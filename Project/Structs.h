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
#include <sys/time.h>

struct Result {
	bool runtimeError;
	int timeUsed;   // in ms
	int memoryUsed; // in KB
	std::string compileResult;
	int totalTestcases;
	int acceptedTestcases;
};

struct Problem {
	std::string problemName;
	int         memoryLimit;
	int         timeLimit;
};

// TODO: change it later with DIR from dirent.h
struct Submission {
	size_t      submissionId;
	std::string fileAddress;
	std::string fileName;
};


#endif
