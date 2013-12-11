/**
 * TestMainMakerTest.cpp
 *
 *  Created on: 2013/09/22
 *      Author: furukawayoshihiro
 */

#include "TestMainMakerTest.h"
#include "mocks/OutputterMock.h"
#include "IOutputter.h"

TestMainMakerTest::TestMainMakerTest() : sut(NULL) {
	// TODO �����������ꂽ�R���X�g���N�^�[�E�X�^�u
	sut = new TestMainMakerSpy();
}

TestMainMakerTest::~TestMainMakerTest() {
	// TODO Auto-generated destructor stub
}

TEST_F(TestMainMakerTest, createInstance) {
	EXPECT_EQ("testMain", sut->getName());
}

TEST_F(TestMainMakerTest, createClassFileName) {
	EXPECT_EQ("testMain.cpp", sut->getClassName());
}

TEST_F(TestMainMakerTest, createObjectFileName) {
	EXPECT_EQ("testMain.o", sut->getObjectName());
}

TEST_F(TestMainMakerTest, createCppFile) {
	std::string expected = "#include <gtest/gtest.h>\n\n";
	expected += "int main(int argc, char** argv) {\n";
	expected += "\t::testing::InitGoogleTest(&argc, argv);\n";
	expected += "\treturn RUN_ALL_TESTS();\n";
	expected += "}\n";

	sut->createFiles();

	EXPECT_EQ(expected, sut->getCppSkeleton());
}

TEST_F(TestMainMakerTest, setOutputter) {
	IOutputter* outputter = new OutputterMock();
	sut->setOutputter( outputter );

	EXPECT_EQ(outputter, sut->getOutputter());
}

TEST_F(TestMainMakerTest, outputContents) {
	std::string expectedCppContents = "#include <gtest/gtest.h>\n\n";
	expectedCppContents += "int main(int argc, char** argv) {\n";
	expectedCppContents += "\t::testing::InitGoogleTest(&argc, argv);\n";
	expectedCppContents += "\treturn RUN_ALL_TESTS();\n";
	expectedCppContents += "}\n";

	OutputterMock* outputterMock = new OutputterMock();
	IOutputter* outputter = outputterMock;
	sut->setOutputter( outputter );
	sut->createFiles();

	EXPECT_EQ(1, outputterMock->getNumberOfCall());
	EXPECT_EQ("test/testMain.cpp", outputterMock->getOutputName(0));
	EXPECT_EQ(expectedCppContents, outputterMock->getContents(0));
}
