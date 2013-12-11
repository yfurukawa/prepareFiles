/**
 * FileMakerListSpy.h
 *
 *  Created on: 2013/08/15
 *      Author: furukawayoshihiro
 */

#ifndef FILEMAKERLISTSPY_H_
#define FILEMAKERLISTSPY_H_

#include "FileMakerList.h"

class FileMakerListSpy: public FileMakerList {
private:
	unsigned int numberOfCall_;
public:
	FileMakerListSpy();
	virtual ~FileMakerListSpy();
	IClassFileMaker* getClassFileMaker();
	IClassFileMaker* getTestClassFileMaker();
	const int getNumberOfClassFileMaker();
	const int getNumberOfTestClassFileMaker();
	void destroyClassList();
	void destroyTestClassList();
};

#endif /* FILEMAKERLISTSPY_H_ */
