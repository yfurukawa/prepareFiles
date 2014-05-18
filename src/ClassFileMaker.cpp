/**
 * ClassFileMaker.cpp
 *
 *  Created on: 2013/08/13
 *      Author: furukawayoshihiro
 */
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <cstdio>

#include "ClassFileMaker.h"

using namespace std;

ClassFileMaker::ClassFileMaker() : name_(""), className_(""), headerName_(""), objectName_(""), headerSkeleton_(""), cppSkeleton_(""), outputter_(NULL){
	// TODO

}

ClassFileMaker::ClassFileMaker(std::string name) : name_(name), className_(name+".cpp"), headerName_(name+".h"), objectName_(name+".o"), headerSkeleton_(""), cppSkeleton_(""), outputter_(NULL) {
}

ClassFileMaker::~ClassFileMaker() {
	// TODO Auto-generated destructor stub
	if( outputter_ != NULL ){
		delete outputter_;
		outputter_ = NULL;
	}
}

void ClassFileMaker::createFiles() {
	createHeaderFile();
	createImplementsFile();

	if( isOutputterSet() ) {
		outputter_->outputContents("src/" + headerName_, headerSkeleton_);
		outputter_->outputContents("src/" + className_, cppSkeleton_ );
	}
}

void ClassFileMaker::setOutputter(IOutputter* outputter) {
	outputter_ = outputter;
}

const std::string ClassFileMaker::getName() const {
	return name_;
}

const std::string ClassFileMaker::getClassName() const {
	return className_;
}

const std::string ClassFileMaker::getObjectName() const {
	return objectName_;
}

////////////////////////////////////////////////////////////////////////////////////

void ClassFileMaker::createHeaderFile() {
	std::string label(name_);

	transform(label.begin(), label.end(), label.begin(), ::toupper);
	label += "_H_";
	headerSkeleton_ = "/**\n";
	headerSkeleton_ += " * " + name_ + ".h<br>\n";
	headerSkeleton_ += " * Copyright\n";
	headerSkeleton_ += " *\n";
	headerSkeleton_ += " */\n";
	headerSkeleton_ += "\n";
	headerSkeleton_ += "#ifndef " + label + "\n";
	headerSkeleton_ += "#define " + label + "\n";
	headerSkeleton_ += "\n";
	headerSkeleton_ += "class " + name_ + " {\n";
	headerSkeleton_ += " public:\n";
	headerSkeleton_ += "  //! Constractor\n";
	headerSkeleton_ += "  " + name_ + "();\n";
	headerSkeleton_ += "  //! Destructor\n";
	headerSkeleton_ += "  virtual ~" + name_ + "();\n";
	headerSkeleton_ += "\n";
	headerSkeleton_ += " protected:\n";
	headerSkeleton_ += " private:\n";
	headerSkeleton_ += "};\n";
	headerSkeleton_ += "\n";
	headerSkeleton_ += "#endif  // " + label + "\n";
}

void ClassFileMaker::createImplementsFile() {
	cppSkeleton_  = "/*\n * Copyright\n *\n*/\n";
	cppSkeleton_ += "#include \"./" + headerName_ + "\"\n";
	cppSkeleton_ += "\n";
	cppSkeleton_ += name_ + "::" + name_ + "() {\n";
	cppSkeleton_ += "}\n";
	cppSkeleton_ += "\n";
	cppSkeleton_ += name_ + "::~" + name_ + "() {\n";
	cppSkeleton_ += "}\n";
}

bool ClassFileMaker::isOutputterSet() {
	return outputter_ != NULL;
}
