/*
 * HashPressionController.cpp
 *
 *  Created on: Dec 11, 2017
 *      Author: ben
 */

#include "HashPressionController.h"

string HashPressionController::compress(string& input, unsigned int blockSize) {
	string retBuffer = "";
	string toHash;
	unsigned long numOfBlocks = input.size() / blockSize;
	if (input.size() % blockSize) {
		numOfBlocks++;
	}
	int amountOfPadding = 0;
	const char * inputArr = input.data();
	vector<char> uniqueCharacters;

	//add padding to the end
	while (input.size() % blockSize) {
		input += " ";
		amountOfPadding++;
	}

	//store all unique characters in a vector
	cout << "Finding Unique Characters..." << endl;
	for (unsigned long long i = 0; i < input.size(); i++) {
		if (!Util::isInCharVector(uniqueCharacters, inputArr[i])) {
			uniqueCharacters.push_back(inputArr[i]);
		}
		if (!(i % 10000000)) {
			cout << (double) i / (double) input.size() * 100 << '%' << endl;
		}
	}

	cout << "Found all unique characters" << endl;


	//append meta data to the return buffer
	retBuffer += MetaData::makeMetaData(blockSize, numOfBlocks, amountOfPadding, uniqueCharacters.size(), uniqueCharacters.data());

	//compress the data and append it to the string
	for (unsigned long long i = 0; i < numOfBlocks; i++) {
		toHash = input.substr(i * blockSize, blockSize);
		retBuffer += Util::unsignedLongToString(Util::hash(toHash));
		if (!(i % 100000)) {
			cout << (double) i / (double) numOfBlocks * 100 << '%' << endl;
		}
	}

	return retBuffer;
}

string HashPressionController::decompress(string& input) {
	MetaData meta = MetaData(input);

	unsigned int blockSize = meta.getBlocksize();
	unsigned int numOfBlocks = meta.getNumOfBlocks();
	unsigned int amountOfPadding = meta.getAmountPadding();
	unsigned int uniqueCharacterLength = meta.getAmountUniqueCharacters();

	string decompressedBlocks[numOfBlocks];
	string retBuffer;
	string tempStr;
	unsigned long tempLong;


	for(unsigned int i = 0; i<numOfBlocks; i++){

		tempStr = input.substr(16+uniqueCharacterLength+(i * 8), 8);
		memcpy(&tempLong, tempStr.data(), 8);
		decompressedBlocks[i] = Util::deHash(tempLong, meta.getCharacterSet().data(), uniqueCharacterLength, blockSize);

		cout << i+1 << "/" << numOfBlocks << endl;
	}

	for(unsigned int i = 0; i < numOfBlocks; i++){
		retBuffer+=decompressedBlocks[i];
	}

	retBuffer = retBuffer.substr(0, retBuffer.size()-amountOfPadding);

	return retBuffer;
}

HashPressionController::HashPressionController() {
	// TODO Auto-generated constructor stub

}

HashPressionController::~HashPressionController() {
	// TODO Auto-generated destructor stub
}
