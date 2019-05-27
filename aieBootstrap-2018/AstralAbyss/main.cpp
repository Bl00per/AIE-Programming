// Author: Garreth Cheffirs
// 2014 - Introduction to C++ Assignment 1
// Modified 2017 - Sam Cartwright
// Academy of Interactive Entertainment
// This code is provided by AIE for the purposes of completing in-class tutorials
// Excessive use of this code in assessments, or its use without the appropriate 
// attribution will be treated as plagiarism.

#include "AstralAbyssApp.h"
#include "defines.h"

int main() {
	
	auto app = new AstralAbyssApp();
	app->run("AIE", SCREEN_WIDTH, SCREEN_HEIGHT, false);
	delete app;

	return 0;
}