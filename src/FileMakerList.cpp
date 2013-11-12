/**
 * FileMakerList.cpp
 *
 *  Created on: 2013/08/15
 *      Author: furukawayoshihiro
 */

#include "FileMakerList.h"
#include "ClassFileMaker.h"

FileMakerList::FileMakerList() {
	// TODO

}

FileMakerList::~FileMakerList() {
	// TODO Auto-generated destructor stub
	destroyClassList();
	destroyTestClassList();
}

void FileMakerList::addClass(IClassFileMaker* fileMaker) {
	classFileMaker_.push_back(fileMaker);
}

void FileMakerList::addTestClass(IClassFileMaker* fileMaker) {
	testClassFileMaker_.push_back(fileMaker);
}

void FileMakerList::createFiles() {
	conductToCreate(classFileMaker_);
	conductToCreate(testClassFileMaker_);
}

std::string FileMakerList::getClassFileList() {
	return executeMethodIterativery( classFileMaker_, &IClassFileMaker::getClassName );
}

std::string FileMakerList::getObjectFileList() {
	return executeMethodIterativery( classFileMaker_, &IClassFileMaker::getObjectName );
}

std::string FileMakerList::getTestClassFileList() {
	return executeMethodIterativery( testClassFileMaker_, &IClassFileMaker::getClassName );
}

std::string FileMakerList::getTestObjectFileList() {
	return executeMethodIterativery( testClassFileMaker_, &IClassFileMaker::getObjectName );
}

//////////////////////////////////////////////////////////////
void FileMakerList::destroyClassList() {
	destroyList(classFileMaker_);
}

void FileMakerList::destroyTestClassList() {
	destroyList(testClassFileMaker_);
}

void FileMakerList::destroyList(std::vector<IClassFileMaker*>& list) {
	for( std::vector<IClassFileMaker*>::iterator itr = list.begin();
			itr != list.end(); ++itr ) {
		delete *itr;
	}
	list.clear();
}

void FileMakerList::conductToCreate(std::vector<IClassFileMaker*>& list) {
	for( std::vector<IClassFileMaker*>::iterator itr = list.begin();
			itr != list.end(); ++itr ) {
		(*itr)->createFiles();
	}
}

std::string FileMakerList::executeMethodIterativery( std::vector<IClassFileMaker*> fileMaker, PFUNC func ) {
	std::string list("");
	for( std::vector<IClassFileMaker*>::iterator itr = fileMaker.begin(); itr != fileMaker.end(); ++itr ) {
		list += ((*itr)->*func)();
		list += " ";
	}
	return list;
}

