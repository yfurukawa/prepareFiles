/*
 * ClassFileMaker.cpp
 *
 *  Created on: 2013/08/13
 *      Author: furukawayoshihiro
 */

#include "ClassFileMaker.h"

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
}

void ClassFileMaker::createImplementsFile() {
}
