/*
 * CommandLineArgumentsParser.cpp
 *
 *  Created on: 2013/08/14
 *      Author: furukawayoshihiro
 */

#include "CommandLineArgumentsParser.h"
#include <iostream>
CommandLineArgumentsParser::CommandLineArgumentsParser() {
	// TODO 自動生成されたコンストラクター・スタブ

}

CommandLineArgumentsParser::~CommandLineArgumentsParser() {
	// TODO Auto-generated destructor stub
}

std::vector<std::string> CommandLineArgumentsParser::parseArguments(int argc, char** argv) throw (std::invalid_argument){

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
		if( !isOption(argument) ){
			className_.push_back(argv[i]);
		}
	}

	return className_;

}

//////////////////////////////////////////////////////////////////
bool CommandLineArgumentsParser::isArgumentEnough(int argc) {
	return argc >= 2;
}

bool CommandLineArgumentsParser::isContainLanguageSettingMultiple(int argc, char** argv) {
	int count(0);

	for(int i = 1; i < argc; ++i) {
		std::string argument(argv[i]);
		if ( (argument.compare("--lang=cpp") == 0) || (argument.compare("--lang=c") == 0) ) {
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
	return (argument.compare("--lang=cpp") == 0) || (argument.compare("--lang=c") == 0) || (argument.compare(0, 9, "--target=") == 0);
}
