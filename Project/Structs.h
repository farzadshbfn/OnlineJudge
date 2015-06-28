//
//  Structs.h
//  OJ
//
//  Created by Farzad Sharbafian on 2015-06-27.
//  Copyright (c) 2015 Farzad Sharbafian. All rights reserved.
//

#ifndef OJ_Structs_h
#define OJ_Structs_h

#include "BasicLibraries.h"

#define RESULT_ACCEPTED              0
#define RESULT_COMPILE_ERROR         1
#define RESULT_RUNTIME_ERROR         2
#define RESULT_TIME_LIMIT_EXCEEDED   4
#define RESULT_MEMORY_LIMIT_EXCEEDED 8

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
		totalTestcases = 1; // just to ignore divide by zero
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
