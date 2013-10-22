/*
 * IClassFileMaker.h
 *
 *  Created on: 2013/08/13
 *      Author: furukawayoshihiro
 */

#ifndef ICLASSFILEMAKER_H_
#define ICLASSFILEMAKER_H_

#include <string>
#include <iostream>
#include <algorithm>

#include "IOutputter.h"

using namespace std;

class IClassFileMaker {
protected:
//	IOutputter* outputter_;

public:
	virtual ~IClassFileMaker();
	IClassFileMaker();
	virtual void createFiles() = 0;
	virtual const std::string getClassName() const = 0;
	virtual const std::string getName() const = 0;
	virtual const std::string getObjectName() const = 0;
	virtual void setOutputter(IOutputter* outputter) = 0;

private:
	virtual void createHeaderFile() = 0;
	virtual void createImplementsFile() = 0;
};

#endif /* ICLASSFILEMAKER_H_ */
