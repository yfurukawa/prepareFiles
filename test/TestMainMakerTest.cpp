/*
 * TestMainMakerTest.cpp
 *
 *  Created on: 2013/09/22
 *      Author: furukawayoshihiro
 */

#include "TestMainMakerTest.h"

TestMainMakerTest::TestMainMakerTest() : sut(NULL) {
	// TODO �����������ꂽ�R���X�g���N�^�[�E�X�^�u
	sut = new TestMainMaker();
}

TestMainMakerTest::~TestMainMakerTest() {
	// TODO Auto-generated destructor stub
}

TEST_F(TestMainMakerTest, createInstance) {
	EXPECT_EQ("testMain", sut->getName());
}
