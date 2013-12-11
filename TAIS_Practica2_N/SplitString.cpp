/*
* SplitString.cpp
*
*  Created on: 17/10/2012
*      Author: alberto
*/

#include "SplitString.h"

int charCount(string str, string delim)
{
	int size = 0, temp = 0, pos = 0;
	while ( (temp = str.find(delim, pos) ) > -1)
	{
		pos = 1 + temp + delim.length(); size++;
	}
	return size + 1;
}

string* split(string str, string delim, int& outSize)
{ /* TODO: free this memory when finished!!! */
	outSize = charCount(str, delim);
	if (outSize == 0)
		return NULL;
	string* out = new string[outSize];
	for (int index = 0, start = 0, find = 0; index < outSize; index++)
	{
		find = str.find(delim, start);
		if (find < 0 || find < start)
		{
			out[index] = str.substr(start);
			break;
		}
		else
			out[index] = str.substr(start, find - start);
		start = find + delim.length();
	}
	return out;
} /* delete [] varName */

string* split(string str, char delim, int& outSize)
{
	return split(str, string(1, delim), outSize);
}




