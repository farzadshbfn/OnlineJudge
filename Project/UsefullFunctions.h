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

template <class T>
std::string to_string(T data) {
	std::stringstream ss;
	ss << data;
	return ss.str();
}

#endif
