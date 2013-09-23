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

#include "ClassFileMakerFactory.h"
#include "IOutputter.h"
#include "IMakefileCreator.h"
#include "FileOutputter.h"
#include "FileMakerList.h"
#include "TestMainMaker.h"

void prepareTargetDirectory();

int main(int argc, char* argv[]) {

	try {
		prepareTargetDirectory();

		ClassFileMakerFactory factory(argc, argv);

		FileMakerList list;
		factory.buildClassList(&list);
		list.createFiles();

		IMakefileCreator* makefileCreator = factory.createMakefile();

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

void prepareTargetDirectory() {
	mkdir( "src" , 0777 );
	mkdir( "test", 0777 );
}
