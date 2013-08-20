/*
 * CommandLineArgumentsParser.cpp
 *
 *  Created on: 2013/08/14
 *      Author: furukawayoshihiro
 */

#include "CommandLineArgumentsParser.h"

CommandLineArgumentsParser::CommandLineArgumentsParser() {
	// TODO �����������ꂽ�R���X�g���N�^�[�E�X�^�u

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
