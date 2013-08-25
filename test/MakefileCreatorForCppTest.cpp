/*
 * MakefileMakerForCppTest.cpp
 *
 *  Created on: 2013/08/24
 *      Author: furukawayoshihiro
 */

#include "MakefileCreatorForCppTest.h"
//#include "mocks/MakefileCreatorForCppSpy.h"
#include "mocks/OutputterMock.h"

MakefileCreatorForCppTest::MakefileCreatorForCppTest() {
	// TODO 自動生成されたコンストラクター・スタブ
	sut = new MakefileCreatorForCppSpy();
}

MakefileCreatorForCppTest::~MakefileCreatorForCppTest() {
	// TODO Auto-generated destructor stub
	delete sut;
}

TEST_F(MakefileCreatorForCppTest, setOutputter) {
	IOutputter* outputter = new OutputterMock();
	sut->setOutputter( outputter );

	EXPECT_EQ(outputter, sut->getOutputter());
}
