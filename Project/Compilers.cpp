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


// MARK: ICompiler

std::string ICompiler::pre_compile_command() {
	return "";
}

void ICompiler::set_fileAddress(std::string fileAddress) {
	_fileAddress = fileAddress;
	size_t pos = fileAddress.find_last_of('/');
	_folderAddress = fileAddress.substr(0, pos);
	_fileName = fileAddress.substr(pos+1);
}

std::string ICompiler::executable_address() {
	return _folderAddress + this->executable_file();
}

char** ICompiler::exec_argv() {
	return _argv;
}

// MARK: CompilerGpp
std::string CompilerGpp::compile_command() {
	return "cd " + _folderAddress + "; g++ " + _fileName + " -std=c++11";
}

std::string CompilerGpp::executable_file() {
	return "a.out";
}

std::string CompilerGpp::code_extension() {
	return "cpp";
}


// MARK: CompilerGcc
std::string CompilerGcc::compile_command() {
	return "cd " + _folderAddress + "; gcc " + _fileName + " -std=c++11";
}

std::string CompilerGcc::executable_file() {
	return "a.out";
}

std::string CompilerGcc::code_extension() {
	return "c";
}

// MARK: CompilerJava
std::string CompilerJava::pre_compile_command() {
	return "mv " + _fileAddress + " " + _folderAddress + "/" + executable_file() + ".java";
}

std::string CompilerJava::compile_command() {
	return "cd " + _folderAddress + ";javac " + executable_file() + ".java";
}

void CompilerJava::set_fileAddress(std::string fileAddress) {
	ICompiler::set_fileAddress(fileAddress);
	for (int i = 0;; i++)
		if (_argv[i])
			delete _argv[i];
		else
			break;
	delete[] _argv;
	_argv = new char*[2];
	_argv[1] = NULL;
	std::string temp = executable_address();
	_argv[0] = new char[temp.size()];
	for (int i = 0; i < temp.size(); i++)
		_argv[0][i] = temp[i];
}

std::string CompilerJava::executable_file() {
	return "Main";
}


std::string CompilerJava::code_extension() {
	return "java";
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
		if (compiler->compile_command() == fileType)
			return compiler;
	
	return NULL;
}





