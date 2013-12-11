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

typedef std::string const (IClassFileMaker::*PFUNC)() const;

class FileMakerList {
private:
	void destroyList( std::vector<IClassFileMaker*>& list );
	void conductToCreate( std::vector<IClassFileMaker*>& list );
	std::string executeMethodIterativery( std::vector<IClassFileMaker*>& fileMaker, PFUNC func );
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
	std::string getClassFileList();
	std::string getObjectFileList();
	std::string getTestClassFileList();
	std::string getTestObjectFileList();
};

#endif /* FILEMAKERLIST_H_ */
