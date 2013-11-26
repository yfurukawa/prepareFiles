/*
 * MakefileCreatorForCppSpy.h
 *
 *  Created on: 2013/08/25
 *      Author: furukawayoshihiro
 */

#ifndef MAKEFILECREATORFORCPPSPY_H_
#define MAKEFILECREATORFORCPPSPY_H_

#include <iostream>

#include "MakefileCreatorForCpp.h"

class MakefileCreatorForCppSpy: public MakefileCreatorForCpp {
private:
	MakefileCreatorForCppSpy();
public:
	MakefileCreatorForCppSpy( std::string targetName );
	virtual ~MakefileCreatorForCppSpy();
	const IOutputter* getOutputter() const;

};

#endif /* MAKEFILECREATORFORCPPSPY_H_ */
