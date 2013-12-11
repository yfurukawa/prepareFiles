/**
 * MakefileCreatorFactoryTest.cpp
 *
 *  Created on: 2013/09/26
 *      Author: furukawayoshihiro
 */

#include <typeinfo>

#include "MakefileCreatorFactoryTest.h"
#include "IMakefileCreator.h"

MakefileCreatorFactoryTest::MakefileCreatorFactoryTest() : sut(NULL), mock(NULL) {
	// TODO �����������ꂽ�R���X�g���N�^�[�E�X�^�u

}

MakefileCreatorFactoryTest::~MakefileCreatorFactoryTest() {
	// TODO Auto-generated destructor stub
	delete sut;
	delete mock;
}

TEST_F(MakefileCreatorFactoryTest, createMakefileCreator) {
	mock = new CommandLineArgumentsParserMock();
	char* argv[] = {(char*)"command", (char*)"Hoge"};
	mock->parseArguments(2, argv);
	sut = new MakefileCreatorFactory(mock);
	IMakefileCreator* actual = sut->createMakefileCreator();
	EXPECT_EQ(typeid(IMakefileCreator*), typeid(actual));
	EXPECT_EQ("MakefileCreatorForCpp", actual->getName());
}

TEST_F(MakefileCreatorFactoryTest, createMakefileCreator_c) {
	mock = new CommandLineArgumentsParserMock();
	char* argv[] = {(char*)"command", (char*)"--lang=c", (char*)"Hoge"};
	mock->parseArguments(3, argv);
	sut = new MakefileCreatorFactory(mock);
	IMakefileCreator* actual = sut->createMakefileCreator();
	EXPECT_EQ(typeid(IMakefileCreator*), typeid(actual));
	EXPECT_EQ("MakefileCreatorForC", actual->getName());
}
