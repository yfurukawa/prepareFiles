/**
 * CommandLineArgumentsParserTest.h
 *
 *  Created on: 2013/08/14
 *      Author: furukawayoshihiro
 */

#ifndef COMMANDLINEARGUMENTSPARSERTEST_H_
#define COMMANDLINEARGUMENTSPARSERTEST_H_

#include <gtest/gtest.h>

#include "CommandLineArgumentsParser.h"

class CommandLineArgumentsParserTest: public ::testing::Test {
protected:
	CommandLineArgumentsParser* sut;
	void SetUp();
	void TearDown();
public:
	CommandLineArgumentsParserTest();
	virtual ~CommandLineArgumentsParserTest();
};

#endif /* COMMANDLINEARGUMENTSPARSERTEST_H_ */
