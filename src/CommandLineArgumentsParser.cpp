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

	if( !isArgumentEnough(argc) ) {
		throw std::invalid_argument("Arguments are ");
	}

	for(int i = 1; i < argc; ++i) {
		className_.push_back(argv[i]);
	}

	return className_;

}

//////////////////////////////////////////////////////////////////
bool CommandLineArgumentsParser::isArgumentEnough(int argc) {
	return argc >= 2;
}
