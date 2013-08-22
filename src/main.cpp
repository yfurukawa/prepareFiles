/*
 * main.cpp
 *
 *  Created on: 2013/08/13
 *      Author: furukawayoshihiro
 */

#include <iostream>
#include <vector>

#include "CommandLineArgumentsParser.h"
#include "IOutputter.h"
#include "ClassFileMaker.h"
#include "TestClassFileMaker.h"
#include "FileOutputter.h"
#include "FileMakerList.h"

ClassFileMaker* createClassFileMaker(std::string);
TestClassFileMaker* createTestClassFileMaker(std::string);
void buildClassList(FileMakerList*, std::vector<std::string>);

int main(int argc, char* argv[]) {

	try {
		CommandLineArgumentsParser* parser = new CommandLineArgumentsParser();
		std::vector<std::string> classes = parser->parseArguments(argc, argv);

		FileMakerList* list = new FileMakerList();
		buildClassList(list, classes);
		list->createFiles();

		delete list;
		delete parser;
		return 0;
	}
	catch(std::invalid_argument& e) {
		std::cout << "Usage: prepareFiles className еее" << std::endl;
		exit (-1);
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
