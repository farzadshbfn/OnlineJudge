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
#include <fstream>

std::string Judge::run_test_cases(Problem problem, Submission& submission) {
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


std::string Judge::judge_problem(Problem problem, Submission submission) {
	_submission = submission;
	_problem = problem;
//	OJManager* sharedInstance = OJManager::shared_instance();
//	sharedInstance->_fileManager->prepare_problem_for_judge_to_test_submission(problem, this, submission);
//	ICompiler* compiler = sharedInstance->_compilerManager->get_suitable_compiler(submission.submissionAddress);
//	std::string compResAdd = this->get_folder_address() + "/compileResult.txt";
//	terminal::system(compiler->generate_compile_command(submission.submissionAddress) + " 2>" + compResAdd);
//	// check if file exists
//	std::string fileExistCommand = "test -f " + compiler->get_executable_file_address(submission.submissionAddress) + "; echo $?";
//	std::string checkResult = terminal::system(fileExistCommand);
//	checkResult = checkResult.substr(0, 1);
//	
//	if (checkResult == "0") // exists
//		return run_test_cases(problem, submission);
//	
//	std::string compileResult = "CompileError\n";
//	std::fstream fs(this->get_folder_address() + "/compileResult.txt");
//	if (fs.is_open()) {
//		std::string line;
//		while (std::getline(fs, line, '\n'))
//			compileResult += line;
//		fs.close();
//	}
//	return compileResult;
	return "";
}







