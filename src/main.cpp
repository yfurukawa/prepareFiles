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

int main(int argc, char* argv[]) {
	CommandLineArgumentsParser* parser = new CommandLineArgumentsParser();

	try {
		std::vector<std::string>classes = parser->parseArguments(argc, argv);

		for(std::vector<std::string>::iterator classesItr = classes.begin(); classesItr != classes.end(); ++classesItr) {
			ClassFileMaker* fileMaker = new ClassFileMaker(*classesItr);
			TestClassFileMaker* testFileMaker = new TestClassFileMaker(*classesItr);
			fileMaker->setOutputter(new FileOutputter());
			fileMaker->createFiles();

			testFileMaker->setOutputter(new FileOutputter());
			testFileMaker->createFiles();
			delete fileMaker;
			delete testFileMaker;
		}
		delete parser;
		return 0;
	}
	catch(std::invalid_argument& e) {
		std::cout << "Usage:" << std::endl;
		exit (-1);
	}
}


