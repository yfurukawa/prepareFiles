/*
 * main.cpp
 *
 *  Created on: 2013/08/13
 *      Author: furukawayoshihiro
 */

#include "IOutputter.h"
#include "ClassFileMaker.h"
#include "TestClassFileMaker.h"
#include "FileOutputter.h"

int main(int argc, char* argv[]) {
	ClassFileMaker* fileMaker;
	fileMaker = new ClassFileMaker("Hoge");
	TestClassFileMaker* testFileMaker;
	testFileMaker = new TestClassFileMaker("Hoge");

	fileMaker->setOutputter(new FileOutputter());
	fileMaker->createFiles();

	testFileMaker->setOutputter(new FileOutputter());
	testFileMaker->createFiles();

	delete fileMaker;
	return 0;
}


