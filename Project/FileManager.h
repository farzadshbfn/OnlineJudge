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

class FileManager {
public:
	FileManager() {}
	
	/**
	 root folder address where all submissions are saved
	 */
	std::string _submissionsFolder;
	/**
	 root folder address where all testdatas are saved
	 */
	std::string _testdatasFolder;
	
	/**
	 ***: set _submissionsFolder & _testdatasFolder before calling this method
	 clears the folder dedicated to judge. fills it with testdata of problem, submission
	 and it's runnable version
	 @param problem
			is needed for problemID to fetch all testdata
	 @param judge
			is needed to copy contents of problen into the folder dedicated for this judge
	 @param submission
			submited code which is about to be tested
	 */
	void move_testdata_submission_to_judgeFolder
	(Problem problem, Judge* judge, Submission& submission);
	
private:
	void clear_folder   (std::string address);
	void move_inputs    (std::string problemName, std::string address);
	void move_outputs   (std::string problemName, std::string address);
	void move_submission(std::string  submission, std::string address);
};


#endif /* FILE_MANAGER_H */





