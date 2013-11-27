/**
 * SubMakefileCreatorTest.h
 *
 *  Created on: 2013/11/26
 *      Author: M825504
 */

#ifndef SUBMAKEFILECREATORTEST_H_
#define SUBMAKEFILECREATORTEST_H_

#include <gtest/gtest.h>

class SubMakefileCreatorSpy;

class SubMakefileCreatorTest: public ::testing::Test {
public:
	SubMakefileCreatorTest();
	virtual ~SubMakefileCreatorTest();

protected:
	SubMakefileCreatorSpy* sut;
};

#endif /* SUBMAKEFILECREATORTEST_H_ */
