/*
 * Util.h
 *
 *  Created on: Nov 16, 2017
 *      Author: ben
 */

#include <string>
#include <fstream>
#include <streambuf>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <mutex>
#include <cmath>

#ifndef MODEL_UTIL_H_
#define MODEL_UTIL_H_

using namespace std;

class Util {
public:
	static mutex mtx;
	Util();
	virtual ~Util();
	static int countOccurences(string&, string);
	static string readFile(string);
	static void writeFile(string, string&);
	static void toLower(string&);
	static unsigned long hash(string);
	static int isInCharVector(vector<char>&, char);
	static string unsignedLongToString(unsigned long);
	static string unsignedIntToString(unsigned int);
	static string decompressBlock(string);
	static string deHash(unsigned long, const char*, int, int);
private:

};


#endif /* MODEL_UTIL_H_ */
