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
public:
	/**
	 subclasses must provide compile command related to submited code
	 */
	virtual std::string generate_compile_command(std::string submitAddress) = 0;
	
	/**
	 executes code
	 */
	virtual std::string generate_run_command(std::string submitAddress) = 0;
	
	/**
	 get excutable file address. (it's necessary to check if compiler did the job!)
	 */
	virtual std::string get_executable_file_address(std::string submitAddress) = 0;
	/**
	 get fileType
	 */
	virtual std::string get_file_type() = 0;
	
	/**
	 get executable file name.
	 */
	virtual std::string get_excute_command_localized() = 0;
	
	virtual char** get_argv(std::string submitAddress) = 0;
};

// MARK: Compilers

class CompilerGpp: public ICompiler {
public:
	std::string generate_compile_command(std::string submitAddress) override;
	std::string generate_run_command(std::string submitAddress) override;
	std::string get_executable_file_address(std::string submitAddress) override;
	std::string get_file_type() override;
	std::string get_excute_command_localized() override;
	char** get_argv(std::string submitAddress) override;
};

class CompilerGcc: public ICompiler {
public:
	std::string generate_compile_command(std::string submitAddress) override;
	std::string generate_run_command(std::string submitAddress) override;
	std::string get_executable_file_address(std::string submitAddress) override;
	std::string get_file_type() override;
	std::string get_excute_command_localized() override;
	char** get_argv(std::string submitAddress) override;
};

class CompilerJava: public ICompiler {
public:
	std::string generate_compile_command(std::string submitAddress) override;
	std::string generate_run_command(std::string submitAddress) override;
	std::string get_executable_file_address(std::string submitAddress) override;
	std::string get_file_type() override;
	std::string get_excute_command_localized() override;
	char** get_argv(std::string submitAddress) override;
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
