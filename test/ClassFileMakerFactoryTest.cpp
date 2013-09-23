/*
 * ClassFileMakerFactoryTest.cpp
 *
 *  Created on: 2013/09/22
 *      Author: furukawayoshihiro
 */

#include <typeinfo>
#include "ClassFileMakerFactoryTest.h"
#include "ClassFileMaker.h"
#include "FileMakerList.h"

ClassFileMakerFactoryTest::ClassFileMakerFactoryTest() : sut(NULL) {
	// TODO 自動生成されたコンストラクター・スタブ
	char* argv[] = {(char*)"command", (char*)"Hoge"};
	sut = new ClassFileMakerFactory(2, argv);
}

ClassFileMakerFactoryTest::~ClassFileMakerFactoryTest() {
	// TODO Auto-generated destructor stub
	delete sut;
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

