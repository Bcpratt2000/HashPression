//============================================================================
// Name        : main.cpp
// Author      : Ben Pratt
//============================================================================

#include <iostream>

#include "../model/HashPressionController.h"
#include "../model/Util.h"
#include "../model/MetaData.h"

using namespace std;

int main() {

	HashPressionController compressor = HashPressionController();
	string fileToRead = "src/WallOfText.txt";

	string text = compressor.compress(Util::readFile(fileToRead), 3);

	MetaData data = MetaData(text);

	cout << data.getBlocksize() << endl;

	Util::writeFile("src/out.txt", text);

	cout << text << endl;

	return 0;
}
