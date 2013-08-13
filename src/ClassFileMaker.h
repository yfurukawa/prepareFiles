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
protected:
	const std::string name_;
	const std::string className_;
	const std::string headerName_;

protected:
	ClassFileMaker();

public:
	ClassFileMaker( std::string name );
	virtual ~ClassFileMaker();
	virtual const std::string getClassName();
	virtual const std::string getName();

private:
	virtual void createHeaderFile();
	virtual void createImplementsFile();
};

#endif /* CLASSFILEMAKER_H_ */
