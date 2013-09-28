/*
 * TestClassFileMakerForC.h
 *
 *  Created on: 2013/09/28
 *      Author: furukawayoshihiro
 */

#ifndef TESTCLASSFILEMAKERFORC_H_
#define TESTCLASSFILEMAKERFORC_H_

#include <string>

#include "IClassFileMaker.h"

class TestClassFileMakerForC: public IClassFileMaker {
protected:
	const std::string name_;
	const std::string testTargetClassName_;
	const std::string moduleName_;
	const std::string headerName_;
	const std::string objectName_;
	std::string headerSkeleton_;
	std::string cSkeleton_;
	IOutputter* outputter_;

protected:
	TestClassFileMakerForC();
public:
	TestClassFileMakerForC(std::string name);
	virtual ~TestClassFileMakerForC();
	virtual void createFiles();
	virtual const std::string getClassName() const;
	virtual const std::string getName() const;
	virtual const std::string getObjectName() const;
	virtual void setOutputter(IOutputter* outputter);

private:
	virtual void createHeaderFile();
	virtual void createImplementsFile();
	bool isOutputterSet();
};

#endif /* TESTCLASSFILEMAKERFORC_H_ */
