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

void init() {
	OJManager *sharedInstance = OJManager::shared_instance();
	sharedInstance->_fileManager->set_prefix_folder_address(FOLDER_ROOT_FILES);
	sharedInstance->_judgeManager->set_prefix_folder_address(FOLDER_ROOT_JUDGES);
//	Problem problem;
//	problem._problemName = "1001";
//	Submission* submission = new Submission();
//	submission->submissionId = 1001;
//	sharedInstance->_fileManager->prepare_problem_for_judge_to_test_submission(problem, sharedInstance->_judgeManager->get_available_judge(), submission);
}

int main() {
	init();
	return 0;
}
