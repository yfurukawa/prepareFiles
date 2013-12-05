/*
 * FileOutputterDAO.cpp
 *
 *  Created on: 2013/08/14
 *      Author: furukawayoshihiro
 */

#include <iostream>
#include <fstream>

#include "FileDAOTest.h"

FileDAOTest::FileDAOTest() : sut(NULL) {
	// TODO �����������ꂽ�R���X�g���N�^�[�E�X�^�u

}

FileDAOTest::~FileDAOTest() {
	// TODO Auto-generated destructor stub
}

void FileDAOTest::SetUp() {
	sut = new FileDAO();
}

void FileDAOTest::TearDown() {
	delete sut;
}

TEST_F(FileDAOTest, createFile_Hoge) {
	sut->outputContents("Hoge.cpp", "");

	std::ifstream in("Hoge.cpp");
	EXPECT_TRUE(in != NULL);
}

TEST_F(FileDAOTest, createFile_Fuga) {
	sut->outputContents("Fuga.cpp", "");

	std::ifstream in("Fuga.cpp");
	EXPECT_TRUE(in != NULL);
}

TEST_F(FileDAOTest, contents_foobar) {
	sut->outputContents("Hoge.cpp", "foo\nbar");

	std::ifstream in("Hoge.cpp");
	std::string contents;
	in >> contents;
	EXPECT_EQ("foo", contents);
	in >> contents;
	EXPECT_EQ("bar", contents);
}

TEST_F(FileDAOTest, catchExceptionWhenOpenFileInputDueToFileNOTExsist) {
	EXPECT_THROW( sut->openInputter("NotExsitFile"), std::ios::failure);
}

TEST_F(FileDAOTest, notCatchExceptionWhenOpenFileDueToInputFileExsist) {
	EXPECT_NO_THROW( sut->openInputter("FileDAO.cpp") );
}
