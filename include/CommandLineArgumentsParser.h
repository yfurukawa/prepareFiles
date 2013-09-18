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
	bool isContainLanguageSettingMultiple(int argc, char** argv);
	bool isThereUnkownOption(int argc, char** argv);
	bool isOption(std::string argument);
	bool isCorrectOption(std::string argument);
};

#endif /* COMMANDLINEARGUMENTSPARSER_H_ */
