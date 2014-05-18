/**
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
	// TODO

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

TEST_F(ClassFileMakerTest, createObjectFileName) {
	EXPECT_EQ("Hoge.o", sut->getObjectName());
}

TEST_F(ClassFileMakerTest, createHeaderFile) {
	std::string expected = createExpectedHeader("Hoge");
	sut->createFiles();

	EXPECT_EQ(expected, sut->getHeaderSkeleton());
}

TEST_F(ClassFileMakerTest, createHeaderFile_Fuga) {
	std::string expected = createExpectedHeader("Fuga");
	delete sut;
	sut = new ClassFileMakerSpy("Fuga");
	sut->createFiles();

	EXPECT_EQ(expected, sut->getHeaderSkeleton());
}

TEST_F(ClassFileMakerTest, createCppFile) {
	std::string expected = "/*\n * Copyright\n *\n*/\n#include \"./Hoge.h\"\n\nHoge::Hoge() {\n}\n\nHoge::~Hoge() {\n}\n";
	sut->createFiles();

	EXPECT_EQ(expected, sut->getCppSkeleton());
}

TEST_F(ClassFileMakerTest, createCppFile_Fuga) {
	std::string expected = "/*\n * Copyright\n *\n*/\n#include \"./Fuga.h\"\n\nFuga::Fuga() {\n}\n\nFuga::~Fuga() {\n}\n";
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
	std::string expectedHeaderContents = createExpectedHeader("Hoge");
	std::string expectedCppContents = "/*\n * Copyright\n *\n*/\n#include \"./Hoge.h\"\n\nHoge::Hoge() {\n}\n\nHoge::~Hoge() {\n}\n";
	OutputterMock* outputterMock = new OutputterMock();
	IOutputter* outputter = outputterMock;
	sut->setOutputter( outputter );
	sut->createFiles();

	EXPECT_EQ(2, outputterMock->getNumberOfCall());
	EXPECT_EQ("src/Hoge.h", outputterMock->getOutputName(0));
	EXPECT_EQ(expectedHeaderContents, outputterMock->getContents(0));
	EXPECT_EQ("src/Hoge.cpp", outputterMock->getOutputName(1));
	EXPECT_EQ(expectedCppContents, outputterMock->getContents(1));

}

///////////////////////////////////////////////////////////////////////////////////////////
std::string ClassFileMakerTest::createExpectedHeader( std::string className ){
	std::string label(className);
	std::string headerSkeleton("");

	transform(label.begin(), label.end(), label.begin(), ::toupper);
	label += "_H_";
	headerSkeleton = "/**\n";
	headerSkeleton += " * " + className + ".h<br>\n";
	headerSkeleton += " * Copyright\n";
	headerSkeleton += " *\n";
	headerSkeleton += " */\n";
	headerSkeleton += "\n";
	headerSkeleton += "#ifndef " + label + "\n";
	headerSkeleton += "#define " + label + "\n";
	headerSkeleton += "\n";
	headerSkeleton += "class " + className + " {\n";
	headerSkeleton += " public:\n";
	headerSkeleton += "  //! Constractor\n";
	headerSkeleton += "  " + className + "();\n";
	headerSkeleton += "  //! Destructor\n";
	headerSkeleton += "  virtual ~" + className + "();\n";
	headerSkeleton += "\n";
	headerSkeleton += " protected:\n";
	headerSkeleton += " private:\n";
	headerSkeleton += "};\n";
	headerSkeleton += "\n";
	headerSkeleton += "#endif  // " + label + "\n";

	return headerSkeleton;
}

