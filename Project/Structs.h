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

#ifndef OJ_Structs_h
#define OJ_Structs_h

#include "BasicLibraries.h"

#define RESULT_ACCEPTED              0
#define RESULT_WRONG_ANSWER          1
#define RESULT_COMPILE_ERROR         2
#define RESULT_RUNTIME_ERROR         4
#define RESULT_TIME_LIMIT_EXCEEDED   8
#define RESULT_MEMORY_LIMIT_EXCEEDED 16

struct Result {
	int resultFlag;
	int timeUsed;   // in ms
	int memoryUsed; // in KB
	std::string compileResult;
	int totalTestcases;
	int acceptedTestcases;
	
	void reset() {
		resultFlag = 0;
		timeUsed = 0;
		memoryUsed = 0;
		compileResult = "";
		totalTestcases = 0;
		acceptedTestcases = 0;
	}
};

struct Problem {
	std::string problemName;
	int         memoryLimit;
	int         timeLimit;
};

// TODO: change it later with DIR from dirent.h
struct Submission {
	std::string submissionId;
	std::string fileAddress;
};


#endif
