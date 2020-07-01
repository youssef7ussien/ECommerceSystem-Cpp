#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "../data/product.h"

/**
 *  inputText() : This function is used for program entries
 *   and it returns the value entered
 */
string inputText();

/**
 *  validationRegex() : This function is used to check entries so that the program works without any problems,
 *    the verification process is done through the regex.
 */
bool validationRegex(const string&, const string&);

void initialBox(int, int, int, int, int height=1);

void statusBar(const string& ,const string& text="LOGOUT",bool isAdmin=false);

void productBox(int, int, int, const Product &, int);

bool logOutDialog(const string&);


#endif // FUNCTIONS_H_INCLUDED
