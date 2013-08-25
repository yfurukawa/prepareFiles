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
protected:
	IOutputter* outputter_;

public:
	MakefileCreatorForCpp();
	virtual ~MakefileCreatorForCpp();
	virtual void setOutputter(IOutputter* outputter);

};

#endif /* MAKEFILECREATORFORCPP_H_ */
