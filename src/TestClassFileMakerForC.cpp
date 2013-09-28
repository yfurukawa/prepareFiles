/*
 * TestClassFileMakerForC.cpp
 *
 *  Created on: 2013/09/28
 *      Author: furukawayoshihiro
 */

#include "TestClassFileMakerForC.h"

TestClassFileMakerForC::TestClassFileMakerForC() : name_(""), testTargetClassName_(""), moduleName_(""), headerName_(""), objectName_(""), headerSkeleton_(""), cSkeleton_(""), outputter_(NULL)  {
	// TODO 自動生成されたコンストラクター・スタブ

}

TestClassFileMakerForC::TestClassFileMakerForC(std::string name) : name_(name+"Test"), testTargetClassName_(name), moduleName_(name+"Test.c"), headerName_(name+"Test.h"), objectName_(name+"Test.o"), headerSkeleton_(""), cSkeleton_(""), outputter_(NULL) {
}

TestClassFileMakerForC::~TestClassFileMakerForC() {
	// TODO Auto-generated destructor stub
	if( outputter_ != NULL ){
		delete outputter_;
		outputter_ = NULL;
	}
}

void TestClassFileMakerForC::createFiles() {
	createHeaderFile();
	createImplementsFile();

	if( isOutputterSet() ) {
		outputter_->outputContents("test/" + headerName_, headerSkeleton_);
		outputter_->outputContents("test/" + moduleName_, cSkeleton_ );
	}
}

const std::string TestClassFileMakerForC::getClassName() const {
	return "../test/"+moduleName_;
}

const std::string TestClassFileMakerForC::getName() const {
	return name_;
}

const std::string TestClassFileMakerForC::getObjectName() const {
	return objectName_;
}

void TestClassFileMakerForC::setOutputter(IOutputter* outputter) {
	outputter_ = outputter;
}

////////////////////////////////////////////////////////////////////////
void TestClassFileMakerForC::createHeaderFile() {
	std::string label(name_);

	transform(label.begin(), label.end(), label.begin(), ::toupper);
	label += "_H_";
	headerSkeleton_  = "#ifndef " + label + "\n";
	headerSkeleton_ += "#define " + label + "\n";
	headerSkeleton_ += "\n";
	headerSkeleton_ += "#include <gtest/gtest.h>\n";
	headerSkeleton_ += "\n";
	headerSkeleton_ += "extern \"C\" {\n";
	headerSkeleton_ += "\t#include \"" + testTargetClassName_ + ".h\"\n";
	headerSkeleton_ += "}\n";
	headerSkeleton_ += "\n";
	headerSkeleton_ += "class " + name_ + " : public ::testing::Test {\n";
	headerSkeleton_ += "protected:\n";
	headerSkeleton_ += "\t" + testTargetClassName_ + "* sut;\n";
	headerSkeleton_ += "\tvoid SetUp();\n";
	headerSkeleton_ += "\tvoid TearDown();\n";
	headerSkeleton_ += "\n";
	headerSkeleton_ += "public:\n";
	headerSkeleton_ += "\t" + name_ + "();\n";
	headerSkeleton_ += "\tvirtual ~" + name_ + "();\n";
	headerSkeleton_ += "\n";
	headerSkeleton_ += "};\n";
	headerSkeleton_ += "\n";
	headerSkeleton_ += "#endif\n";
}

void TestClassFileMakerForC::createImplementsFile() {
	cSkeleton_  = "#include \"" + headerName_ + "\"\n";
	cSkeleton_ += "\n";
	cSkeleton_ += name_ + "::" + name_ + "() {\n";
	cSkeleton_ += "\n";
	cSkeleton_ += "}\n";
	cSkeleton_ += "\n";
	cSkeleton_ += name_ + "::~" + name_ + "() {\n";
	cSkeleton_ += "\n";
	cSkeleton_ += "}\n";
	cSkeleton_ += "\n";
	cSkeleton_ += "void " + name_ + "::SetUp() {\n";
	cSkeleton_ += "\tsut = new " + testTargetClassName_ + "();\n";
	cSkeleton_ += "}\n";
	cSkeleton_ += "\n";
	cSkeleton_ += "void " + name_ + "::TearDown() {\n";
	cSkeleton_ += "\tdelete sut;\n";
	cSkeleton_ += "}\n";
	cSkeleton_ += "\n";
	cSkeleton_ += "TEST_F (" + name_ + ", testNameIsHere_ChangeThis) {\n";
	cSkeleton_ += "/* Write a test code here. */\n\n";
	cSkeleton_ += "}\n";
}

bool TestClassFileMakerForC::isOutputterSet() {
	return outputter_ != NULL;
}
