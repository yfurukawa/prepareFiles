/*
 * MakefileMakerForCppTest.h
 *
 *  Created on: 2013/08/24
 *      Author: furukawayoshihiro
 */

#ifndef MAKEFILECREATORFORCPPTEST_H_
#define MAKEFILECREATORFORCPPTEST_H_

#include <gtest/gtest.h>

#include "mocks/MakefileCreatorForCppSpy.h"

class MakefileCreatorForCppTest : public ::testing::Test {
protected:
	MakefileCreatorForCppSpy* sut;
public:
	MakefileCreatorForCppTest();
	virtual ~MakefileCreatorForCppTest();
};

#endif /* MAKEFILEMAKERFORCPPTEST_H_ */
