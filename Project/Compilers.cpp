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

#include "Compilers.h"

// MARK: CompilerGpp
std::string CompilerGpp::generate_compile_command(std::string submitAddress) {
	std::string result;
	result = "g++ " + submitAddress + " -std=c++11 ";
	result += "-o " + get_executable_file_address(submitAddress);
	return result;
}

std::string CompilerGpp::generate_run_command(std::string submitAddress) {
	return "." + get_executable_file_address(submitAddress);
}

std::string CompilerGpp::get_executable_file_address(std::string submitAddress) {
	size_t pos = submitAddress.find_last_of('/');
	return submitAddress.substr(0, pos) + "/a.out";
}

std::string CompilerGpp::get_file_type() {
	return "cpp";
}

std::string CompilerGpp::get_excute_command_localized() {
	return "./a.out";
}

char** CompilerGpp::get_argv(std::string submitAddress) {
	static char** argv = new char*[1];
	argv[0] = NULL;
	return argv;
}


// MARK: CompilerGcc
std::string CompilerGcc::generate_compile_command(std::string submitAddress) {
	std::string result;
	result = "gcc " + submitAddress + " ";
	result += "-o " + get_executable_file_address(submitAddress);
	return result;
}

std::string CompilerGcc::generate_run_command(std::string submitAddress) {
	return "." + get_executable_file_address(submitAddress);
}

std::string CompilerGcc::get_executable_file_address(std::string submitAddress) {
	size_t pos = submitAddress.find_last_of('/');
	return submitAddress.substr(0, pos) + "/a.out";
}

std::string CompilerGcc::get_file_type() {
	return "c";
}

std::string CompilerGcc::get_excute_command_localized() {
	return "./a.out";
}

char** CompilerGcc::get_argv(std::string submitAddress) {
	static char** argv = new char*[1];
	argv[0] = NULL;
	return argv;
}

// MARK: CompilerJava
std::string CompilerJava::generate_compile_command(std::string submitAddress) {
	std::string result;
	//first it needs to be renamed to Main.java
	size_t pos = submitAddress.find_last_of('/');
	result = "cd " + submitAddress.substr(0, pos) + "; ";
	std::string mainFileAddress = submitAddress.substr(0, pos) + "/Main.java";
	result += "mv " + submitAddress + " " + mainFileAddress + "; ";
	result += "javac Main.java";
	return result;
}

std::string CompilerJava::generate_run_command(std::string submitAddress) {
	return "java " + get_executable_file_address(submitAddress);
}

std::string CompilerJava::get_executable_file_address(std::string submitAddress) {
	size_t pos = submitAddress.find_last_of('/');
	return submitAddress.substr(0, pos) + "/Main";
}

std::string CompilerJava::get_file_type() {
	return "java";
}

std::string CompilerJava::get_excute_command_localized() {
	return "java Main";
}

char** CompilerJava::get_argv(std::string submitAddress) {
	static char** argv = new char*[1];
	std::string exc = this->get_executable_file_address(submitAddress);
	argv[0] = new char[exc.size()];
	std::copy(exc.begin(), exc.end(), argv[0]);
	argv[1] = NULL;
	return argv;
}

// MARK: CompilerManager

CompilerManager* CompilerManager::shared_instance() {
	CompilerManager *sharedInstance = NULL;
	if (sharedInstance == NULL)
		sharedInstance = new CompilerManager();
	return sharedInstance;
}

CompilerManager::CompilerManager() {
	compilers.push_back(new CompilerGpp());
	compilers.push_back(new CompilerGcc());
	compilers.push_back(new CompilerJava());
}

ICompiler* CompilerManager::get_suitable_compiler(std::string submitAddress) {
	size_t pos = submitAddress.find_last_of('.');
	std::string fileType = submitAddress.substr(pos+1);
	
	for (ICompiler *compiler: compilers)
		if (compiler->get_file_type() == fileType)
			return compiler;
	
	return NULL;
}





