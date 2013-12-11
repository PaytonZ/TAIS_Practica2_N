/*
 * SplitString.h
 *
 *  Created on: 17/10/2012
 *      Author: alberto
 */

#ifndef SPLITSTRING_H_
#define SPLITSTRING_H_

#include <string>

using namespace std;

string* split(string str, string delim, int& outSize);
string* split(string str, char delim, int& outSize);


#endif /* SPLITSTRING_H_ */
