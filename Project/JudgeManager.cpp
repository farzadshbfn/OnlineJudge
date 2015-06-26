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

#include "JudgeManager.h"
#include <fstream>
#include "Defines.h"
#include "Compilers.h"

// MARK: public methods

JudgeManager::JudgeManager() {}

void JudgeManager::set_prefix_folder_address(std::string prefixFolderAddress) {
	_prefixFolderAddress = prefixFolderAddress;
	load_judges();
}

Judge* JudgeManager::get_available_judge() {
	return _judges[0];
}


// MARK: private methods

void JudgeManager::load_judges() {
	_judges.clear();
	
	// address to where judge infos are saved
	std::string fileAddress = FOLDER_ROOT_PROJECT;
	fileAddress += "/Resources/JudgesInfo.txt";
	
	// open the file, and read from it
	std::ifstream fs(fileAddress.c_str());
	if (fs.is_open()) {
		std::string line;
		while (std::getline(fs, line, '\n')) {
			size_t pos = line.find(':');
			std::string username = line.substr(0, pos);
			std::string password = line.substr(pos+1);
			_judges.push_back(new Judge(username, password));
			_judges.back()->set_folder_address(_prefixFolderAddress + "/" + username);
		}
		fs.close();
	}

}