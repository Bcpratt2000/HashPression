/*
 * HashPressionController.h
 *
 *  Created on: Dec 11, 2017
 *      Author: ben
 */

#include <string>

#include "Util.h"
#include "MetaData.h"

#ifndef MODEL_HASHPRESSIONCONTROLLER_H_
#define MODEL_HASHPRESSIONCONTROLLER_H_

using namespace std;

class HashPressionController {
public:
	HashPressionController();
	virtual ~HashPressionController();
	string compress(string, unsigned int);
	string deconmpress(string&);
};


#endif /* MODEL_HASHPRESSIONCONTROLLER_H_ */
