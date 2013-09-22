/*
 * TestMainMaker.cpp
 *
 *  Created on: 2013/09/22
 *      Author: furukawayoshihiro
 */

#include "TestMainMaker.h"

TestMainMaker::TestMainMaker() : name_("testMain"), className_("testMain.cpp"), cppSkeleton_(""), outputter_(NULL) {
	// TODO 自動生成されたコンストラクター・スタブ

}

TestMainMaker::~TestMainMaker() {
	// TODO Auto-generated destructor stub
	if( outputter_ != NULL ){
		delete outputter_;
		outputter_ = NULL;
	}
}

const std::string TestMainMaker::getClassName() const {
	return className_;
}

const std::string TestMainMaker::getName() const {
	return name_;
}

const std::string TestMainMaker::getObjectName() const {
	return name_+".o";
}

void TestMainMaker::createFiles() {
	createImplementsFile();

	if( isOutputterSet() ) {
		outputter_->outputContents("../test/" + className_, cppSkeleton_ );
	}
}

void TestMainMaker::setOutputter(IOutputter* outputter) {
	outputter_ = outputter;
}

///////////////////////////////////////////////////////////////////
void TestMainMaker::createHeaderFile() {
	// Don't need to implements this method due to testMain.cpp has no header file.
}

void TestMainMaker::createImplementsFile() {
	cppSkeleton_ = "#include <gtest/gtest.h>\n\n";
	cppSkeleton_ += "int main(int argc, char** argv) {\n";
	cppSkeleton_ += "\t::testing::InitGoogleTest(&argc, argv);\n";
	cppSkeleton_ += "\treturn RUN_ALL_TESTS();\n";
	cppSkeleton_ += "}\n";
}

bool TestMainMaker::isOutputterSet() {
	return outputter_ != NULL;
}
