/*
 * FileMakerList.cpp
 *
 *  Created on: 2013/08/15
 *      Author: furukawayoshihiro
 */

#include "FileMakerList.h"

FileMakerList::FileMakerList() {
	// TODO 自動生成されたコンストラクター・スタブ

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
