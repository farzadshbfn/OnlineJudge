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

#ifndef OJ_Compilers_h
#define OJ_Compilers_h

#include "BasicLibraries.h"
#include "TerminalManager.h"
#include "Judge.h"

class ICompiler {
protected:
	ICompiler();
	std::string _fileAddress;
	std::string _folderAddress;
	std::string _fileName;
	char**      _argv;
public:
	virtual std::string pre_compile_command();
	virtual std::string compile_command() = 0;
	virtual std::string executable_address();
	virtual std::string executable_file() = 0;
	virtual char**      exec_argv();
	virtual std::string code_extension() = 0;
	
	/**
	 call this method before calling others
	 */
	virtual void set_fileAddress(std::string fileAddress);
	std::string get_compileFile() { return "compileResult.txt";}
};

// MARK: Compilers

class CompilerGpp: public ICompiler {
public:
	CompilerGpp(): ICompiler() {}
	
	std::string compile_command() override;
	std::string executable_file() override;
	std::string code_extension() override;
};

class CompilerGcc: public ICompiler {
public:
	CompilerGcc(): ICompiler() {}
	
	std::string compile_command() override;
	std::string executable_file() override;
	std::string code_extension() override;
};

class CompilerJava: public ICompiler {
public:
	CompilerJava(): ICompiler() {}
	
	std::string pre_compile_command() override;
	std::string compile_command() override;
	std::string executable_file() override;
	std::string code_extension() override;
	void set_fileAddress(std::string fileAddress) override;
};


// MARK: Compiler Manager

class CompilerManager {
public:
	/**
	 @return shared object through all the app
	 */
	static CompilerManager* shared_instance();
	
	/**
	 searchs all compilers availble in system with fileType. if they match, returns
	 a compiler that can compile submited code
	 @return suitable compiler
	 */
	ICompiler* get_suitable_compiler(std::string submitAddress);
private:
	/**
	 holds all compilers defined
	 */
	std::vector<ICompiler*> compilers;
	CompilerManager();
};

#endif
