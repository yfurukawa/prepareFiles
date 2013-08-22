/*
 * CommandLineArgumentsParser.h
 *
 *  Created on: 2013/08/14
 *      Author: furukawayoshihiro
 */

#ifndef COMMANDLINEARGUMENTSPARSER_H_
#define COMMANDLINEARGUMENTSPARSER_H_

#include <string>
#include <vector>
#include <stdexcept>

class CommandLineArgumentsParser {
protected:
	std::vector<std::string>(className_);
public:
	CommandLineArgumentsParser();
	virtual ~CommandLineArgumentsParser();
	std::vector<std::string> parseArguments(int argc, char** argv) throw (std::invalid_argument);

private:
	bool isArgumentEnough(int argc);
	bool isContainSwitch(int argc, char** argv);
};

#endif /* COMMANDLINEARGUMENTSPARSER_H_ */
