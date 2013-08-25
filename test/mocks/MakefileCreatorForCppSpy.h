/*
 * MakefileCreatorForCppSpy.h
 *
 *  Created on: 2013/08/25
 *      Author: furukawayoshihiro
 */

#ifndef MAKEFILECREATORFORCPPSPY_H_
#define MAKEFILECREATORFORCPPSPY_H_

#include "MakefileCreatorForCpp.h"

class MakefileCreatorForCppSpy: public MakefileCreatorForCpp {
public:
	MakefileCreatorForCppSpy();
	virtual ~MakefileCreatorForCppSpy();
	const IOutputter* getOutputter() const;
};

#endif /* MAKEFILECREATORFORCPPSPY_H_ */
