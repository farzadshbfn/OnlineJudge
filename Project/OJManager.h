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

#ifndef OJ_OJManager_h
#define OJ_OJManager_h

#include "FileManager.h"
#include "JudgeManager.h"

class OJManager {
public:
	
	FileManager*  _fileManager;
	JudgeManager* _judgeManager;
	
	/**
	 @return object shared through all the application
	 */
	static OJManager* shared_instance() {
		static OJManager *sharedInstance = NULL;
		if (sharedInstance == NULL)
			sharedInstance = new OJManager();
		return sharedInstance;
	}
	
private:
	
	OJManager() {
		_fileManager = new FileManager();
		_judgeManager = new JudgeManager();
	}
};

#endif
