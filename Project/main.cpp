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

#include <iostream>

//#define MAC_OS

#include "Defines.h"
#include "BasicLibraries.h"
#include "OJManager.h"

void test() {
	OJManager *manager = OJManager::shared_instance();
	Problem problem;
	problem.problemName = "100";
	problem.timeLimit = 5;
	problem.memoryLimit = 100000000;
	
	Submission submission;
	submission.submissionId = to_string(1002);
	
	Judge* judge = manager->_judgeManager->get_a_judge();
	
	manager->_fileManager->prepare_judge_folder(submission, problem, judge);
	
	Result result = judge->judge_problem(problem, submission);
	std::cerr << std::hex << result.resultFlag << std::endl;
}

void init() {
	OJManager *sharedInstance = OJManager::shared_instance();
	sharedInstance->_fileManager->_submissionsFolder = FOLDER_ROOT_SUBMISSIONS;
	sharedInstance->_fileManager->_testdatasFolder   = FOLDER_ROOT_TESTDATAS;
	sharedInstance->_judgeManager->set_judgesTempFolders(FOLDER_ROOT_JUDGESTEMP);
}

int main() {
	init();
	test();
	return 0;
}
