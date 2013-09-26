/*
 * CFileMaker.cpp
 *
 *  Created on: 2013/09/26
 *      Author: furukawayoshihiro
 */

#include <iostream>
#include <algorithm>
#include <cctype>

#include "CFileMaker.h"

CFileMaker::CFileMaker() : name_(""), moduleName_(""), headerName_(""), objectName_(""), headerSkeleton_(""), cSkeleton_(""), outputter_(NULL) {
	// TODO 自動生成されたコンストラクター・スタブ

}

CFileMaker::CFileMaker(std::string name) : name_(name), moduleName_(name+".c"), headerName_(name+".h"), objectName_(name+".o"), headerSkeleton_(""), cSkeleton_(""), outputter_(NULL) {
}

CFileMaker::~CFileMaker() {
	// TODO Auto-generated destructor stub
	if( outputter_ != NULL ){
		delete outputter_;
		outputter_ = NULL;
	}
}

void CFileMaker::createFiles() {
	createHeaderFile();
	createImplementsFile();

	if( isOutputterSet() ) {
		outputter_->outputContents("src/" + headerName_, headerSkeleton_);
		outputter_->outputContents("src/" + moduleName_, cSkeleton_ );
	}
}

const std::string CFileMaker::getClassName() const {
	return moduleName_;
}

const std::string CFileMaker::getName() const {
	return name_;
}

const std::string CFileMaker::getObjectName() const {
	return objectName_;
}

void CFileMaker::setOutputter(IOutputter* outputter) {
	outputter_ = outputter;
}

///////////////////////////////////////////////////////////////////////////
void CFileMaker::createHeaderFile() {
	std::string label(name_);

	transform(label.begin(), label.end(), label.begin(), ::toupper);
	label += "_H_";
	headerSkeleton_  = "#ifndef " + label + "\n";
	headerSkeleton_ += "#define " + label + "\n";
	headerSkeleton_ += "\n";
	headerSkeleton_ += "#endif\n";
}

void CFileMaker::createImplementsFile() {
	cSkeleton_  = "#include \"" + headerName_ + "\"\n";
	cSkeleton_ += "\n";
}

bool CFileMaker::isOutputterSet() {
	return outputter_ != NULL;
}
