/*
 * main.cpp
 *
 *  Created on: 2013/08/13
 *      Author: furukawayoshihiro
 */

#include <iostream>
#include <vector>
#include <stdexcept>
#include <dirent.h>
#include <sys/stat.h>

#include "CommandLineArgumentsParser.h"
#include "IOutputter.h"
#include "IMakefileCreator.h"
#include "ClassFileMaker.h"
#include "TestClassFileMaker.h"
#include "FileOutputter.h"
#include "FileMakerList.h"
#include "MakefileCreatorForCpp.h"
#include "TestMainMaker.h"

void buildClassList(FileMakerList*, std::vector<std::string>);
void prepareTargetDirectory();

int main(int argc, char* argv[]) {

	try {
		prepareTargetDirectory();

		CommandLineArgumentsParser parser;
		std::vector<std::string> classes = parser.parseArguments(argc, argv);

		FileMakerList list;
		buildClassList(&list, classes);
		list.createFiles();

		IMakefileCreator* makefileCreator = new MakefileCreatorForCpp(parser.getTargetName());
		makefileCreator->setOutputter(new FileOutputter());
		makefileCreator->createFiles(list.getClassFileList(), list.getObjectFileList(), list.getTestClassFileList(), list.getTestObjectFileList());

		TestMainMaker* testMainMaker = new TestMainMaker();
		testMainMaker->setOutputter(new FileOutputter());
		testMainMaker->createFiles();

		delete makefileCreator;
		delete testMainMaker;
		return 0;
	}
	catch(const std::invalid_argument& e) {
		std::cerr << e.what();
		std::cerr << std::endl;
		std::cout << "Usage: prepareFiles --lang=cpp | --lang=c className ..." << std::endl;
		return -1;
	}
	catch(...) {
		std::cerr << "Unknown exceptions are there." << std::endl;
		return -1;
	}
}

template<class T>
IClassFileMaker* createFileMaker(std::string name) {
	IClassFileMaker* fileMaker = new T(name);
	fileMaker->setOutputter(new FileOutputter());
	return fileMaker;
}

void buildClassList(FileMakerList* list, std::vector<std::string> classes){
	for(std::vector<std::string>::iterator classNameOfCreating = classes.begin(); classNameOfCreating != classes.end(); ++classNameOfCreating) {
		list->addClass(createFileMaker<ClassFileMaker>(*classNameOfCreating));
	}
	for(std::vector<std::string>::iterator classNameOfCreating = classes.begin(); classNameOfCreating != classes.end(); ++classNameOfCreating) {
		list->addTestClass(createFileMaker<TestClassFileMaker>(*classNameOfCreating));
	}
}

void prepareTargetDirectory() {
	mkdir( "src" , 0777 );
	mkdir( "test", 0777 );
}
