/*
 * ClassFileMakerFactoryTest.cpp
 *
 *  Created on: 2013/09/22
 *      Author: furukawayoshihiro
 */

#include <typeinfo>
#include "mocks/CommandLineArgumentsParserMock.h"
#include "ClassFileMakerFactoryTest.h"
#include "ClassFileMaker.h"
#include "FileMakerList.h"

ClassFileMakerFactoryTest::ClassFileMakerFactoryTest() : sut(NULL), mock(NULL) {
	// TODO 自動生成されたコンストラクター・スタブ
	char* argv[] = {(char*)"command", (char*)"Hoge"};
	mock = 	new CommandLineArgumentsParserMock();
	mock->parseArguments(2, argv);
	sut = new ClassFileMakerFactory(mock);
}

ClassFileMakerFactoryTest::~ClassFileMakerFactoryTest() {
	// TODO Auto-generated destructor stub
	delete sut;
	delete mock;
}

TEST_F(ClassFileMakerFactoryTest, createClassFileMaker_cpp) {
	FileMakerList list;
	sut->buildClassList(&list);
	EXPECT_EQ("Hoge.cpp ", list.getClassFileList());
}

TEST_F(ClassFileMakerFactoryTest, createTestClassFileMaker_cpp) {
	FileMakerList list;
	sut->buildClassList(&list);
	EXPECT_EQ("../test/HogeTest.cpp ", list.getTestClassFileList());
}

TEST_F(ClassFileMakerFactoryTest, createClassFileMaker_c) {
	delete mock;
	delete sut;
	char* argv[] = {(char*)"command", (char*)"--lang=c", (char*)"Hoge"};
	mock = 	new CommandLineArgumentsParserMock();
	mock->parseArguments(3, argv);
	sut = new ClassFileMakerFactory(mock);
	FileMakerList list;
	sut->buildClassList(&list);
	EXPECT_EQ("Hoge.c ", list.getClassFileList());
}
