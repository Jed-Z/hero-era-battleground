/* *************************
* FileName: ui.h
* Author: Jed Zhang
* Site: https://www.jed123.com/hero-era-battleground-cpp.html
* Date: 2018.6.7
* Description: User interface declaration.
**************************/
#ifndef _UI_H_
#define _UI_H_
#include <iostream>
using namespace std;

// Print 100 "=" as a split line.
// This function is used for testing. Not used in game!
void split_line();

// Print game introduction.
void print_introduction();

// Print game help.
void print_help(int lang = 0);

// Print game exit information.
void print_bye();

#endif
