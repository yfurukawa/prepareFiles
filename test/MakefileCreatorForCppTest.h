/*
 * MakefileMakerForCppTest.h
 *
 *  Created on: 2013/08/24
 *      Author: furukawayoshihiro
 */

#ifndef MAKEFILECREATORFORCPPTEST_H_
#define MAKEFILECREATORFORCPPTEST_H_

#include <gtest/gtest.h>

#include "IMakefileCreator.h"

class MakefileCreatorForCppTest : public ::testing::Test {
protected:
	IMakefileCreator* sut;
public:
	MakefileCreatorForCppTest();
	virtual ~MakefileCreatorForCppTest();
};

#endif /* MAKEFILEMAKERFORCPPTEST_H_ */
