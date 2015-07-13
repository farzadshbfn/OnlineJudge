/*
 Copyright (c) 2015, Farzad Sharbafian <farzad.shbfn@gmail.com>
 
 Permission to use, copy, modify, and/or distribute this software for any
 purpose with or without fee is hereby granted, provided that the above
 copyright notice and this permission notice appear in all copies.
 
 THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include "Judge.h"
#include "OJManager.h"

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/resource.h>

sig_atomic_t pid;
void Judge::set_time_limit() {
	rlimit timeL;
	timeL.rlim_cur = _problem.timeLimit;
	timeL.rlim_max = _problem.timeLimit;
	setrlimit(RLIMIT_CPU, &timeL);
}

void Judge::set_memory_limit() {
	rlimit memL;
	memL.rlim_cur = _problem.memoryLimit;
	memL.rlim_max = _problem.memoryLimit;
	setrlimit(RLIMIT_AS, &memL);
}

void Judge::set_process_limit() {
	rlimit procL;
	procL.rlim_cur = 1;
	procL.rlim_max = 1;
	setrlimit(RLIMIT_NPROC, &procL);
}

void setup_input_output(std::string input, std::string output) {
	int in, out;
	in = open(input.c_str(), O_RDONLY);
	out = open(output.c_str(), O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
	
	dup2(in, 0);
	dup2(out, 1);
	close(in);
	close(out);
}

void handler(int sig) {
	if (sig == SIGXCPU) {
		// TODO: get thread info before killing it
//		kill(pid, SIGKILL); // kill zombies
	}
}

void setup_hanlder() {
	struct sigaction sa;
	memset(&sa, 0, sizeof sa);
	sa.sa_handler = &handler;
	sigaction(SIGXCPU, &sa, NULL);
}

void Judge::execute_single(std::string input, std::string output) {
	pid = fork();
	setup_hanlder();
	if (pid == 0) {
		set_time_limit();
		set_memory_limit();
		set_process_limit();
		setup_input_output(input, output);
		execvp(_compiler->executable_address().c_str(), _compiler->exec_argv());
	}
	else {
		int res;
		waitpid(pid, &res, 0);
		std::cerr << res << std::endl;
		switch (res) {
			case 0: break;
			case 9:
			case 24:
				_result.resultFlag |= RESULT_TIME_LIMIT_EXCEEDED;
				break;
			case 134:
				_result.resultFlag |= RESULT_MEMORY_LIMIT_EXCEEDED;
				break;
			default:
				_result.resultFlag |= RESULT_RUNTIME_ERROR;
				break;
		}
		if (_result.resultFlag) return;
	}
}

void Judge::execute_all() {
	auto ins = inputs();
	auto outs = outputs();
	for (int i = 0; i < outs.size(); i++) {
		std::string in = (i < ins.size()? ins[i] : "");
		std::string out = result_file(outs[i]);
		execute_single(in, out);
		if (_result.resultFlag) return;
	}
}

void Judge::compare_outputs() {
	auto outs = outputs();
	auto ress = results();
	if (outs.size() != ress.size()) {
		_result.resultFlag |= RESULT_OUTPUT_FORMAT_ERROR;
		return;
	}
	for (int i = 0; i < outs.size(); i++)
		terminal::system("diff " + outs[i] + " " + ress[i] + " >" + diff_file(outs[i]));
	
	auto difs = diffs();
	for (int i = 0; i < difs.size() && !_result.resultFlag; i++) {
		std::string content = get_content_of_file(difs[i]);
		if (content.size() != 0)
			_result.resultFlag |= RESULT_WRONG_ANSWER;
	}
}

Result Judge::judge_problem(Problem problem, Submission submission) {
	_result.reset();
	_submission = submission;
	_problem = problem;

	_compiler = CompilerManager::shared_instance()->get_suitable_compiler(submission.fileAddress);
	std::string cmd = _compiler->pre_compile_command() + _compiler->compile_command();
	terminal::system(cmd);
	_result.compileResult = get_content_of_file(get_judgeFolder() + "/" + _compiler->get_compileFile());
	
	if (!file_exists(_compiler->executable_address())) {
		_result.resultFlag |= RESULT_COMPILE_ERROR;
		return _result;
	}
	
	execute_all();
	if (_result.resultFlag) return _result;
	
	compare_outputs();
	if (_result.resultFlag) return _result;
	
	_result.resultFlag |= _result.acceptedTestcases != _result.totalTestcases;
	return _result;
}

std::vector<std::string> Judge::inputs() {
	return get_files_in_folder(get_inputsFolder());
}

std::vector<std::string> Judge::outputs() {
	return get_files_in_folder(get_outputsFolder());
}

std::vector<std::string> Judge::results() {
	return get_files_in_folder(get_resultsFolder());
}

std::vector<std::string> Judge::diffs() {
	return get_files_in_folder(get_diffsFolder());
}

std::string Judge::result_file(std::string output) {
	return get_resultsFolder() + "/" + output.substr(output.find_last_of("/")+1);
}

std::string Judge::diff_file  (std::string output) {
	return get_diffsFolder() + "/" + output.substr(output.find_last_of("/")+1);
}





