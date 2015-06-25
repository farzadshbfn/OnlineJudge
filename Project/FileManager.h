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

#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "BasicLibraries.h"

class FileManager {
public:
	/**
	 set root folder address where all submissions and test datas are saved
	 @param prefixAddress
			the root folder address
	 */
	void   setPrefixAddress(std::string prefixAddress);
	FileManager() {}
private:
	std::string _prefixAddress;
};


#endif /* FILE_MANAGER_H */