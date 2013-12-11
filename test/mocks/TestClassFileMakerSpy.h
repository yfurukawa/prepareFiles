/**
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
	const std::string getHeaderName() const;
	const std::string getHeaderSkeleton() const;
	const std::string getCppSkeleton() const;
	const IOutputter* getOutputter() const;
};

#endif /* TESTCLASSFILEMAKERSPY_H_ */
