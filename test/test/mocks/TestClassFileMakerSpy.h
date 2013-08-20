/*
 * TestClassFileMakerSpy.h
 *
 *  Created on: 2013/08/14
 *      Author: furukawayoshihiro
 */

#ifndef TESTCLASSFILEMAKERSPY_H_
#define TESTCLASSFILEMAKERSPY_H_

#include "TestClassFileMaker.h"

class TestClassFileMakerSpy: public TestClassFileMaker {
private:
	TestClassFileMakerSpy();
public:
	TestClassFileMakerSpy( std::string name );
	virtual ~TestClassFileMakerSpy();
	const std::string getHeaderName();
	std::string getHeaderSkeleton();
	std::string getCppSkeleton();
	IOutputter* getOutputter();
};

#endif /* TESTCLASSFILEMAKERSPY_H_ */
