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
#include "IMakefileCreator.h"
#include "MakefileCreatorForCpp.h"

ClassFileMakerFactory::ClassFileMakerFactory() {
	// TODO �����������ꂽ�R���X�g���N�^�[�E�X�^�u

}

ClassFileMakerFactory::~ClassFileMakerFactory() {
	// TODO Auto-generated destructor stub
}

ClassFileMakerFactory::ClassFileMakerFactory(int argc, char* argv[]) {
	parser.parseArguments(argc, argv);
	classes_ = parser.getClassName();
}

void ClassFileMakerFactory::buildClassList(FileMakerList* list){
	for(std::vector<std::string>::iterator classNameOfCreating = classes_.begin(); classNameOfCreating != classes_.end(); ++classNameOfCreating) {
		list->addClass(createFileMaker<ClassFileMaker>(*classNameOfCreating));
	}
	for(std::vector<std::string>::iterator classNameOfCreating = classes_.begin(); classNameOfCreating != classes_.end(); ++classNameOfCreating) {
		list->addTestClass(createFileMaker<TestClassFileMaker>(*classNameOfCreating));
	}
}

IMakefileCreator* ClassFileMakerFactory::createMakefile() {
	IMakefileCreator* creator = new MakefileCreatorForCpp(parser.getTargetName());
	creator->setOutputter(new FileOutputter());
	return creator;
}

/////////////////////////////////////////////////////////////////////
template<typename T>
IClassFileMaker* ClassFileMakerFactory::createFileMaker(std::string name) {
	IClassFileMaker* fileMaker = new T(name);
	fileMaker->setOutputter(new FileOutputter());
	return fileMaker;
}

