//============================================================================
// Name        : main.cpp
// Author      : Ben Pratt
//============================================================================

#include <iostream>
#include <vector>

#include "../model/HashPressionController.h"
#include "../model/Util.h"
#include "../model/MetaData.h"

using namespace std;

int main() {

	HashPressionController compressor = HashPressionController();

	string text;
	string rawText = Util::readFile("src/WallOfText.txt");

	cout << "File Loaded, Compressing..." << endl;

	text = compressor.compress(rawText, 3);

	MetaData data = MetaData(text);

//	cout << "BlockSize: " << endl;
//	cout << data.getBlocksize() << endl;
//	cout << "numBlocks: " << endl;
//	cout << data.getNumOfBlocks() << endl;
//	cout << "AmountPadding: " << endl;
//	cout << data.getAmountPadding() << endl;
//	cout << "UniqueCharacters: " << endl;
//	cout << data.getAmountUniqueCharacters() << endl;
//	cout << "CharacterSet: " << endl;
//	cout << data.getCharacterSet() << endl;


	cout << "Writing to file" << endl;

	Util::writeFile("src/out.hps", text);

	cout << "File was written" << endl;

	cout << "Dehashing" << endl;

	string decompressedText = compressor.decompress(text);

	cout << "Writing to File" << endl;

	Util::writeFile("src/out.txt", decompressedText);

//	string toHash = "Hello world";
//	unsigned long hash = Util::hash(toHash);
//	vector<char> uniqueCharacters;
//		for (unsigned long long i = 0; i < toHash.size(); i++) {
//			if (!Util::isInCharVector(uniqueCharacters, toHash[i])) {
//				uniqueCharacters.push_back(toHash[i]);
//			}
//		}
//	cout << Util::deHash(hash, uniqueCharacters.data(), uniqueCharacters.size(), toHash.length()) << endl;


	return 0;
}
