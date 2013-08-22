/*
 * CommandLineArgumentsParser.cpp
 *
 *  Created on: 2013/08/14
 *      Author: furukawayoshihiro
 */

#include "CommandLineArgumentsParser.h"

CommandLineArgumentsParser::CommandLineArgumentsParser() {
	// TODO 自動生成されたコンストラクター・スタブ

}

CommandLineArgumentsParser::~CommandLineArgumentsParser() {
	// TODO Auto-generated destructor stub
}

std::vector<std::string> CommandLineArgumentsParser::parseArguments(int argc, char** argv) throw (std::invalid_argument){

	if( !isArgumentEnough(argc) || !isContainSwitch(argc, argv)) {
		throw std::invalid_argument("Arguments are ");
	}

	for(int i = 2; i < argc; ++i) {
		className_.push_back(argv[i]);
	}

	return className_;

}

//////////////////////////////////////////////////////////////////
bool CommandLineArgumentsParser::isArgumentEnough(int argc) {
	return argc >= 3;
}

bool CommandLineArgumentsParser::isContainSwitch(int argc, char** argv) {
	bool result(false);
	for(int i = 1; i < argc; ++i) {
		std::string argument(argv[i]);
		if ( (argument.compare("-cpp") == 0) || (argument.compare("-c") == 0) ) {
			result = result?false:true;
		}
	}
	return result;
}
