/*
 * FileOutputterTest.h
 *
 *  Created on: 2013/08/14
 *      Author: furukawayoshihiro
 */

#ifndef FILEOUTPUTTERTEST_H_
#define FILEOUTPUTTERTEST_H_

#include <gtest/gtest.h>
#include "FileOutputter.h"

class FileOutputterTest: public ::testing::Test {
protected:
	FileDAO* sut;

public:
	FileOutputterTest();
	virtual ~FileOutputterTest();
	void SetUp();
	void TearDown();
};

#endif /* FILEOUTPUTTERTEST_H_ */
