/*
 * TestClassFileMakerTest.cpp
 *
 *  Created on: 2013/08/14
 *      Author: furukawayoshihiro
 */

#include "TestClassFileMakerTest.h"
#include "mocks/OutputterMock.h"

TestClassFileMakerTest::TestClassFileMakerTest() : sut(NULL) {
	// TODO

}

TestClassFileMakerTest::~TestClassFileMakerTest() {
	// TODO Auto-generated destructor stub
}

void TestClassFileMakerTest::SetUp() {
	sut = new TestClassFileMakerSpy("Hoge");
}

void TestClassFileMakerTest::TearDown() {
	delete sut;
}

TEST_F(TestClassFileMakerTest, createInstance) {
	EXPECT_EQ("HogeTest", sut->getName());
}

TEST_F(TestClassFileMakerTest, createClassFileName) {
	EXPECT_EQ("../test/HogeTest.cpp", sut->getClassName());
}

TEST_F(TestClassFileMakerTest, createHeaderFileName) {
	EXPECT_EQ("HogeTest.h", sut->getHeaderName());
}

TEST_F(TestClassFileMakerTest, createObjectFileName) {
	EXPECT_EQ("HogeTest.o", sut->getObjectName());
}

TEST_F(TestClassFileMakerTest, createHeaderFile) {
	std::string expected = getExpectedHeaderContents();
	sut->createFiles();

	EXPECT_EQ(expected, sut->getHeaderSkeleton());
}

TEST_F(TestClassFileMakerTest, createHeaderFile_Fuga) {
	std::string expected = "#ifndef FUGATEST_H_\n#define FUGATEST_H_\n\n#include <gtest/gtest.h>\n#include \"Fuga.h\"\n\nclass FugaTest : public ::testing::Test {\n";
	expected += "protected:\n\tFuga* sut;\n\tvoid SetUp();\n\tvoid TearDown();\n\npublic:\n\tFugaTest();\n\tvirtual ~FugaTest();\n\n};\n\n#endif\n";
	delete sut;
	sut = new TestClassFileMakerSpy("Fuga");
	sut->createFiles();

	EXPECT_EQ(expected, sut->getHeaderSkeleton());
}

TEST_F(TestClassFileMakerTest, createCppFile) {
	std::string expected = getExpectedCppContents();
	sut->createFiles();

	EXPECT_EQ(expected, sut->getCppSkeleton());
}

TEST_F(TestClassFileMakerTest, createCppFile_Fuga) {
	std::string expected = "#include \"FugaTest.h\"\n\nFugaTest::FugaTest() {\n\n}\n\nFugaTest::~FugaTest() {\n\n}\n\n";
	expected += "void FugaTest::SetUp() {\n\tsut = new Fuga();\n}\n\nvoid FugaTest::TearDown() {\n\tdelete sut;\n}\n\nTEST_F (FugaTest, testNameIsHere_ChangeThis) {\n/* Write a test code here. */\n\n}\n";
	delete sut;
	sut = new TestClassFileMakerSpy("Fuga");
	sut->createFiles();

	EXPECT_EQ(expected, sut->getCppSkeleton());
}

TEST_F(TestClassFileMakerTest, setOutputter) {
	IOutputter* outputter = new OutputterMock();
	sut->setOutputter( outputter );

	EXPECT_EQ(outputter, sut->getOutputter());
}

TEST_F(TestClassFileMakerTest, outputContents) {
	std::string expectedHeaderContents = getExpectedHeaderContents();
	std::string expectedCppContents = getExpectedCppContents();
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


std::string TestClassFileMakerTest::getExpectedHeaderContents() {
	std::string expected = "#ifndef HOGETEST_H_\n#define HOGETEST_H_\n\n#include <gtest/gtest.h>\n#include \"Hoge.h\"\n\nclass HogeTest : public ::testing::Test {\n";
	expected += "protected:\n\tHoge* sut;\n\tvoid SetUp();\n\tvoid TearDown();\n\npublic:\n\tHogeTest();\n\tvirtual ~HogeTest();\n\n};\n\n#endif\n";
	return expected;
}

std::string TestClassFileMakerTest::getExpectedCppContents() {
	std::string expected = "#include \"HogeTest.h\"\n\nHogeTest::HogeTest() {\n\n}\n\nHogeTest::~HogeTest() {\n\n}\n\n";
	expected += "void HogeTest::SetUp() {\n\tsut = new Hoge();\n}\n\nvoid HogeTest::TearDown() {\n\tdelete sut;\n}\n\nTEST_F (HogeTest, testNameIsHere_ChangeThis) {\n/* Write a test code here. */\n\n}\n";
	return expected;
}
