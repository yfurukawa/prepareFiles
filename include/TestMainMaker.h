/*
 * TestMainMaker.h
 *
 *  Created on: 2013/09/22
 *      Author: furukawayoshihiro
 */

#ifndef TESTMAINMAKER_H_
#define TESTMAINMAKER_H_

#include "IClassFileMaker.h"

class TestMainMaker: public IClassFileMaker {
public:
	TestMainMaker();
	virtual ~TestMainMaker();
	virtual void createFiles();
	virtual const std::string getClassName() const;
	virtual const std::string getName() const;
	virtual const std::string getObjectName() const;
	virtual void setOutputter(IOutputter* outputter);

private:
	virtual void createHeaderFile();
	virtual void createImplementsFile();
};

#endif /* TESTMAINMAKER_H_ */
