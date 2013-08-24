/*
 * MakefileMakerForCpp.h
 *
 *  Created on: 2013/08/24
 *      Author: furukawayoshihiro
 */

#ifndef MAKEFILECREATORFORCPP_H_
#define MAKEFILECREATORFORCPP_H_

#include "IMakefileCreator.h"

class MakefileCreatorForCpp: public IMakefileCreator {
public:
	MakefileCreatorForCpp();
	virtual ~MakefileCreatorForCpp();
};

#endif /* MAKEFILECREATORFORCPP_H_ */
