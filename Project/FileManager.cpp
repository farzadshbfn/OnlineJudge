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
void FileManager::move_testdata_submission_to_judgeFolder
(Problem problem, Judge* judge, Submission& submission) {
	// remove all fils in judge folder
	terminal::system("rm " + judge->get_folder_address() + "/*.*");
	
	// move all testdata into judge folder
	std::string moveTestDataCmd = "find " + _prefixAddress;
	moveTestDataCmd += "/Testdata/" + problem.problemName + "_*.*";
	moveTestDataCmd += " -exec cp -t ";
	moveTestDataCmd += judge->get_folder_address();
	moveTestDataCmd += "/ {} \\+";
	terminal::system(moveTestDataCmd);
	
	// move submission
	std::string moveSubmission = "find " + _prefixAddress;
	moveSubmission += "/Submissions/" + int_to_string((int)submission.submissionId) + ".*";
	
	// before moving submission completely, catch it's name
	std::string submissionFileAddress = terminal::system(moveSubmission);
	submissionFileAddress = submissionFileAddress.substr(0, int(submissionFileAddress.size())-1);
	size_t pos = submissionFileAddress.find_last_of('/');
	std::string submissionName = submissionFileAddress.substr(pos+1);
	
	moveSubmission += " -exec cp -t ";
	moveSubmission += judge->get_folder_address();
	moveSubmission += "/ {} \\+";
	std::string sub = terminal::system(moveSubmission);
	submission.submissionAddress = judge->get_folder_address() + "/" + submissionName;
}

void FileManager::clear_folder(std::string address) {
}

void FileManager::move_inputs(std::string problemName, std::string address) {
	std::string cmd = "find " + address
}

void FileManager::move_outputs(std::string problemName, std::string address) {
}

void FileManager::move_submission(std::string  submission, std::string address) {
}


