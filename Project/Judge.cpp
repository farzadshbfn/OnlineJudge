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


void set_time_limit() {
}

void set_memory_limit() {
}


void Judge::execute_single(std::string input, std::string output) {
	
}

void Judge::execute_all() {
	auto ins = inputs();
	auto outs = outputs();
	for (int i = 0; i < outs.size(); i++) {
		std::string in = (i < ins.size()? ins[i] : "");
		std::string out = result_file(outs[i]);
		execute_single(in, out);
		if (_result.resultFlag)
			return;
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
	
	if (_result.resultFlag)
		return _result;
	
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
	return get_resultsFolder() + output.substr(output.find_last_of("/")+1);
}

std::string Judge::diff_file  (std::string output) {
	return get_diffsFolder() + output.substr(output.find_last_of("/")+1);
}





