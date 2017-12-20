/*
 * MetaData.cpp
 *
 *  Created on: Dec 11, 2017
 *      Author: ben
 */

#include "MetaData.h"

MetaData::MetaData(const string compressedData) {
	this->compressedData = compressedData;
	// TODO Auto-generated constructor stub

}

string MetaData::makeMetaData(unsigned int blocksize, unsigned int numOfBlocks, unsigned int amountOfPadding, unsigned int uniqueCharacters, char characterSet[]) {
	string stringBuffer = "";

	stringBuffer+=Util::unsignedIntToString(blocksize);
	stringBuffer+=Util::unsignedIntToString(numOfBlocks);
	stringBuffer+=Util::unsignedIntToString(amountOfPadding);
	stringBuffer+=Util::unsignedIntToString(uniqueCharacters);
	for(unsigned int i = 0; i< uniqueCharacters; i++){
		stringBuffer+=characterSet[i];
	}

	return stringBuffer;
}

unsigned int MetaData::getBlocksize() {
	unsigned int retBuffer = 0;
	memcpy(&retBuffer, compressedData.data(), 4);
	return retBuffer;
}

unsigned int MetaData::getNumOfBlocks() {
	unsigned int retBuffer = 0;
	memcpy(&retBuffer, compressedData.data()+4, 4);
	return retBuffer;
}
unsigned int MetaData::getAmountPadding() {
	unsigned int retBuffer = 0;
	memcpy(&retBuffer, compressedData.data()+8, 4);
	return retBuffer;
}
unsigned int MetaData::getAmountUniqueCharacters() {
	unsigned int retBuffer = 0;
	memcpy(&retBuffer, compressedData.data()+12, 4);
	return retBuffer;
}
string MetaData::getCharacterSet() {
	return compressedData.substr(16, getAmountUniqueCharacters());
}

MetaData::~MetaData() {
	// TODO Auto-generated destructor stub
}
