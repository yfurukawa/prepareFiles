/*
 * CommandLineArgumentsParserTest.cpp
 *
 *  Created on: 2013/08/14
 *      Author: furukawayoshihiro
 */

#include <stdexcept>
#include <vector>
#include "CommandLineArgumentsParserTest.h"

CommandLineArgumentsParserTest::CommandLineArgumentsParserTest() {
	// TODO 自動生成されたコンストラクター・スタブ

}

void CommandLineArgumentsParserTest::SetUp() {
}

void CommandLineArgumentsParserTest::TearDown() {
}

CommandLineArgumentsParserTest::~CommandLineArgumentsParserTest() {
	// TODO Auto-generated destructor stub
}

TEST_F(CommandLineArgumentsParserTest, exceptionThrowWhenArgumentsIsCommandOnly) {
	int argc(1);
	char* argv[] = {(char*)"prepareFiles"};

	sut = new CommandLineArgumentsParser();

	EXPECT_THROW(sut->parseArguments(argc, argv), std::invalid_argument);
}

TEST_F(CommandLineArgumentsParserTest, exceptionThrowWhenSwitchIsNOTExsist) {
	int argc(2);
	char* argv[] = {(char*)"prepareFiles", (char*)"Hoge"};

	sut = new CommandLineArgumentsParser();

	EXPECT_THROW(sut->parseArguments(argc, argv), std::invalid_argument);
}

TEST_F(CommandLineArgumentsParserTest, exceptionThrowWhenSwitchIsDuplicated) {
	int argc(3);
	char* argv[] = {(char*)"prepareFiles", (char*)"-cpp", (char*)"-c"};

	sut = new CommandLineArgumentsParser();

	EXPECT_THROW(sut->parseArguments(argc, argv), std::invalid_argument);
}

TEST_F(CommandLineArgumentsParserTest, noExceptionThrowWhenArgumentContainAClassNameWithCppSwitch) {
	int argc(3);
	char* argv[] = {(char*)"prepareFiles", (char*)"-cpp", (char*)"Hoge"};

	sut = new CommandLineArgumentsParser();

	EXPECT_NO_THROW(sut->parseArguments(argc, argv));
}

TEST_F(CommandLineArgumentsParserTest, noExceptionThrowWhenArgumentContainAClassNameWithCSwitch) {
	int argc(3);
	char* argv[] = {(char*)"prepareFiles", (char*)"-c", (char*)"Hoge"};

	sut = new CommandLineArgumentsParser();

	EXPECT_NO_THROW(sut->parseArguments(argc, argv));
}

TEST_F(CommandLineArgumentsParserTest, pickUpAClassNameFromArgument) {
	int argc(3);
	char* argv[] = {(char*)"prepareFiles", (char*)"-cpp", (char*)"Hoge"};

	sut = new CommandLineArgumentsParser();

	std::vector<std::string> className;
	className = sut->parseArguments(argc, argv);
	ASSERT_EQ(1, className.size());
	EXPECT_EQ("Hoge", className[0]);
}

TEST_F(CommandLineArgumentsParserTest, pickUpSomeClassNamesFromArgument) {
	int argc(5);
	char* argv[] = {(char*)"prepareFiles", (char*)"-cpp", (char*)"Hoge", (char*)"Fuga", (char*)"Foo"};

	sut = new CommandLineArgumentsParser();

	std::vector<std::string> className;
	className = sut->parseArguments(argc, argv);
	ASSERT_EQ(3, className.size());
	EXPECT_EQ("Hoge", className[0]);
	EXPECT_EQ("Fuga", className[1]);
	EXPECT_EQ("Foo", className[2]);
}

