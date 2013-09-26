/*
 * MakefileCreatorFactoryTest.cpp
 *
 *  Created on: 2013/09/26
 *      Author: furukawayoshihiro
 */

#include <typeinfo>

#include "MakefileCreatorFactoryTest.h"
#include "mocks/CommandLineArgumentsParserMock.h"
#include "IMakefileCreator.h"

MakefileCreatorFactoryTest::MakefileCreatorFactoryTest() : sut(NULL) {
	// TODO 自動生成されたコンストラクター・スタブ

}

MakefileCreatorFactoryTest::~MakefileCreatorFactoryTest() {
	// TODO Auto-generated destructor stub
	delete sut;
}

TEST_F(MakefileCreatorFactoryTest, createMakefileCreator) {
	CommandLineArgumentsParserMock mock;
	char* argv[] = {(char*)"command", (char*)"Hoge"};
	mock.parseArguments(2, argv);
	sut = new MakefileCreatorFactory(&mock);

	IMakefileCreator* actual = sut->createMakefileCreator();
	EXPECT_EQ(typeid(IMakefileCreator*), typeid(actual));
}
