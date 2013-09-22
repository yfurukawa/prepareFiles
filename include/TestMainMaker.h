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
};

#endif /* TESTMAINMAKER_H_ */
