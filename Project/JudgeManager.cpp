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

void JudgeManager::set_judgesTempFolders(std::string judgesTempFolders) {
	_judgesTempFolders = judgesTempFolders;
	load_judges();
}

Judge* JudgeManager::get_a_judge() {
	return _judges[0];
}


// MARK: private methods

void JudgeManager::load_judges() {
	_judges.clear();
	std::string judge1Username = "judge1";
	Judge *judge = new Judge(judge1Username);
	judge->_folderAddress = _judgesTempFolders + "/" + judge1Username;
	_judges.push_back(judge);
}