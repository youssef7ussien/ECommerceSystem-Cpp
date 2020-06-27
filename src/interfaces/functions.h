#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include<iostream>
#include "../data/product.h"
using namespace std;

string inputText();

bool validationRegex(string, string);

void initialBox(int, int, int, int, int height=1);

void statusBar(string ,string text="LOGOUT",bool isAdmin=false);

void productBox(int, int, int, const Product &, int);


#endif // FUNCTIONS_H_INCLUDED
