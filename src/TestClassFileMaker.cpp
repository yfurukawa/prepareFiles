/*
 * TestClassFileMaker.cpp
 *
 *  Created on: 2013/08/14
 *      Author: furukawayoshihiro
 */

#include "TestClassFileMaker.h"

TestClassFileMaker::TestClassFileMaker() {
	// TODO 自動生成されたコンストラクター・スタブ

}

TestClassFileMaker::TestClassFileMaker(std::string name) : name_(name+"Test"), testTargetClassName_(name), className_(name+"Test.cpp"), headerName_(name+"Test.h"), objectName_(name+"Test.o"), headerSkeleton_(""), cppSkeleton_(""), outputter_(NULL) {
}

TestClassFileMaker::~TestClassFileMaker() {
	// TODO Auto-generated destructor stub
	if( outputter_ != NULL ){
		delete outputter_;
		outputter_ = NULL;
	}
}

void TestClassFileMaker::createFiles() {
	createHeaderFile();
	createImplementsFile();

	if( isOutputterSet() ) {
		outputter_->outputContents("test/" + headerName_, headerSkeleton_);
		outputter_->outputContents("test/" + className_, cppSkeleton_ );
	}
}

const std::string TestClassFileMaker::getClassName() const {
	return className_;
}

const std::string TestClassFileMaker::getName() const {
	return name_;
}

void TestClassFileMaker::setOutputter(IOutputter* outputter) {
	outputter_ = outputter;
}

const std::string TestClassFileMaker::getObjectName() const {
	return objectName_;
}

//////////////////////////////////////////////////////////////////////
void TestClassFileMaker::createHeaderFile() {
	std::string label(name_);

	transform(label.begin(), label.end(), label.begin(), ::toupper);
	label += "_H_";
	headerSkeleton_  = "#ifndef " + label + "\n";
	headerSkeleton_ += "#define " + label + "\n";
	headerSkeleton_ += "\n";
	headerSkeleton_ += "#include <gtest/gtest.h>\n";
	headerSkeleton_ += "#include \"" + testTargetClassName_ + ".h\"\n";
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
	headerSkeleton_ += "#endif";
}

void TestClassFileMaker::createImplementsFile() {
	cppSkeleton_  = "#include \"" + headerName_ + "\"\n";
	cppSkeleton_ += "\n";
	cppSkeleton_ += name_ + "::" + name_ + "() {\n";
	cppSkeleton_ += "\n";
	cppSkeleton_ += "}\n";
	cppSkeleton_ += "\n";
	cppSkeleton_ += name_ + "::~" + name_ + "() {\n";
	cppSkeleton_ += "\n";
	cppSkeleton_ += "}\n";
	cppSkeleton_ += "\n";
	cppSkeleton_ += "void " + name_ + "::SetUp() {\n";
	cppSkeleton_ += "\tsut = new " + testTargetClassName_ + "();\n";
	cppSkeleton_ += "}\n";
	cppSkeleton_ += "\n";
	cppSkeleton_ += "void " + name_ + "::TearDown() {\n";
	cppSkeleton_ += "\tdelete sut;\n";
	cppSkeleton_ += "}\n";
}

bool TestClassFileMaker::isOutputterSet() {
	return outputter_ != NULL;
}

