/**
 * MakefileCreatorFactoryTest.h
 *
 *  Created on: 2013/09/26
 *      Author: furukawayoshihiro
 */

#ifndef MAKEFILECREATORFACTORYTEST_H_
#define MAKEFILECREATORFACTORYTEST_H_

#include <gtest/gtest.h>
#include "MakefileCreatorFactory.h"
#include "mocks/CommandLineArgumentsParserMock.h"

class MakefileCreatorFactoryTest: public ::testing::Test {
protected:
	MakefileCreatorFactory* sut;
	CommandLineArgumentsParserMock* mock;
public:
	MakefileCreatorFactoryTest();
	virtual ~MakefileCreatorFactoryTest();
};

#endif /* MAKEFILECREATORFACTORYTEST_H_ */
