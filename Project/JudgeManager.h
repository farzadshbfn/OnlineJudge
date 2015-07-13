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


#ifndef __OJ__JudgeManager__
#define __OJ__JudgeManager__

#include "BasicLibraries.h"
#include "Judge.h"

class JudgeManager {
public:
	JudgeManager();
	/**
	 set root folder address where all submissions and test datas are saved
	 @param judgesTempFolders
	 the root folder address
	 */
	void set_judgesTempFolders(std::string judgesTempFolders);
	/**
	 @return root folder that contains judges folder
	 */
	std::string get_judgesTempFolders() { return _judgesTempFolders;}
	
	Judge* get_a_judge();
private:
	std::string _judgesTempFolders;
	std::vector<Judge*> _judges;
	
	/**
	 load judges
	 */
	void load_judges();
};

#endif /* defined(__OJ__JudgeManager__) */
