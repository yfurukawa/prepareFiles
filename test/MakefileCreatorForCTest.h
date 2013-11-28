/*
 * MakefileCreatorForCTest.h
 *
 *  Created on: 2013/09/28
 *      Author: furukawayoshihiro
 */

#ifndef MAKEFILECREATORFORCTEST_H_
#define MAKEFILECREATORFORCTEST_H_

#include <gtest/gtest.h>

#include "mocks/MakefileCreatorForCSpy.h"

class MakefileCreatorForCTest: public ::testing::Test {
protected:
	MakefileCreatorForCSpy* sut;
	std::string createExpectedMakefileContents();

public:
	MakefileCreatorForCTest();
	virtual ~MakefileCreatorForCTest();
};

#endif /* MAKEFILECREATORFORCTEST_H_ */
