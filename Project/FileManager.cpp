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

#include "FileManager.h"
#include "TerminalManager.h"

// MARK: public methods

void FileManager::set_prefix_folder_address(std::string prefixFolderAddress) {
	_prefixAddress = prefixFolderAddress;
}

std::string int_to_string(int number) {
	std::stringstream ss;
	ss << number;
	return ss.str();
}

void FileManager::prepare_problem_for_judge_to_test_submission
(Problem problem, Judge* judge, Submission *submission) {
	terminal::system("rm " + judge->get_folder_address() + "/*.*");
	std::string moveTestDataCmd = "find " + _prefixAddress;
	moveTestDataCmd += "/Testdata/" + problem._problemName + "_*.*";
	moveTestDataCmd += " -exec cp -t ";
	moveTestDataCmd += judge->get_folder_address();
	moveTestDataCmd += "/ {} \\+";
	terminal::system(moveTestDataCmd);
	
	std::string moveSubmission = "find " + _prefixAddress;
	moveSubmission += "/Submissions/" + int_to_string((int)submission->submissionId) + ".*";
	moveSubmission += " -exec cp -t ";
	moveSubmission += judge->get_folder_address();
	moveSubmission += "/ {} \\+";
	std::string sub = terminal::system(moveSubmission);
	std::cerr << sub << std::endl;
}
// MARK: private methods
