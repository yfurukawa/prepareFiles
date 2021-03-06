/**
 * CommandLineArgumentsParser.cpp
 *
 *  Created on: 2013/08/14
 *      Author: furukawayoshihiro
 */

#include "CommandLineArgumentsParser.h"
#include <iostream>
CommandLineArgumentsParser::CommandLineArgumentsParser() : language_("cpp"), targetName_("a.out"), needToCreateMakefile_(true) {
	// TODO �����������ꂽ�R���X�g���N�^�[�E�X�^�u

}

CommandLineArgumentsParser::~CommandLineArgumentsParser() {
	// TODO Auto-generated destructor stub
}

void CommandLineArgumentsParser::parseArguments(int argc, char** argv) throw (std::invalid_argument){

	if( !isArgumentEnough(argc) ) {
		throw std::invalid_argument("It is necessary to contain Class name.");
	}
	if( isContainLanguageSettingMultiple(argc, argv) ) {
		throw std::invalid_argument("Language Setting is contained once in arguments.");
	}
	if( isThereUnkownOption(argc, argv) ) {
		throw std::invalid_argument("Unknown Options are there.");
	}

	for(int i = 1; i < argc; ++i) {
		std::string argument(argv[i]);
		if( isOption(argument) ){
			parseOption(argument);
		}
		else {
			className_.push_back(argv[i]);
		}
	}

//	return className_;
}

std::string CommandLineArgumentsParser::getLanguage() {
	return language_;
}

std::string CommandLineArgumentsParser::getTargetName() {
	return targetName_;
}

std::vector<std::string> CommandLineArgumentsParser::getClassName() {
	return className_;
}

const bool CommandLineArgumentsParser::isNecessaryToCreateMakefile() const {
	return needToCreateMakefile_;
}

//////////////////////////////////////////////////////////////////////////////////////////
bool CommandLineArgumentsParser::isArgumentEnough(int argc) {
	return argc >= 2;
}

bool CommandLineArgumentsParser::isContainLanguageSettingMultiple(int argc, char** argv) {
	int count(0);

	for(int i = 1; i < argc; ++i) {
		std::string argument(argv[i]);
		if ( isLanguageCpp(argument) || isLanguageC(argument) ) {
			++count;
		}
	}
	return count>=2?true:false;
}

bool CommandLineArgumentsParser::isThereUnkownOption(int argc, char** argv) {
	bool result(false);

	for(int i = 1; i < argc; ++i) {
		std::string argument(argv[i]);
		if( isOption(argument) ) {
			result = result || !isCorrectOption( argument );
		}
	}
	return result;
}

bool CommandLineArgumentsParser::isOption(std::string argument) {
	return argument.find("--", 0) == 0;
}

bool CommandLineArgumentsParser::isCorrectOption(std::string argument) {
	return false || isLanguageCpp(argument)
			|| isLanguageC(argument)
			|| isTargetNameOption(argument)
			|| isMakefileCreatingOption(argument)
			|| isAppendOption(argument);
}

bool CommandLineArgumentsParser::isMakefileCreatingOption(std::string argument) {
	return argument.compare("--without_Makefile") == 0;
}

void CommandLineArgumentsParser::parseOption(std::string argument) {
	if ( isLanguageCpp(argument) ) {
		language_ = "cpp";
	}
	else if( isLanguageC(argument) ) {
		language_ = "c";
	}
	else if( isTargetNameOption(argument) ) {
		targetName_ = argument.substr(argument.find("=")+1);
	}
	else if( isMakefileCreatingOption(argument) ) {
		needToCreateMakefile_ = false;
	}
}

bool CommandLineArgumentsParser::isLanguageCpp(std::string argument) {
	return argument.compare("--lang=cpp") == 0;
}

bool CommandLineArgumentsParser::isLanguageC(std::string argument) {
	return argument.compare("--lang=c") == 0;
}

bool CommandLineArgumentsParser::isTargetNameOption(std::string argument) {
	return argument.compare(0, 9, "--target=") == 0;
}

bool CommandLineArgumentsParser::isAppendOption(std::string argument) {
	return argument.compare("--append") == 0;
}

