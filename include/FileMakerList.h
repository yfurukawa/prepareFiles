/*
 * FileMakerList.h
 *
 *  Created on: 2013/08/15
 *      Author: furukawayoshihiro
 */

#ifndef FILEMAKERLIST_H_
#define FILEMAKERLIST_H_

#include <vector>
#include "IClassFileMaker.h"

class FileMakerList {
private:
	void destroyList( std::vector<IClassFileMaker*>& list );
	void conductToCreate( std::vector<IClassFileMaker*>& list );
protected:
	std::vector<IClassFileMaker*> classFileMaker_;
	std::vector<IClassFileMaker*> testClassFileMaker_;
	void destroyClassList();
	void destroyTestClassList();
public:
	FileMakerList();
	virtual ~FileMakerList();
	void addClass(IClassFileMaker* fileMaker);
	void addTestClass(IClassFileMaker* fileMaker);
	void createFiles();
};

#endif /* FILEMAKERLIST_H_ */
