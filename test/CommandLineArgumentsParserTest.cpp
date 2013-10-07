/*
 * CommandLineArgumentsParserTest.cpp
 *
 *  Created on: 2013/08/14
 *      Author: furukawayoshihiro
 */

#include <stdexcept>
#include <vector>
#include "CommandLineArgumentsParserTest.h"

CommandLineArgumentsParserTest::CommandLineArgumentsParserTest() : sut(NULL) {
	// TODO

}

void CommandLineArgumentsParserTest::SetUp() {
	sut = new CommandLineArgumentsParser();
}

void CommandLineArgumentsParserTest::TearDown() {
	delete sut;
}

CommandLineArgumentsParserTest::~CommandLineArgumentsParserTest() {
	// TODO Auto-generated destructor stub
}

TEST_F(CommandLineArgumentsParserTest, exceptionThrowWhenArgumentsIsCommandOnly) {
	int argc(1);
	char* argv[] = {(char*)"prepareFiles"};

	ASSERT_THROW(sut->parseArguments(argc, argv), std::invalid_argument);
	try{
		sut->parseArguments(argc, argv);
	}
	catch(std::invalid_argument& e) {
		std::string actual = e.what();
		EXPECT_EQ("It is necessary to contain Class name.", actual);
	}
}

TEST_F(CommandLineArgumentsParserTest, exceptionThrowWhenLanguageSettingIsDuplicated) {
	int argc(3);
	char* argv[] = {(char*)"prepareFiles", (char*)"--lang=cpp", (char*)"--lang=c"};

	ASSERT_THROW(sut->parseArguments(argc, argv), std::invalid_argument);
	try{
		sut->parseArguments(argc, argv);
	}
	catch(std::invalid_argument& e) {
		std::string actual = e.what();
		EXPECT_EQ("Language Setting is contained once in arguments.", actual);
	}
}

TEST_F(CommandLineArgumentsParserTest, exceptionThrowWhenUnknownOptionsAreThere) {
	int argc(3);
	char* argv[] = {(char*)"prepareFiles", (char*)"--unknownOption", (char*)"Hoge"};

	ASSERT_THROW(sut->parseArguments(argc, argv), std::invalid_argument);
	try{
		sut->parseArguments(argc, argv);
	}
	catch(std::invalid_argument& e) {
		std::string actual = e.what();
		EXPECT_EQ("Unknown Options are there.", actual);
	}
}

TEST_F(CommandLineArgumentsParserTest, noExceptionThrowWhenLanguageSettingIsNOTExsist) {
	int argc(2);
	char* argv[] = {(char*)"prepareFiles", (char*)"Hoge"};

	EXPECT_NO_THROW(sut->parseArguments(argc, argv));
	try {
		sut->parseArguments(argc, argv);
	}
	catch(std::invalid_argument& e) {
		std::cout << e.what() << std::endl;
		FAIL();
	}
}

TEST_F(CommandLineArgumentsParserTest, noExceptionThrowWhenArgumentContainAClassNameWithLanguageSettingOfCpp) {
	int argc(3);
	char* argv[] = {(char*)"prepareFiles", (char*)"--lang=cpp", (char*)"Hoge"};

	EXPECT_NO_THROW(sut->parseArguments(argc, argv));
	try {
		sut->parseArguments(argc, argv);
	}
	catch(std::invalid_argument& e) {
		std::cout << e.what() << std::endl;
		FAIL();
	}
}

TEST_F(CommandLineArgumentsParserTest, noExceptionThrowWhenArgumentContainAClassNameWithLanguageSettingOfC) {
	int argc(3);
	char* argv[] = {(char*)"prepareFiles", (char*)"--lang=c", (char*)"Hoge"};

	EXPECT_NO_THROW(sut->parseArguments(argc, argv));
}

TEST_F(CommandLineArgumentsParserTest, noExceptionThrowWhenArgumentContainAClassNameWithTragetSetting) {
	int argc(3);
	char* argv[] = {(char*)"prepareFiles", (char*)"--target=sampleTarget", (char*)"Hoge"};

	EXPECT_NO_THROW(sut->parseArguments(argc, argv));
}

TEST_F(CommandLineArgumentsParserTest, pickUpAClassNameFromArgument) {
	int argc(3);
	char* argv[] = {(char*)"prepareFiles", (char*)"--lang=cpp", (char*)"Hoge"};
	sut->parseArguments(argc, argv);

	std::vector<std::string> className;
	className = sut->getClassName();
	ASSERT_EQ(1, className.size());
	EXPECT_EQ("Hoge", className[0]);
}

TEST_F(CommandLineArgumentsParserTest, pickUpSomeClassNamesFromArgumentWithLanguageSetting) {
	int argc(5);
	char* argv[] = {(char*)"prepareFiles", (char*)"--lang=cpp", (char*)"Hoge", (char*)"Fuga", (char*)"Foo"};
	sut->parseArguments(argc, argv);

	std::vector<std::string> className;
	className = sut->getClassName();
	ASSERT_EQ(3, className.size());
	EXPECT_EQ("Hoge", className[0]);
	EXPECT_EQ("Fuga", className[1]);
	EXPECT_EQ("Foo", className[2]);
}

TEST_F(CommandLineArgumentsParserTest, pickUpSomeClassNamesFromArgumentWithoutLanguageSetting) {
	int argc(4);
	char* argv[] = {(char*)"prepareFiles", (char*)"Hoge", (char*)"Fuga", (char*)"Foo"};
	sut->parseArguments(argc, argv);

	std::vector<std::string> className;
	className = sut->getClassName();
	ASSERT_EQ(3, className.size());
	EXPECT_EQ("Hoge", className[0]);
	EXPECT_EQ("Fuga", className[1]);
	EXPECT_EQ("Foo", className[2]);
}

TEST_F(CommandLineArgumentsParserTest, pickUpSomeClassNamesFromArgumentWithTragetSetting) {
	int argc(5);
	char* argv[] = {(char*)"prepareFiles", (char*)"--target=sampleTarget", (char*)"Hoge", (char*)"Fuga", (char*)"Foo"};
	sut->parseArguments(argc, argv);

	std::vector<std::string> className;
	className = sut->getClassName();
	ASSERT_EQ(3, className.size());
	EXPECT_EQ("Hoge", className[0]);
	EXPECT_EQ("Fuga", className[1]);
	EXPECT_EQ("Foo", className[2]);
}

TEST_F(CommandLineArgumentsParserTest, pickUpSomeClassNamesFromArgumentWithLanguageAndTargetSetting) {
	int argc(6);
	char* argv[] = {(char*)"prepareFiles", (char*)"--lang=cpp", (char*)"--target=sampleTarget", (char*)"Hoge", (char*)"Fuga", (char*)"Foo"};
	sut->parseArguments(argc, argv);

	std::vector<std::string> className;
	className = sut->getClassName();
	ASSERT_EQ(3, className.size());
	EXPECT_EQ("Hoge", className[0]);
	EXPECT_EQ("Fuga", className[1]);
	EXPECT_EQ("Foo", className[2]);
}

TEST_F(CommandLineArgumentsParserTest, pickUpSomeClassNamesFromArgumentWithTragetAndLanguageSetting) {
	int argc(6);
	char* argv[] = {(char*)"prepareFiles", (char*)"--target=sampleTarget", (char*)"--lang=cpp", (char*)"Hoge", (char*)"Fuga", (char*)"Foo"};
	sut->parseArguments(argc, argv);

	std::vector<std::string> className;
	className = sut->getClassName();
	ASSERT_EQ(3, className.size());
	EXPECT_EQ("Hoge", className[0]);
	EXPECT_EQ("Fuga", className[1]);
	EXPECT_EQ("Foo", className[2]);
}

TEST_F(CommandLineArgumentsParserTest, pickUpTargetLanguageCppFromArgument) {
	int argc(6);
	char* argv[] = {(char*)"prepareFiles", (char*)"--target=sampleTarget", (char*)"--lang=cpp", (char*)"Hoge", (char*)"Fuga", (char*)"Foo"};

	sut->parseArguments(argc, argv);

	EXPECT_EQ("cpp", sut->getLanguage());
}

TEST_F(CommandLineArgumentsParserTest, pickUpTargetLanguageCFromArgument) {
	int argc(6);
	char* argv[] = {(char*)"prepareFiles", (char*)"--target=sampleTarget", (char*)"--lang=c", (char*)"Hoge", (char*)"Fuga", (char*)"Foo"};

	sut->parseArguments(argc, argv);

	EXPECT_EQ("c", sut->getLanguage());
}

TEST_F(CommandLineArgumentsParserTest, pickUpTargetNameSampleTargetFromArgument) {
	int argc(6);
	char* argv[] = {(char*)"prepareFiles", (char*)"--target=sampleTarget", (char*)"--lang=c", (char*)"Hoge", (char*)"Fuga", (char*)"Foo"};

	sut->parseArguments(argc, argv);

	EXPECT_EQ("sampleTarget", sut->getTargetName());
}

TEST_F(CommandLineArgumentsParserTest, pickUpTargetNameTargetNameFromArgument) {
	int argc(6);
	char* argv[] = {(char*)"prepareFiles", (char*)"--target=targetName", (char*)"--lang=c", (char*)"Hoge", (char*)"Fuga", (char*)"Foo"};

	sut->parseArguments(argc, argv);

	EXPECT_EQ("targetName", sut->getTargetName());
}

TEST_F(CommandLineArgumentsParserTest, pickUpDefaultTargetName) {
	int argc(5);
	char* argv[] = {(char*)"prepareFiles", (char*)"--lang=c", (char*)"Hoge", (char*)"Fuga", (char*)"Foo"};

	sut->parseArguments(argc, argv);

	EXPECT_EQ("a.out", sut->getTargetName());
}

TEST_F(CommandLineArgumentsParserTest, pickUpDefaultLanguageSettings) {
	int argc(4);
	char* argv[] = {(char*)"prepareFiles", (char*)"Hoge", (char*)"Fuga", (char*)"Foo"};

	sut->parseArguments(argc, argv);

	EXPECT_EQ("cpp", sut->getLanguage());
}

TEST_F(CommandLineArgumentsParserTest, ItIsNecessaryToCreateWhenNoCommandLineOption) {
	int argc(4);
	char* argv[] = {(char*)"prepareFiles", (char*)"Hoge", (char*)"Fuga", (char*)"Foo"};

	try{
		sut->parseArguments(argc, argv);
		EXPECT_EQ(true, sut->isNecessaryToCreateMakefile());
	}
	catch(std::invalid_argument& e) {
		std::string actual = e.what();
		FAIL() << "We should NOT get here.";
	}

}

TEST_F(CommandLineArgumentsParserTest, ItIsNOTNecessaryToCreateWhenCommandLineOptionIsThere) {
	int argc(5);
	char* argv[] = {(char*)"prepareFiles", (char*)"--no_Makefile", (char*)"Hoge", (char*)"Fuga", (char*)"Foo"};

	try{
		sut->parseArguments(argc, argv);
		EXPECT_EQ(false, sut->isNecessaryToCreateMakefile());
	}
	catch(std::invalid_argument& e) {
		std::string actual = e.what();
		FAIL() << "We should NOT get here.";
	}

}
