/*
 * TestClassFileMakerTest.h
 *
 *  Created on: 2013/08/14
 *      Author: furukawayoshihiro
 */

#ifndef TESTCLASSFILEMAKERTEST_H_
#define TESTCLASSFILEMAKERTEST_H_

#include <gtest/gtest.h>

#include "mocks/TestClassFileMakerSpy.h"

class TestClassFileMakerTest: public ::testing::Test {
protected:
	TestClassFileMakerSpy* sut;
	void SetUp();
	void TearDown();
	std::string getExpectedHeaderContents();
	std::string getExpectedCppContents();

public:
	TestClassFileMakerTest();
	virtual ~TestClassFileMakerTest();

};

#endif /* TESTCLASSFILEMAKERTEST_H_ */
