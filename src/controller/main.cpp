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
	string text;

	srand(time(NULL));

//	text = compressor.compress(Util::readFile(fileToRead), 128);

//	MetaData data = MetaData(text);
	string l;
	while(true){
		l = to_string(rand());
	text = Util::unsignedLongToString(Util::hash(l));

	Util::writeFile("src/out.txt", text);
	}

	cout <<"Test"<< endl;

//	cout << text << endl;


	return 0;
}
