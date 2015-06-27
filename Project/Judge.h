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

#ifndef JUDGE_H
#define JUDGE_H

#include "BasicLibraries.h"
#include "Compilers.h"

struct Problem {
	std::string problemName;
	int         memoryLimit;
	float       timeLimit;
};

struct Submission {
	size_t      submissionId;
	std::string submissionAddress;
};


struct Information {
	int totalProblem;
	int accepted;
	bool runtimeError;
	int time;
	int memory;
};

class Judge {
public:
	Judge(std::string username, std::string password);
	
	/**
	 @param folderAddress
			address of folder dedicated to this judge
	 */
	void set_folder_address(std::string folderAddress);
	
	/**
	 @return address of folder dedicated to this judge
	 */
	std::string get_folder_address() { return _folderAddress;}
	
	/**
	 well, it's onlinejudge after all!
	 @param problem
			problem to be judged
	 @param submissoin
			submission to judge problem with
	 @return result of judge
	 */
	std::string judge_problem(Problem problem, Submission submission);
	
	/**
	 determins if this judge is ready to judge a problem or not
	 */
	bool is_busy();
private:
	std::string _username;
	std::string _password;
	
	std::string _folderAddress;
	
	/**
	 the real deal
	 */
	std::string run_test_cases(Problem problem, Submission& submission);
};


#endif /* JUDGE_H */