/**
 * CFileMakerTest.h
 *
 *  Created on: 2013/09/26
 *      Author: furukawayoshihiro
 */

#ifndef CFILEMAKERTEST_H_
#define CFILEMAKERTEST_H_

#include <gtest/gtest.h>

#include "mocks/CFileMakerSpy.h"

class CFileMakerTest: public ::testing::Test {
protected:
	CFileMakerSpy* sut;

	void SetUp();
	void TearDown();
public:
	CFileMakerTest();
	virtual ~CFileMakerTest();
};

#endif /* CFILEMAKERTEST_H_ */
