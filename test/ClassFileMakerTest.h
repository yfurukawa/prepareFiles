/**
 * ClassFileMakerTest.h
 *
 *  Created on: 2013/08/13
 *      Author: furukawayoshihiro
 */

#ifndef CLASSFILEMAKERTEST_H_
#define CLASSFILEMAKERTEST_H_

#include <string>
#include <gtest/gtest.h>
#include "mocks/ClassFileMakerSpy.h"

class ClassFileMakerTest: public ::testing::Test {
public:
	ClassFileMakerTest();
	virtual ~ClassFileMakerTest();

protected:
	ClassFileMakerSpy* sut;

	virtual void SetUp();
	virtual void TearDown();
	std::string createExpectedHeader(std::string className);

};

#endif /* CLASSFILEMAKERTEST_H_ */
