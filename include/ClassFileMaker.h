/*
 * ClassFileMaker.h
 *
 *  Created on: 2013/08/13
 *      Author: furukawayoshihiro
 */

#ifndef CLASSFILEMAKER_H_
#define CLASSFILEMAKER_H_

#include <iostream>
#include "IClassFileMaker.h"
#include "IOutputter.h"

class ClassFileMaker: public IClassFileMaker {
protected:
	const std::string name_;
	const std::string className_;
	const std::string headerName_;
	std::string headerSkeleton_;
	std::string cppSkeleton_;
	IOutputter* outputter_;

protected:
	ClassFileMaker();

public:
	ClassFileMaker( std::string name );
	virtual ~ClassFileMaker();
	virtual void createFiles();
	virtual const std::string getClassName();
	virtual const std::string getName();
	virtual void setOutputter(IOutputter* outputter);

private:
	virtual void createHeaderFile();
	virtual void createImplementsFile();
	bool isOutputterSet();
};

#endif /* CLASSFILEMAKER_H_ */
