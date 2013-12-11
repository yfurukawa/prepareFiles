/**
 * ClassFileMakerFactoryTest.h
 *
 *  Created on: 2013/09/22
 *      Author: furukawayoshihiro
 */

#ifndef CLASSFILEMAKERFACTORYTEST_H_
#define CLASSFILEMAKERFACTORYTEST_H_

#include <gtest/gtest.h>

#include "ClassFileMakerFactory.h"

class ClassFileMakerFactoryTest: public ::testing::Test {
protected:
	ClassFileMakerFactory* sut;
	CommandLineArgumentsParserMock* mock;
public:
	ClassFileMakerFactoryTest();
	virtual ~ClassFileMakerFactoryTest();
};

#endif /* CLASSFILEMAKERFACTORYTEST_H_ */
