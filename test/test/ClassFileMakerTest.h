/*
 * ClassFileMakerTest.h
 *
 *  Created on: 2013/08/13
 *      Author: furukawayoshihiro
 */

#ifndef CLASSFILEMAKERTEST_H_
#define CLASSFILEMAKERTEST_H_

#include <gtest/gtest.h>
#include "mocks/ClassFileMakerSpy.h"

class ClassFileMakerTest: public ::testing::Test {
protected:
	ClassFileMakerSpy* sut;

	virtual void SetUp();
	virtual void TearDown();

public:
	ClassFileMakerTest();
	virtual ~ClassFileMakerTest();
};

#endif /* CLASSFILEMAKERTEST_H_ */
