/*
 * MetaData.h
 *
 *  Created on: Dec 11, 2017
 *      Author: ben
 */

#include <string.h>
#include <stdio.h>
#include <string>
#include <iostream>

#include "Util.h"

#ifndef MODEL_METADATA_H_
#define MODEL_METADATA_H_

using namespace std;

class MetaData {
public:
	MetaData(const string);
	virtual ~MetaData();
	static string makeMetaData(unsigned int blockSize, unsigned int numOfBlocks, unsigned int amountOfPadding, unsigned int uniqueCharacters, char characterSet[]);
	unsigned int getBlocksize();
	unsigned int getNumOfBlocks();
	unsigned int getAmountPadding();
	unsigned int getAmountUniqueCharacters();
	string getCharacterSet();
private:
	string compressedData;
};


#endif /* MODEL_METADATA_H_ */
