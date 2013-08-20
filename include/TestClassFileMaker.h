/*
 * TestClassFileMaker.h
 *
 *  Created on: 2013/08/14
 *      Author: furukawayoshihiro
 */

#ifndef TESTCLASSFILEMAKER_H_
#define TESTCLASSFILEMAKER_H_

#include "IClassFileMaker.h"

class TestClassFileMaker: public IClassFileMaker {
protected:
	const std::string name_;
	const std::string testTargetClassName_;
	const std::string className_;
	const std::string headerName_;
	std::string headerSkeleton_;
	std::string cppSkeleton_;
	IOutputter* outputter_;

protected:
	TestClassFileMaker();
public:
	TestClassFileMaker( std::string name );
	virtual ~TestClassFileMaker();
	virtual void createFiles();
	virtual const std::string getClassName();
	virtual const std::string getName();
	virtual void setOutputter(IOutputter* outputter);

private:
	virtual void createHeaderFile();
	virtual void createImplementsFile();
	bool isOutputterSet();
};

#endif /* TESTCLASSFILEMAKER_H_ */
