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

int Util::isInCharVector(vector<char>& vect, char character){
	for(unsigned int i = 0; i<vect.size(); i++){
		if(vect.at(i) == character){
			return 1;
		}
	}
	return 0;
}

unsigned long Util::hash(string& input){
		unsigned long sumOfChars = 0;
		auto inputArr = input.data();
		unsigned long size = 8;
		unsigned long retBuffer = 0;

		for(unsigned int i = 0; i<size*100; i++){
			sumOfChars += (inputArr[i%size]*inputArr[i<<(12203*i&size)%size])*12203*i;
		}
		retBuffer += (sumOfChars << 32);
		sumOfChars=0;
		for(unsigned int  i = 0; i<size*100; i++){
			sumOfChars += (inputArr[(sumOfChars+i*13)%size] ^ inputArr[(i*103841)%size])*103841*i;
		}
		retBuffer+=sumOfChars;
		return retBuffer;
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

string Util::readFile(string& file) {
	string strBuffer = "";

	std::ifstream fileStream;
	fileStream.open(file);
	ostringstream ss = ostringstream { };
	ss << fileStream.rdbuf();
	fileStream.close();

	if(ss.str().size() == 0){
		cout << file << " Was empty, Exiting..." << endl;
		exit(1);
	}

	return ss.str();
}
void Util::writeFile(string file, string& input){
	std::ofstream out(file);
	out << input;
	out.close();
}


void Util::toLower(string& text){
	for(unsigned int i = 0; i < text.length(); ++i) {
		text[i] = tolower(text[i]);
	}
}

string Util::unsignedLongToString(unsigned long input){
	string retBuffer = "";
	char charBuffer[sizeof(input)];
	for (unsigned int i = 0; i < sizeof(input); i++) {
			charBuffer[sizeof(input)-1-i] = (input >> (i*8)) & 0xff;
			cout << ((input >> (i*8)) & 0xff) << " ";

		}
	cout << endl;
	for(unsigned int i = 0; i < sizeof(charBuffer); i++){
		retBuffer+=charBuffer[i];
	}
	return retBuffer;
}

string Util::unsignedIntToString(unsigned int input){
	string retBuffer = "";
	char charBuffer[sizeof(input)];
	for (unsigned int i = 0; i < sizeof(input); i++) {
			charBuffer[sizeof(input)-1-i] = (input >> (i*8)) & 0xff;
		}
	for(unsigned int i = 0; i < sizeof(charBuffer); i++){
		retBuffer+=charBuffer[i];
	}
	return retBuffer;
}

Util::~Util() {
	// TODO Auto-generated destructor stub
}
