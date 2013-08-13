/*
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

ClassFileMaker::ClassFileMaker() : name_(NULL){
	// TODO 自動生成されたコンストラクター・スタブ

}

ClassFileMaker::ClassFileMaker(std::string name) : name_(name), className_(name+".cpp"), headerName_(name+".h") {
}

ClassFileMaker::~ClassFileMaker() {
	// TODO Auto-generated destructor stub
}

const std::string ClassFileMaker::getName() {
	return name_;
}

const std::string ClassFileMaker::getClassName() {
	return className_;
}

void ClassFileMaker::createHeaderFile() {
	std::string label(name_);

	transform(label.begin(), label.end(), label.begin(), ::toupper);
	label += "_H_";
	headerSkeleton_  = "#ifndef " + label + "\n";
	headerSkeleton_ += "#define " + label + "\n";
	headerSkeleton_ += "\n";
	headerSkeleton_ += "class " + name_ + " {\n";
	headerSkeleton_ += "public:\n";
	headerSkeleton_ += "\t" + name_ + "();\n";
	headerSkeleton_ += "\t~" + name_ + "();\n";
	headerSkeleton_ += "\n";
	headerSkeleton_ += "};\n";
	headerSkeleton_ += "\n";
	headerSkeleton_ += "#endif";
}

void ClassFileMaker::createImplementsFile() {
}
