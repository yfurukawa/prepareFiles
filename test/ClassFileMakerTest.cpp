/*
 * ClassFileMakerTest.cpp
 *
 *  Created on: 2013/08/13
 *      Author: furukawayoshihiro
 */

#include "ClassFileMakerTest.h"

ClassFileMakerTest::ClassFileMakerTest() : sut(NULL){
	// TODO �����������ꂽ�R���X�g���N�^�[�E�X�^�u

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
