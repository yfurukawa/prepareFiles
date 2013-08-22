/*
 * ClassFileMakerTest.cpp
 *
 *  Created on: 2013/08/13
 *      Author: furukawayoshihiro
 */

#include "ClassFileMakerTest.h"
//#include "mocks/ClassFileMakerSpy.h"
#include "mocks/OutputterMock.h"
#include "IOutputter.h"

ClassFileMakerTest::ClassFileMakerTest() : sut(NULL){
	// TODO 自動生成されたコンストラクター・スタブ

}

void ClassFileMakerTest::SetUp() {
	sut = new ClassFileMakerSpy("Hoge");
}

void ClassFileMakerTest::TearDown() {
	delete sut;
}

ClassFileMakerTest::~ClassFileMakerTest() {
	// TODO Auto-generated destructor stub
}

TEST_F(ClassFileMakerTest, createInstance) {
	EXPECT_EQ("Hoge", sut->getName());
}

TEST_F(ClassFileMakerTest, createClassFileName) {
	EXPECT_EQ("Hoge.cpp", sut->getClassName());
}

TEST_F(ClassFileMakerTest, createHeaderFileName) {
	EXPECT_EQ("Hoge.h", sut->getHeaderName());
}

TEST_F(ClassFileMakerTest, createHeaderFile) {
	std::string expected = "#ifndef HOGE_H_\n#define HOGE_H_\n\nclass Hoge {\npublic:\n\tHoge();\n\tvirtual ~Hoge();\n\n};\n\n#endif";
	sut->createFiles();

	EXPECT_EQ(expected, sut->getHeaderSkeleton());
}

TEST_F(ClassFileMakerTest, createHeaderFile_Fuga) {
	std::string expected = "#ifndef FUGA_H_\n#define FUGA_H_\n\nclass Fuga {\npublic:\n\tFuga();\n\tvirtual ~Fuga();\n\n};\n\n#endif";
	delete sut;
	sut = new ClassFileMakerSpy("Fuga");
	sut->createFiles();

	EXPECT_EQ(expected, sut->getHeaderSkeleton());
}

TEST_F(ClassFileMakerTest, createCppFile) {
	std::string expected = "#include \"Hoge.h\"\n\nHoge::Hoge() {\n\n}\n\nHoge::~Hoge() {\n\n}\n";
	sut->createFiles();

	EXPECT_EQ(expected, sut->getCppSkeleton());
}

TEST_F(ClassFileMakerTest, createCppFile_Fuga) {
	std::string expected = "#include \"Fuga.h\"\n\nFuga::Fuga() {\n\n}\n\nFuga::~Fuga() {\n\n}\n";
	delete sut;
	sut = new ClassFileMakerSpy("Fuga");
	sut->createFiles();

	EXPECT_EQ(expected, sut->getCppSkeleton());
}

TEST_F(ClassFileMakerTest, setOutputter) {
	IOutputter* outputter = new OutputterMock();
	sut->setOutputter( outputter );

	EXPECT_EQ(outputter, sut->getOutputter());
}

TEST_F(ClassFileMakerTest, outputContents) {
	std::string expectedHeaderContents = "#ifndef HOGE_H_\n#define HOGE_H_\n\nclass Hoge {\npublic:\n\tHoge();\n\tvirtual ~Hoge();\n\n};\n\n#endif";
	std::string expectedCppContents = "#include \"Hoge.h\"\n\nHoge::Hoge() {\n\n}\n\nHoge::~Hoge() {\n\n}\n";
	OutputterMock* outputterMock = new OutputterMock();
	IOutputter* outputter = outputterMock;
	sut->setOutputter( outputter );
	sut->createFiles();

	EXPECT_EQ(2, outputterMock->getNumberOfCall());
	EXPECT_EQ("Hoge.h", outputterMock->getOutputName(0));
	EXPECT_EQ(expectedHeaderContents, outputterMock->getContents(0));
	EXPECT_EQ("Hoge.cpp", outputterMock->getOutputName(1));
	EXPECT_EQ(expectedCppContents, outputterMock->getContents(1));

}
