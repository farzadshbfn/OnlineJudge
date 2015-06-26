//
//  Compilers.h
//  OJ
//
//  Created by Farzad Sharbafian on 2015-06-26.
//  Copyright (c) 2015 Farzad Sharbafian. All rights reserved.
//

#ifndef OJ_Compilers_h
#define OJ_Compilers_h

#include "BasicLibraries.h"

class ICompiler {
public:
	/**
	 subclasses must provide compile command related to submited code
	 */
	virtual std::string generateCompileCommand(std::string submitAddress) = 0;
	
	/**
	 executes code
	 */
	virtual int         runCompiledCode() = 0;
};

class CompilerGpp: public ICompiler {
	std::string generateCompileCommand(std::string submitAddress) override {
		std::string command;
		return command;
	}
	
	int runCompiledCode() override {
		return 0;
	}
};

class CompileGcc: public ICompiler {
	std::string generateCompileCommand(std::string submitAddress) override {
		std::string command;
		return command;
	}
	
	int runCompiledCode() override {
		return 0;
	}
};

class CompileJava: public ICompiler {
	std::string generateCompileCommand(std::string submitAddress) override {
		std::string command;
		return command;
	}
	
	int runCompiledCode() override {
		return 0;
	}
};

#endif
