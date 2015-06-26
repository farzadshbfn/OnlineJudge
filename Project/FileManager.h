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

#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "BasicLibraries.h"
#include "JudgeManager.h"

struct Problem {
	std::string _problemName;
};

struct Submission {
	size_t      submissionId;
	std::string submissionAddress;
};


class FileManager {
public:
	FileManager() {}
	
	/**
	 set root folder address where all submissions and test datas are saved
	 @param prefixAddress
	 the root folder address
	 */
	void set_prefix_folder_address(std::string prefixFolderAddress);
	
	
	/**
	 @return root folder that contains submissions and testdatas
	 */
	std::string get_prefix_folder_address() { return _prefixAddress;}
	
	
	/**
	 clears the folder dedicated to judge. fills it with testdata of problem, submission
	 and it's runnable version
	 @param problem
			is needed for problemID to fetch all testdata
	 @param judge
			is needed to copy contents of problen into the folder dedicated for this judge
	 @param submission
			submited code which is about to be tested
	 */
	void prepare_problem_for_judge_to_test_submission
	(Problem problem, Judge* judge, Submission *submission);
private:
	std::string _prefixAddress;
};


#endif /* FILE_MANAGER_H */





