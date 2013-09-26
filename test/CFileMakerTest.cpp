/*
 * CFileMakerTest.cpp
 *
 *  Created on: 2013/09/26
 *      Author: furukawayoshihiro
 */
#include <iostream>

#include "CFileMakerTest.h"
#include "mocks/OutputterMock.h"

CFileMakerTest::CFileMakerTest() : sut(NULL) {
	// TODO 自動生成されたコンストラクター・スタブ

}

CFileMakerTest::~CFileMakerTest() {
	// TODO Auto-generated destructor stub
}


void CFileMakerTest::SetUp() {
	sut = new CFileMakerSpy("Hoge");
}

void CFileMakerTest::TearDown() {
	delete sut;
}

TEST_F(CFileMakerTest, createInstance) {
	EXPECT_EQ("Hoge", sut->getName());
}

TEST_F(CFileMakerTest, createModuleFileName) {
	EXPECT_EQ("Hoge.c", sut->getClassName());
}

TEST_F(CFileMakerTest, createHeaderFileName) {
	EXPECT_EQ("Hoge.h", sut->getHeaderName());
}


TEST_F(CFileMakerTest, createObjectFileName) {
	EXPECT_EQ("Hoge.o", sut->getObjectName());
}

TEST_F(CFileMakerTest, createHeaderFile) {
	std::string expected = "#ifndef HOGE_H_\n#define HOGE_H_\n\n#endif\n";
	sut->createFiles();

	EXPECT_EQ(expected, sut->getHeaderSkeleton());
}


TEST_F(CFileMakerTest, createHeaderFile_Fuga) {
	std::string expected = "#ifndef FUGA_H_\n#define FUGA_H_\n\n#endif\n";
	delete sut;
	sut = new CFileMakerSpy("Fuga");
	sut->createFiles();

	EXPECT_EQ(expected, sut->getHeaderSkeleton());
}


TEST_F(CFileMakerTest, createCFile) {
	std::string expected = "#include \"Hoge.h\"\n\n";
	sut->createFiles();

	EXPECT_EQ(expected, sut->getCppSkeleton());
}

TEST_F(CFileMakerTest, createCFile_Fuga) {
	std::string expected = "#include \"Fuga.h\"\n\n";
	delete sut;
	sut = new CFileMakerSpy("Fuga");
	sut->createFiles();

	EXPECT_EQ(expected, sut->getCppSkeleton());
}

TEST_F(CFileMakerTest, setOutputter) {
	IOutputter* outputter = new OutputterMock();
	sut->setOutputter( outputter );

	EXPECT_EQ(outputter, sut->getOutputter());
}

TEST_F(CFileMakerTest, outputContents) {
	std::string expectedHeaderContents = "#ifndef HOGE_H_\n#define HOGE_H_\n\n#endif\n";
	std::string expectedCppContents = "#include \"Hoge.h\"\n\n";
	OutputterMock* outputterMock = new OutputterMock();
	IOutputter* outputter = outputterMock;
	sut->setOutputter( outputter );
	sut->createFiles();

	EXPECT_EQ(2, outputterMock->getNumberOfCall());
	EXPECT_EQ("src/Hoge.h", outputterMock->getOutputName(0));
	EXPECT_EQ(expectedHeaderContents, outputterMock->getContents(0));
	EXPECT_EQ("src/Hoge.c", outputterMock->getOutputName(1));
	EXPECT_EQ(expectedCppContents, outputterMock->getContents(1));

}
