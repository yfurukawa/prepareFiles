/**
 * TestMainMakerTest.h
 *
 *  Created on: 2013/09/22
 *      Author: furukawayoshihiro
 */

#ifndef TESTMAINMAKERTEST_H_
#define TESTMAINMAKERTEST_H_

#include <gtest/gtest.h>
#include "mocks/TestMainMakerSpy.h"

class TestMainMakerTest: public ::testing::Test {
protected:
	TestMainMakerSpy* sut;
public:
	TestMainMakerTest();
	virtual ~TestMainMakerTest();
};

#endif /* TESTMAINMAKERTEST_H_ */
