/*
 * ClassFileMakerTest.cpp
 *
 *  Created on: 2013/08/13
 *      Author: furukawayoshihiro
 */

#include "ClassFileMakerTest.h"
#include "mocks/ClassFileMakerSpy.h"

ClassFileMakerTest::ClassFileMakerTest() : sut(NULL){
	// TODO 自動生成されたコンストラクター・スタブ

}

void ClassFileMakerTest::SetUp() {
}

void ClassFileMakerTest::TearDown() {
	delete sut;
}

ClassFileMakerTest::~ClassFileMakerTest() {
	// TODO Auto-generated destructor stub
}

TEST_F(ClassFileMakerTest, createInstance) {
	sut = new ClassFileMaker("Hoge");
	EXPECT_EQ("Hoge", sut->getName());
}

TEST_F(ClassFileMakerTest, createClassFileName) {
	sut = new ClassFileMaker("Hoge");
	EXPECT_EQ("Hoge.cpp", sut->getClassName());
}

TEST_F(ClassFileMakerTest, createHeaderFileName) {
	ClassFileMakerSpy* spy = new ClassFileMakerSpy("Hoge");
	EXPECT_EQ("Hoge.h", spy->getHeaderName());
}

