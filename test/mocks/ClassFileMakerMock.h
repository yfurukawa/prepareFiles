/*
 * ClassFileMakerMock.h
 *
 *  Created on: 2013/08/16
 *      Author: furukawayoshihiro
 */

#ifndef CLASSFILEMAKERMOCK_H_
#define CLASSFILEMAKERMOCK_H_

#include "IClassFileMaker.h"

class ClassFileMakerMock: public IClassFileMaker {
private:
	unsigned int numberOfCretatedFiles_;
	virtual void createHeaderFile() {};
	virtual void createImplementsFile() {};
public:
	ClassFileMakerMock();
	virtual ~ClassFileMakerMock();
	virtual void createFiles();
	virtual const std::string getClassName() const { return ""; }
	virtual const std::string getName() const { return ""; }
	virtual const std::string getObjectName() const { return ""; }
	virtual void setOutputter(IOutputter* outputter) {};
	const unsigned int getNumberOfCreatedFile();
};

#endif /* CLASSFILEMAKERMOCK_H_ */
