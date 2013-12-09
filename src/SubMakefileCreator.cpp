/**
 * SubMakefileCreator.cpp
 *
 *  Created on: 2013/11/26
 *      Author: M825504
 */

#include "SubMakefileCreator.h"
#include <iostream>

SubMakefileCreator::SubMakefileCreator() : outputter_(NULL), inputter_(NULL) {

}

SubMakefileCreator::~SubMakefileCreator() {
	// TODO Auto-generated destructor stub
}

void SubMakefileCreator::setOutputter(IOutputter* outputter) {
	outputter_ = outputter;
}

void SubMakefileCreator::setInputter(IInputter* inputter) {
	inputter_ = inputter;
}


void SubMakefileCreator::createFiles(const std::string& sourceClasses,
		const std::string& sourceObjects, const std::string& testClasses,
		const std::string& testObjects) {
	if( inputter_->isExsist("src/productionSources.mk") ) {
		inputter_->openInputter("src/productionSources.mk");
		outputter_->outputContents("src/productionSources.mk",
				inputter_->readData()+" "+sourceClasses+"\n");
		inputter_->closeInputter();
		inputter_->openInputter("src/productionObjects.mk");
		outputter_->outputContents("src/productionObjects.mk",
				inputter_->readData()+" "+sourceObjects+"\n");
		inputter_->closeInputter();
		inputter_->openInputter("src/testSources.mk");
		outputter_->outputContents("src/testSources.mk",
				inputter_->readData()+" "+testClasses+"\n");
		inputter_->closeInputter();
		inputter_->openInputter("src/testObjects.mk");
		outputter_->outputContents("src/testObjects.mk",
				inputter_->readData()+" "+testObjects+"\n");
		inputter_->closeInputter();
	}
	else {
		outputter_->outputContents("src/productionSources.mk", createProductionSources(sourceClasses));
		outputter_->outputContents("src/productionObjects.mk", createProductionObjects(sourceObjects));
		outputter_->outputContents("src/testSources.mk", createTestSources(testClasses));
		outputter_->outputContents("src/testObjects.mk", createTestObjects(testObjects));
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////

std::string SubMakefileCreator::createProductionSources(
		const std::string& sourceClasses) {
	return "SRC = " + sourceClasses + "\n";
}


std::string SubMakefileCreator::createProductionObjects(
		const std::string& sourceObjects) {
	return "OBJ = " + sourceObjects + "\n";
}


std::string SubMakefileCreator::createTestSources(
		const std::string& testClasses) {
	return "TEST_SRC = ../test/testMain.cpp " + testClasses + "\n";
}


std::string SubMakefileCreator::createTestObjects(
		const std::string& testObjects) {
	return "TEST_OBJ = testMain.o " + testObjects + "\n";
}
