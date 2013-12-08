/*
 * FileDAOTest.h
 *
 *  Created on: 2013/08/14
 *      Author: furukawayoshihiro
 */

#ifndef FILEDAOTEST_H_
#define FILEDAOTEST_H_

#include <gtest/gtest.h>
#include "FileDAO.h"

class FileDAOTest: public ::testing::Test {
protected:
	FileDAO* sut;
	void prepareTestingFile( std::string fileName = "t.txt", std::string contents = "No contents");
public:
	FileDAOTest();
	virtual ~FileDAOTest();
	void SetUp();
	void TearDown();
};

#endif /* FILEDAOTEST_H_ */
