/*
 * TestClassFileMakerForCTest.cpp
 *
 *  Created on: 2013/09/28
 *      Author: furukawayoshihiro
 */

#include <iostream>

#include "TestClassFileMakerForCTest.h"
#include "mocks/OutputterMock.h"

TestClassFileMakerForCTest::TestClassFileMakerForCTest() : sut(NULL) {
	// TODO 自動生成されたコンストラクター・スタブ

}

void TestClassFileMakerForCTest::SetUp() {
	sut = new TestClassFileMakerForCSpy("Hoge");
}

void TestClassFileMakerForCTest::TearDown() {
}

TestClassFileMakerForCTest::~TestClassFileMakerForCTest() {
	// TODO Auto-generated destructor stub
}

TEST_F(TestClassFileMakerForCTest, createInstance) {
	EXPECT_EQ("HogeTest", sut->getName());
}

TEST_F(TestClassFileMakerForCTest, createClassFileName) {
	EXPECT_EQ("../test/HogeTest.cpp", sut->getClassName());
}

TEST_F(TestClassFileMakerForCTest, createHeaderFileName) {
	EXPECT_EQ("HogeTest.h", sut->getHeaderName());
}

TEST_F(TestClassFileMakerForCTest, createObjectFileName) {
	EXPECT_EQ("HogeTest.o", sut->getObjectName());
}

TEST_F(TestClassFileMakerForCTest, createHeaderFile) {
	std::string expected = getExpectedHeaderContents();
	sut->createFiles();

	EXPECT_EQ(expected, sut->getHeaderSkeleton());
}

TEST_F(TestClassFileMakerForCTest, createHeaderFile_Fuga) {
	std::string expected = "#ifndef FUGATEST_H_\n#define FUGATEST_H_\n\n#include <gtest/gtest.h>\n\nextern \"C\" {\n\t#include \"Fuga.h\"\n}\n\nclass FugaTest : public ::testing::Test {\n";
	expected += "protected:\n\tFuga* sut;\n\tvoid SetUp();\n\tvoid TearDown();\n\npublic:\n\tFugaTest();\n\tvirtual ~FugaTest();\n\n};\n\n#endif\n";
	delete sut;
	sut = new TestClassFileMakerForCSpy("Fuga");
	sut->createFiles();

	EXPECT_EQ(expected, sut->getHeaderSkeleton());
}

TEST_F(TestClassFileMakerForCTest, createCppFile) {
	std::string expected = getExpectedSourceContents();
	sut->createFiles();

	EXPECT_EQ(expected, sut->getCppSkeleton());
}

TEST_F(TestClassFileMakerForCTest, createCppFile_Fuga) {
	std::string expected = "#include \"FugaTest.h\"\n\nFugaTest::FugaTest() {\n\n}\n\nFugaTest::~FugaTest() {\n\n}\n\n";
	expected += "void FugaTest::SetUp() {\n\tsut = new Fuga();\n}\n\nvoid FugaTest::TearDown() {\n\tdelete sut;\n}\n\nTEST_F (FugaTest, testNameIsHere_ChangeThis) {\n/* Write a test code here. */\n\n}\n";
	delete sut;
	sut = new TestClassFileMakerForCSpy("Fuga");
	sut->createFiles();

	EXPECT_EQ(expected, sut->getCppSkeleton());
}

TEST_F(TestClassFileMakerForCTest, setOutputter) {
	IOutputter* outputter = new OutputterMock();
	sut->setOutputter( outputter );

	EXPECT_EQ(outputter, sut->getOutputter());
}

TEST_F(TestClassFileMakerForCTest, outputContents) {
	std::string expectedHeaderContents = getExpectedHeaderContents();
	std::string expectedCppContents = getExpectedSourceContents();
	OutputterMock* outputterMock = new OutputterMock();
	IOutputter* outputter = outputterMock;
	sut->setOutputter( outputter );
	sut->createFiles();

	EXPECT_EQ(2, outputterMock->getNumberOfCall());
	EXPECT_EQ("test/HogeTest.h", outputterMock->getOutputName(0));
	EXPECT_EQ(expectedHeaderContents, outputterMock->getContents(0));
	EXPECT_EQ("test/HogeTest.cpp", outputterMock->getOutputName(1));
	EXPECT_EQ(expectedCppContents, outputterMock->getContents(1));

}


std::string TestClassFileMakerForCTest::getExpectedHeaderContents() {
	std::string expected = "#ifndef HOGETEST_H_\n";
	expected += "#define HOGETEST_H_\n";
	expected += "\n";
	expected += "#include <gtest/gtest.h>\n";
	expected += "\n";
	expected += "extern \"C\" {\n";
	expected += "\t#include \"Hoge.h\"\n";
	expected += "}\n";
	expected += "\n";
	expected += "class HogeTest : public ::testing::Test {\n";
	expected += "protected:\n";
	expected += "\tHoge* sut;\n";
	expected += "\tvoid SetUp();\n";
	expected += "\tvoid TearDown();\n";
	expected += "\n";
	expected += "public:\n";
	expected += "\tHogeTest();\n";
	expected += "\tvirtual ~HogeTest();\n";
	expected += "\n";
	expected += "};\n";
	expected += "\n";
	expected += "#endif\n";
	return expected;
}

std::string TestClassFileMakerForCTest::getExpectedSourceContents() {
	std::string expected = "#include \"HogeTest.h\"\n\nHogeTest::HogeTest() {\n\n}\n\nHogeTest::~HogeTest() {\n\n}\n\n";
	expected += "void HogeTest::SetUp() {\n\tsut = new Hoge();\n}\n\nvoid HogeTest::TearDown() {\n\tdelete sut;\n}\n\nTEST_F (HogeTest, testNameIsHere_ChangeThis) {\n/* Write a test code here. */\n\n}\n";
	return expected;
}
