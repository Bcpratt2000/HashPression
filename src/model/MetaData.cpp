/*
 * MetaData.cpp
 *
 *  Created on: Dec 11, 2017
 *      Author: ben
 */

#include "MetaData.h"

MetaData::MetaData(const string compressedData) {
	this->compressedData = compressedData;
	this->compressedDataArr = compressedData.data();
	// TODO Auto-generated constructor stub

}

string MetaData::makeMetaData(unsigned int blockSize, unsigned int numOfBlocks, unsigned int amountOfPadding, unsigned int uniqueCharacters, char characterSet[]) {
	string stringBuffer = "";

	stringBuffer+=Util::unsignedIntToString(blockSize);
	stringBuffer+=Util::unsignedIntToString(numOfBlocks);
	stringBuffer+=Util::unsignedIntToString(amountOfPadding);
	stringBuffer+=Util::unsignedIntToString(uniqueCharacters);
	for(unsigned int i = 0; i< uniqueCharacters; i++){
		stringBuffer+=characterSet[i];
	}

	return stringBuffer;
}

int MetaData::getBlocksize() {
	int* retBuffer;
	memcpy(retBuffer, &compressedDataArr, 4);
	return *retBuffer;
}
int MetaData::getNumOfBlocks() {
	return (int) compressedDataArr[2];
}
int MetaData::getAmountPadding() {
	return (int) compressedDataArr[4];
}
int MetaData::getAmountUniqueCharacters() {
	return (int) compressedDataArr[6];
}
string MetaData::getCharacterSet() {
	return compressedData.substr(8);
}

MetaData::~MetaData() {
	// TODO Auto-generated destructor stub
}
