/*
 * ClassFileMakerFactory.cpp
 *
 *  Created on: 2013/09/22
 *      Author: furukawayoshihiro
 */

#include "ClassFileMakerFactory.h"
#include "CommandLineArgumentsParser.h"
#include "ClassFileMaker.h"
#include "TestClassFileMaker.h"
#include "FileOutputter.h"
#include "FileMakerList.h"

ClassFileMakerFactory::ClassFileMakerFactory() : parser_(NULL) {
	// TODO

}

ClassFileMakerFactory::~ClassFileMakerFactory() {
	// TODO Auto-generated destructor stub
}

ClassFileMakerFactory::ClassFileMakerFactory(CommandLineArgumentsParser* parser) : parser_(parser) {
}

void ClassFileMakerFactory::buildClassList(FileMakerList* list){
	classes_ = parser_->getClassName();
	for(std::vector<std::string>::iterator classNameOfCreating = classes_.begin(); classNameOfCreating != classes_.end(); ++classNameOfCreating) {
		list->addClass(createFileMaker<ClassFileMaker>(*classNameOfCreating));
	}
	for(std::vector<std::string>::iterator classNameOfCreating = classes_.begin(); classNameOfCreating != classes_.end(); ++classNameOfCreating) {
		list->addTestClass(createFileMaker<TestClassFileMaker>(*classNameOfCreating));
	}
}

/////////////////////////////////////////////////////////////////////
template<typename T>
IClassFileMaker* ClassFileMakerFactory::createFileMaker(std::string name) {
	IClassFileMaker* fileMaker = new T(name);
	fileMaker->setOutputter(new FileOutputter());
	return fileMaker;
}

