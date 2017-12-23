/*
 * Util.cpp
 *
 *  Created on: Nov 16, 2017
 *      Author: ben
 */

#include "Util.h"

Util::Util() {
	// TODO Auto-generated constructor stub

}

int Util::isInCharVector(vector<char>& vect, char character) {
	for (unsigned long i = 0; i < vect.size(); i++) {
		if (vect[i] == character) {
			return 1;
		}
	}
	return 0;
}

unsigned long Util::hash(string input) {
	unsigned long retBuffer = 0;
	for (unsigned int i = 0; i < 8 * input.size() ; i++) {
		retBuffer += ((input[i % input.size()] ^ input[(i + 1) % input.size()]) * i * 100109) + input[retBuffer % input.size()];
	}
	return retBuffer;

}

string Util::deHash(unsigned long hash, const char* characterSet, int characterSetLength, int blockSize) {
	string strBuffer = "";
	int index = 0;

	for (unsigned long i = 0; i < pow(characterSetLength, blockSize); i) {
		index++;
		for (int x = 0; x < blockSize; x++) {
			srand(index*(x+1));
			strBuffer += characterSet[rand() % characterSetLength];
		}
		if (Util::hash(strBuffer) == hash) {
			return strBuffer;
		}
		strBuffer = "";
	}
	cout << "Unable to deHash" << endl;
	exit(1);
	return 0;
}

int Util::countOccurences(string& sample, string pattern) {
	int index = sample.find(pattern);
	int count = 0;
	while (index != -1) {
		count++;
		sample = sample.substr(index + 1);
		index = sample.find(pattern);
	}
	return count;
}

string Util::readFile(string file) {
	string strBuffer = "";

	std::ifstream fileStream;
	fileStream.open(file);
	ostringstream ss = ostringstream { };
	ss << fileStream.rdbuf();
	fileStream.close();

	if (ss.str().size() == 0) {
		cout << file << " Was empty, Exiting..." << endl;
		exit(1);
	}

	return ss.str();
}
void Util::writeFile(string file, string& input) {
	std::ofstream out(file);
	out << input;
	out.close();
}

void Util::toLower(string& text) {
	for (unsigned int i = 0; i < text.length(); ++i) {
		text[i] = tolower(text[i]);
	}
}

string Util::unsignedLongToString(unsigned long input) {
	string retBuffer = "";
	char charBuffer[sizeof(input)];
	for (unsigned int i = 0; i < sizeof(input); i++) {
		charBuffer[i] = (input >> (i * 8)) & 0xff;
	}
	for (unsigned int i = 0; i < sizeof(charBuffer); i++) {
		retBuffer += charBuffer[i];
	}
	return retBuffer;
}

string Util::unsignedIntToString(unsigned int input) {
	string retBuffer = "";
	char charBuffer[sizeof(input)];
	for (unsigned int i = 0; i < sizeof(input); i++) {
		charBuffer[i] = (input >> (i * 8)) & 0xff;
	}
	for (unsigned int i = 0; i < sizeof(charBuffer); i++) {
		retBuffer += charBuffer[i];
	}
	return retBuffer;
}

Util::~Util() {
	// TODO Auto-generated destructor stub
}
