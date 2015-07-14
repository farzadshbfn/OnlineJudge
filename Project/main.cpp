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
	
	Result result = judge->judge_problem(problem, submission);
	std::cerr << std::hex << result.resultFlag << std::endl;
}

void init() {
	OJManager *sharedInstance = OJManager::shared_instance();
	sharedInstance->_fileManager->_submissionsFolder = FOLDER_ROOT_SUBMISSIONS;
	sharedInstance->_fileManager->_testdatasFolder   = FOLDER_ROOT_TESTDATAS;
	sharedInstance->_judgeManager->set_judgesTempFolders(FOLDER_ROOT_JUDGESTEMP);
}

std::map<int, std::string> command_names() {
	std::map<int, std::string> mp;
	mp[0] = "ACCEPTED";
	mp[1] = "COMPILE_ERROR";
	mp[2] = "TIME_LIMIT_EXCEEDED";
	mp[4] = "MEMORY_LIMIT_EXCEEDED";
	mp[8] = "RUNTIME_ERROR";
	mp[16] = "PRESENTATION_ERROR";
	mp[32] = "WRONG_ANSWER";
	mp[64] = "OUTPUT_FORMAT_ERROR";
	return mp;
}

void cmd() {
	std::string line;
	auto commandNames = command_names();
	while (std::getline(std::cin, line)) {
		std::stringstream ss;
		ss << line;
		ss >> line;
		if (line == "submit") {
			int timeLimit, memLimit;
			std::string probName, subId;
			ss >> subId >> probName >> timeLimit >> memLimit;
			Submission sub;
			sub.submissionId = subId;
			Problem prob;
			prob.problemName = probName;
			prob.timeLimit = timeLimit;
			prob.memoryLimit = memLimit;
			
			Judge *judge = OJManager::shared_instance()->_judgeManager->get_a_judge();
			Result res = judge->judge_problem(prob, sub);
			std::cout << commandNames[res.resultFlag] << std::endl;
		}
		else if (line == "exit")
			return;
	}
}

int main() {
	init();
//	test();
	cmd();
	return 0;
}
