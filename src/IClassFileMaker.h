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

using namespace std;

class IClassFileMaker {
public:
	virtual ~IClassFileMaker();
	IClassFileMaker();
	void createClassFile();
	virtual const std::string getClassName() = 0;
	virtual const std::string getName() = 0;

private:
	virtual void createHeaderFile() = 0;
	virtual void createImplementsFile() = 0;
};

#endif /* ICLASSFILEMAKER_H_ */
