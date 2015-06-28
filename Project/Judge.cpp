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

std::string Judge::run_test_cases() {
//	std::stringstream inputs_stream
//	(terminal::system
//	 ("cd " +  _folderAddress + "; " + "find " + problem.problemName + "*.in"));
//	
//	std::stringstream outputs_stream
//	(terminal::system
//	 ("cd " +  _folderAddress + "; " + "find " + problem.problemName + "*.out"));
//	
//	std::vector<std::string> inputs;
//	std::vector<std::string> outputs;
//	std::vector<std::string> userOutputs;
//	std::string line;
//	while (inputs_stream >> line && line != "")
//		inputs.push_back(line);
//	while (outputs_stream >> line && line != "")
//		outputs.push_back(line);
//	
//	if (inputs.size())
//		std::sort(inputs.begin(), inputs.end());
//	if (outputs.size())
//		std::sort(outputs.begin(), outputs.end());
//	
//	
//	ICompiler *compiler =
//	OJManager::shared_instance()->
//	_compilerManager->
//	get_suitable_compiler(submission.submissionAddress);
//	
//	// TODO: check later for problem with no input
//	for (int i = 0; i < inputs.size(); i++) {
//		// TODO: check for runtime
//		std::string testCommand = "cd " + this->get_folder_address() + "; ";
//		testCommand += "sudo -u " + this->_username + " ";
//		testCommand += compiler->get_excute_command_localized();
//		testCommand += " <" + inputs[i];
//		std::stringstream ss;
//		ss << i;
//		testCommand += " >u_" + ss.str() + ".out";
//		terminal::system(testCommand);
//	}
//	int accepted = 0;
//	for (int i = 0; i < outputs.size(); i++) {
//		std::string compareCommand = "cd " + this->get_folder_address() + "; ";
//		compareCommand += "diff " + outputs[i] + " ";
//		std::stringstream ss;
//		ss << i;
//		compareCommand += "u_" + ss.str() + ".out";
//		std::string compResult = terminal::system(compareCommand);
//		compResult = compResult.substr(0, int(compResult.size())-1);
//		if (compResult == "")
//			accepted++;
//	}
//	std::string result;
//	if (accepted == outputs.size())
//		result = "Accepted";
//	else {
//		result = "WrongAnswer ";
//		std::stringstream ss;
//		ss << accepted << "/" << outputs.size();
//		result += ss.str();
//	}
//	return result;
	return "";
}

void Judge::generate_outputs() {
}

std::string Judge::judge_problem(Problem problem, Submission submission) {
	_result.reset();
	_submission = submission;
	_problem = problem;

	ICompiler *compiler =
	CompilerManager::shared_instance()->get_suitable_compiler(submission.fileAddress);
	std::string cmd = compiler->pre_compile_command() + compiler->compile_command();
	terminal::system(cmd);
	_result.compileResult = get_content_of_file(get_judgeFolder() + "/" + compiler->get_compileFile());
	// check compileError
	if (file_exists(compiler->executable_address())) {
		_result.resultFlag |= RESULT_COMPILE_ERROR;
	}
	
	generate_outputs();
	
	return "";
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





