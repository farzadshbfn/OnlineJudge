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

Judge::Judge(std::string username, std::string password) {
	_username = username;
	_password = password;
}

void Judge::set_folder_address(std::string folderAddress) {
	_folderAddress = folderAddress;
}

bool Judge::is_busy() {
	return 0;
}

std::string run_test_cases(ICompiler* compiler, Problem problem, Submission& submission) {
	return "";
}

std::string Judge::judge_problem(Problem problem, Submission submission) {
	std::string result;
	OJManager* sharedInstance = OJManager::shared_instance();
	sharedInstance->_fileManager->prepare_problem_for_judge_to_test_submission(problem, this, submission);
	ICompiler* compiler = sharedInstance->_compilerManager->get_suitable_compiler(submission.submissionAddress);
//	std::cerr << compiler->generate_compile_command(submission.submissionAddress) << std::endl;
//	std::cerr << compiler->generate_run_command(submission.submissionAddress) << std::endl;
	std::string compileResult = terminal::system(compiler->generate_compile_command(submission.submissionAddress));
	
	// check if file exists
	std::string fileExistCommand = "test -f " + compiler->get_executable_file_address(submission.submissionAddress) + "; echo $?";
	std::string checkResult = terminal::system(fileExistCommand);
	checkResult = checkResult.substr(0, 1);
	
	if (checkResult == "0") // exists
		return run_test_cases(compiler, problem, submission);
	
	return result;
}







