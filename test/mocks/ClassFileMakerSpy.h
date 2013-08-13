/*
 * ClassFileMakerSpy.h
 *
 *  Created on: 2013/08/13
 *      Author: furukawayoshihiro
 */

#ifndef CLASSFILEMAKERSPY_H_
#define CLASSFILEMAKERSPY_H_

#include "ClassFileMaker.h"

class ClassFileMakerSpy: public ClassFileMaker {
private:
	ClassFileMakerSpy();
public:
	ClassFileMakerSpy(std::string name);
	virtual ~ClassFileMakerSpy();
	const std::string getHeaderName();
	std::string getHeaderSkeleton();
};

#endif /* CLASSFILEMAKERSPY_H_ */
