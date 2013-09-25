/*
 * CommandLineArgumentsParserMock.h
 *
 *  Created on: 2013/09/25
 *      Author: furukawayoshihiro
 */

#ifndef COMMANDLINEARGUMENTSPARSERMOCK_H_
#define COMMANDLINEARGUMENTSPARSERMOCK_H_

#include <vector>
#include "CommandLineArgumentsParser.h"

class CommandLineArgumentsParserMock: public CommandLineArgumentsParser {
public:
	CommandLineArgumentsParserMock();
	virtual ~CommandLineArgumentsParserMock();
//	std::vector<std::string> getClassName();
};

#endif /* COMMANDLINEARGUMENTSPARSERMOCK_H_ */
