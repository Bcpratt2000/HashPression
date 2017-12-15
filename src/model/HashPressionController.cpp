/*
 * HashPressionController.cpp
 *
 *  Created on: Dec 11, 2017
 *      Author: ben
 */

#include "HashPressionController.h"


string HashPressionController::compress(string input, unsigned int blockSize){
	string retBuffer = "";
	string toHash;
	unsigned int numOfBlocks = input.size()/blockSize;
	int amountOfPadding = 0;
	const char * inputArr = input.data();
	vector<char> uniqueCharacters;

	//store all unique characters in a vector
	for(unsigned int i = 0; i < input.size(); i++){
		if(!Util::isInCharVector(uniqueCharacters, inputArr[i])){
			uniqueCharacters.push_back(inputArr[i]);
		}
	}


	//add padding to the end
	while(input.size()%blockSize!=0){
		input+=" ";
		amountOfPadding++;
	}

	//append meta data to the return buffer
	retBuffer+=MetaData::makeMetaData(blockSize, numOfBlocks, amountOfPadding, uniqueCharacters.size(), uniqueCharacters.data());



	//compress the data and append it to the string
	for(unsigned int i = 0; i < numOfBlocks; i++){
		toHash = input.substr(i*blockSize, blockSize);;
		retBuffer+=Util::unsignedLongToString(Util::hash(toHash));
	}

	return retBuffer;
}



HashPressionController::HashPressionController() {
	// TODO Auto-generated constructor stub

}

HashPressionController::~HashPressionController() {
	// TODO Auto-generated destructor stub
}
