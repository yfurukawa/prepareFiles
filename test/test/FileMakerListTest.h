/*
 * FileMakerListTest.h
 *
 *  Created on: 2013/08/15
 *      Author: furukawayoshihiro
 */

#ifndef FILEMAKERLISTTEST_H_
#define FILEMAKERLISTTEST_H_

#include <gtest/gtest.h>

#include "mocks/FileMakerListSpy.h"

class FileMakerListTest: public ::testing::Test {
protected:
	FileMakerListSpy* sut;
	void SetUp();
	void TearDown();

public:
	FileMakerListTest();
	virtual ~FileMakerListTest();
};

#endif /* FILEMAKERLISTTEST_H_ */
