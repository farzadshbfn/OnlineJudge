//
//  UsefullFunctions.h
//  OJ
//
//  Created by Farzad Sharbafian on 2015-06-28.
//  Copyright (c) 2015 Farzad Sharbafian. All rights reserved.
//

#ifndef OJ_UsefullFunctions_h
#define OJ_UsefullFunctions_h

#include "BasicLibraries.h"
#include <dirent.h>
#include <fstream>
#include <sys/stat.h>

template <class T>
std::string to_string(T data) {
	std::stringstream ss;
	ss << data;
	return ss.str();
}

static std::vector<std::string> get_files_in_folder(std::string folder) {
	std::vector<std::string> ret;
	DIR *dir = opendir(folder.c_str());
	
	struct dirent *entry = readdir(dir);
	
	while (entry != NULL) {
		if (entry->d_type != DT_DIR)
			ret.push_back(folder + "/" + std::string(entry->d_name));
		
		entry = readdir(dir);
	}
	closedir(dir);
	return ret;
}

static std::string get_content_of_file(std::string fileAddress) {
	std::string content;
	std::fstream fs(fileAddress);
	if (fs.is_open()) {
		std::string line;
		while (std::getline(fs, line, '\n'))
			content += line;
		fs.close();
	}
	return content;
}

static bool file_exists(std::string filename) {
	struct stat fileInfo;
	return stat(filename.c_str(), &fileInfo) == 0;
}

#endif
