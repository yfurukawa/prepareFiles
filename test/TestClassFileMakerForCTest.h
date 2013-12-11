/**
 * TestClassFileMakerForCTest.h
 *
 *  Created on: 2013/09/28
 *      Author: furukawayoshihiro
 */

#ifndef TESTCLASSFILEMAKERFORCTEST_H_
#define TESTCLASSFILEMAKERFORCTEST_H_

#include <gtest/gtest.h>
#include "mocks/TestClassFileMakerForCSpy.h"

class TestClassFileMakerForCTest: public ::testing::Test {
protected:
	TestClassFileMakerForCSpy* sut;

	void SetUp();
	void TearDown();
	std::string getExpectedHeaderContents();
	std::string getExpectedSourceContents();
public:
	TestClassFileMakerForCTest();
	virtual ~TestClassFileMakerForCTest();
};

#endif /* TESTCLASSFILEMAKERFORCTEST_H_ */
