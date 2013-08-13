/*
 * ClassFileMaker.h
 *
 *  Created on: 2013/08/13
 *      Author: furukawayoshihiro
 */

#ifndef CLASSFILEMAKER_H_
#define CLASSFILEMAKER_H_

#include "IClassFileMaker.h"

class ClassFileMaker: public IClassFileMaker {
private:
	std::string name_;

public:
	ClassFileMaker();
	ClassFileMaker( std::string name );
	virtual ~ClassFileMaker();
	virtual std::string getClassName();
	virtual std::string getName();

private:
	virtual void createHeaderFile();
	virtual void createImplementsFile();
};

#endif /* CLASSFILEMAKER_H_ */
