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

class FileDAOTest: public ::testing::Test {
protected:
	FileDAO* sut;

public:
	FileDAOTest();
	virtual ~FileDAOTest();
	void SetUp();
	void TearDown();
};

#endif /* FILEOUTPUTTERTEST_H_ */
