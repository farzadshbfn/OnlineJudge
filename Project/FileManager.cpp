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
#include "UsefullFunctions.h"

// MARK: public methods
void FileManager::prepare_judge_folder(Submission& submission, Problem& problem, Judge* judge) {
	//TODO: handle following 2 lines with DIR from <dirent.h>
	std::string findSb = "cd " + _submissionsFolder + ";find " + submission.submissionId + "*";
	submission.submissionId = terminal::system(findSb);
	submission.fileAddress = judge->get_judgeFolder() + "/" + submission.submissionId;
	std::string command = clear_folder_cmd(judge->get_judgeFolder());
	command += move_inputs_cmd(problem.problemName, judge->get_inputsFolder());
	command += move_outputs_cmd(problem.problemName, judge->get_outputsFolder());
	command += move_submission_cmd(_submissionsFolder + "/" + submission.submissionId, judge->get_judgeFolder());
	terminal::system(command);
}

std::string FileManager::clear_folder_cmd(std::string address) {
	return "cd " + address +"; find . -type f -exec rm {} \\+;";
}

std::string FileManager::move_inputs_cmd(std::string problemName, std::string address) {
	return "find " + _testdatasFolder + "/" + problemName + "_*.in -exec cp -t " + address + " {} \\+;";
}

std::string FileManager::move_outputs_cmd(std::string problemName, std::string address) {
	return "find " + _testdatasFolder + "/" + problemName + "_*.out -exec cp -t " + address + " {} \\+;";
}

std::string FileManager::move_submission_cmd(std::string submission, std::string address) {
	return "cp " + submission + " " + address + ";";
}


