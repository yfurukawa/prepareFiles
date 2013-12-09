/**
 * MakefileCreatorForCpp.cpp
 *
 *  Created on: 2013/08/24
 *      Author: furukawayoshihiro
 */

#include "MakefileCreatorForCpp.h"

MakefileCreatorForCpp::MakefileCreatorForCpp() : outputter_(NULL), inputter_(NULL), targetName_(), targetNameForTest_("") {

}

MakefileCreatorForCpp::MakefileCreatorForCpp( std::string name ) : outputter_(NULL), inputter_(NULL), targetName_(name), targetNameForTest_(name+"Test") {

}

MakefileCreatorForCpp::~MakefileCreatorForCpp() {
	// TODO Auto-generated destructor stub
	if( outputter_ != NULL ){
		delete outputter_;
		outputter_ = NULL;
	}
	if( inputter_ != NULL ){
		delete inputter_;
		inputter_ = NULL;
	}
}

void MakefileCreatorForCpp::setOutputter(IOutputter* outputter) {
	outputter_ = outputter;
	subCreator.setOutputter(outputter_);
}

void MakefileCreatorForCpp::setInputter(IInputter* inputter) {
	inputter_ = inputter;
	subCreator.setInputter(inputter);
}

void MakefileCreatorForCpp::createFiles(const std::string& sourceClasses,
		const std::string& sourceObjects, const std::string& testClasses, const std::string& testObjects) {
	outputter_->outputContents("src/Makefile", createMakefileContents());
	subCreator.createFiles( sourceClasses, sourceObjects, testClasses, testObjects );
}

/////////////////////////////////////////////////////////////////////////////////////////
std::string MakefileCreatorForCpp::createMakefileContents() {

	std::string contents;
	contents  = "CC = g++\n";
	contents += "RM = rm -f\n";
	contents += "INCLUDE = -I/usr/incude -I/usr/local/include\n";
	contents += "LIB_DIR = -L/usr/lib -L/usr/local/lib\n";
	contents += "LIB =\n";
	contents += "OPT = -O0 -g3 -Wall -fmessage-length=0\n";
	contents += "TARGET = " + targetName_ + "\n";
	contents += "include productionSources.mk\n";
	contents += "include productionObjects.mk\n";
	contents += "\n";
	contents += "all: $(OBJ) main.o\n";
	contents += "\t$(CC) $(INCLUDE) $(LIB_DIR) $(OPT) -o $(TARGET) $(OBJ) main.o";
	contents += "\n";
	contents += "$(OBJ): $(SRC)\n";
	contents += "\t$(CC) $(INCLUDE) $(LIB_DIR) $(OPT) -c $(SRC)\n";
	contents += "\n";
	contents += "main.o: main.cpp\n";
	contents += "\t$(CC) $(INCLUDE) $(LIB_DIR) $(OPT) -c main.cpp";
	contents += "\n";
	contents += ".PHONY: clean\n";
	contents += "clean:\n";
	contents += "\t$(RM) *.o $(TARGET) $(TEST_TARGET) gmon.out *.gc* *.xml\n";
	contents += "\n";
	contents += "\n";
	contents += "TEST_TARGET = " + targetNameForTest_ + "\n";
	contents += "TEST_INCLUDE = -I../test -I.\n";
	contents += "TEST_LIB = -lgtest\n";
	contents += "TEST_OPT = -O0 -g3 -Wall -fmessage-length=0 -pg -fprofile-arcs -ftest-coverage\n";
	contents += "include testSources.mk\n";
	contents += "include testObjects.mk\n";
	contents += "\n";
	contents += "test: $(OBJ) $(TEST_OBJ)\n";
	contents += "\t$(CC) $(INCLUDE) $(TEST_INCLUDE) $(LIB_DIR) $(TEST_OPT) -o $(TEST_TARGET) $(OBJ) $(TEST_OBJ) $(LIB) $(TEST_LIB)\n";
	contents += "\n";
	contents += "$(TEST_OBJ): $(TEST_SRC)\n";
	contents += "\t$(CC) $(INCLUDE) $(TEST_INCLUDE) $(LIB_DIR) $(LIB) $(TEST_LIB) $(TEST_OPT) -c $(TEST_SRC)\n";

	return contents;
}

