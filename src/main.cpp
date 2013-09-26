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
#include "ClassFileMakerFactory.h"
#include "IOutputter.h"
#include "IMakefileCreator.h"
#include "FileOutputter.h"
#include "FileMakerList.h"
#include "TestMainMaker.h"

void prepareSourceDirectory();

int main(int argc, char* argv[]) {

	try {
		CommandLineArgumentsParser parser;
		parser.parseArguments(argc, argv);

		prepareSourceDirectory();

		ClassFileMakerFactory factory(&parser);

		FileMakerList list;
		factory.buildClassList(&list);
		list.createFiles();

		IMakefileCreator* makefileCreator = factory.createMakefile();

		makefileCreator->createFiles(list.getClassFileList(), list.getObjectFileList(), list.getTestClassFileList(), list.getTestObjectFileList());

		TestMainMaker testMainMaker;
		testMainMaker.setOutputter(new FileOutputter());
		testMainMaker.createFiles();

		delete makefileCreator;
		return 0;
	}
	catch(const std::invalid_argument& e) {
		std::cerr << e.what();
		std::cerr << std::endl;
		std::cout << "Usage: prepareFiles [--lang=cpp | --lang=c] [--target=targetName] className ..." << std::endl;
		return -1;
	}
	catch(...) {
		std::cerr << "Unknown exceptions are there." << std::endl;
		return -1;
	}
}

void prepareSourceDirectory() {
#ifdef __APPLE__
	mkdir( "src" , 0777 );
	mkdir( "test", 0777 );
#else
	mkdir( "src" );
	mkdir( "test");
#endif
}
