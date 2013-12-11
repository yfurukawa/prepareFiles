/**
 * TestMainMakerSpy.h
 *
 *  Created on: 2013/09/22
 *      Author: furukawayoshihiro
 */

#ifndef TESTMAINMAKERSPY_H_
#define TESTMAINMAKERSPY_H_

#include "TestMainMaker.h"

class TestMainMakerSpy: public TestMainMaker {
public:
	TestMainMakerSpy();
	virtual ~TestMainMakerSpy();
	const std::string getCppSkeleton() const;
	const IOutputter* getOutputter() const;
};

#endif /* TESTMAINMAKERSPY_H_ */
