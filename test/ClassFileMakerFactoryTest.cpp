/*
 * ClassFileMakerFactoryTest.cpp
 *
 *  Created on: 2013/09/22
 *      Author: furukawayoshihiro
 */

#include <typeinfo>
#include "ClassFileMakerFactoryTest.h"
#include "ClassFileMaker.h"

ClassFileMakerFactoryTest::ClassFileMakerFactoryTest() : sut(NULL) {
	// TODO 自動生成されたコンストラクター・スタブ
	char* argv[] = {(char*)"command", (char*)"c"};
	sut = new ClassFileMakerFactory(2, argv);
}

ClassFileMakerFactoryTest::~ClassFileMakerFactoryTest() {
	// TODO Auto-generated destructor stub
	delete sut;
}

//TEST_F(ClassFileMakerFactoryTest, createClassFileMaker_cpp) {
//	IClassFileMaker* actual = sut->createClassFileMaker("Hoge");
//	EXPECT_EQ("Hoge", actual->getName());
//}
//
//TEST_F(ClassFileMakerFactoryTest, createTestClassFileMaker_cpp) {
//	IClassFileMaker* actual = sut->createTestClassFileMaker("Hoge");
//	EXPECT_EQ("HogeTest", actual->getName());
//}

