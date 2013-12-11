/**
 * TestClassFileMakerForCSpy.h
 *
 *  Created on: 2013/09/28
 *      Author: furukawayoshihiro
 */

#ifndef TESTCLASSFILEMAKERFORCSPY_H_
#define TESTCLASSFILEMAKERFORCSPY_H_

#include <string>

#include "TestClassFileMakerForC.h"

class TestClassFileMakerForCSpy : public TestClassFileMakerForC {
private:
	TestClassFileMakerForCSpy();
public:
	TestClassFileMakerForCSpy(std::string name);
	virtual ~TestClassFileMakerForCSpy();
	const std::string getHeaderName() const;
	const std::string getHeaderSkeleton() const;
	const std::string getCppSkeleton() const;
	const IOutputter* getOutputter() const;
};

#endif /* TESTCLASSFILEMAKERFORCSPY_H_ */
