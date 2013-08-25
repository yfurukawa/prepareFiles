/*
 * FileOutputterTest.cpp
 *
 *  Created on: 2013/08/14
 *      Author: furukawayoshihiro
 */

#include <iostream>
#include <fstream>

#include "FileOutputterTest.h"

FileOutputterTest::FileOutputterTest() {
	// TODO �����������ꂽ�R���X�g���N�^�[�E�X�^�u

}

FileOutputterTest::~FileOutputterTest() {
	// TODO Auto-generated destructor stub
}

void FileOutputterTest::SetUp() {
	sut = new FileOutputter();
}

void FileOutputterTest::TearDown() {
	delete sut;
}

TEST_F(FileOutputterTest, createFile_Hoge) {
	sut->outputContents("Hoge.cpp", "");

	std::ifstream in("Hoge.cpp");
	EXPECT_TRUE(in != NULL);
}

TEST_F(FileOutputterTest, createFile_Fuga) {
	sut->outputContents("Fuga.cpp", "");

	std::ifstream in("Fuga.cpp");
	EXPECT_TRUE(in != NULL);
}

TEST_F(FileOutputterTest, contents_foobar) {
	sut->outputContents("Hoge.cpp", "foo\nbar");

	std::ifstream in("Hoge.cpp");
	std::string contents;
	in >> contents;
	EXPECT_EQ("foo", contents);
	in >> contents;
	EXPECT_EQ("bar", contents);
}