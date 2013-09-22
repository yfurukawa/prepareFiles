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

ClassFileMaker* createClassFileMaker(std::string);
TestClassFileMaker* createTestClassFileMaker(std::string);
void buildClassList(FileMakerList*, std::vector<std::string>);

int main(int argc, char* argv[]) {

	try {
		mkdir( "src" , 0777 );
		mkdir( "test", 0777 );
		CommandLineArgumentsParser* parser = new CommandLineArgumentsParser();
		std::vector<std::string> classes = parser->parseArguments(argc, argv);

		FileMakerList* list = new FileMakerList();
		buildClassList(list, classes);
		list->createFiles();

		IMakefileCreator* makefileCreator = new MakefileCreatorForCpp(parser->getTargetName());
		makefileCreator->setOutputter(new FileOutputter());
		makefileCreator->createFiles(list->getClassFileList(), list->getObjectFileList(), list->getTestClassFileList(), list->getTestObjectFileList());

		TestMainMaker* testMainMaker = new TestMainMaker();
		testMainMaker->setOutputter(new FileOutputter());
		testMainMaker->createFiles();

		delete list;
		delete parser;
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

ClassFileMaker* createClassFileMaker(std::string name){
	ClassFileMaker* fileMaker = new ClassFileMaker(name);
	fileMaker->setOutputter(new FileOutputter());
	return fileMaker;
}

TestClassFileMaker* createTestClassFileMaker(std::string name){
	TestClassFileMaker* testFileMaker = new TestClassFileMaker(name);
	testFileMaker->setOutputter(new FileOutputter());
	return testFileMaker;
}

void buildClassList(FileMakerList* list, std::vector<std::string> classes){
	for(std::vector<std::string>::iterator classesItr = classes.begin(); classesItr != classes.end(); ++classesItr) {
		list->addClass(createClassFileMaker(*classesItr));
		list->addTestClass(createTestClassFileMaker(*classesItr));
	}
}
