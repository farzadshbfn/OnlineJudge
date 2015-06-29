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
#include "Structs.h"


class Judge {
public:
	Judge(std::string username) { _username = username;}
	
	/**
	 holds address to judge temp folder
	 */
	std::string _folderAddress;
	
	/**
	 set _folderAddress before calling below functions
	*/
	std::string get_judgeFolder()   { return _folderAddress;}
	std::string get_inputsFolder()  { return _folderAddress + "/inputs";}
	std::string get_outputsFolder() { return _folderAddress + "/outputs";}
	std::string get_resultsFolder() { return _folderAddress + "/results";}
	std::string get_diffsFolder()   { return _folderAddress + "/diffs";}
	/**
	 well, it's onlinejudge after all!
	 @param problem
			problem to be judged
	 @param submissoin
			submission to judge problem with
	 @return result of judge
	 */
	Result judge_problem(Problem problem, Submission submission);
private:
	std::string _username;
	Submission  _submission;
	Problem     _problem;
	ICompiler*  _compiler;
	
	Result _result;
	
	void execute_single(std::string input, std::string output);
	void execute_all();
	std::string run_test_cases();
	
	std::vector<std::string> inputs();
	std::vector<std::string> outputs();
	std::vector<std::string> results();
	std::vector<std::string> diffs();
	
	std::string result_file(std::string output);
	std::string diff_file  (std::string output);
};


#endif /* JUDGE_H */