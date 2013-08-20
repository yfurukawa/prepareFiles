/*
 * ClassFileMakerSpy.cpp
 *
 *  Created on: 2013/08/13
 *      Author: furukawayoshihiro
 */

#include "ClassFileMakerSpy.h"

ClassFileMakerSpy::ClassFileMakerSpy() {
	// TODO 自動生成されたコンストラクター・スタブ

}

ClassFileMakerSpy::ClassFileMakerSpy(std::string name) : ClassFileMaker(name) {

}

ClassFileMakerSpy::~ClassFileMakerSpy() {
	// TODO Auto-generated destructor stub
}

const std::string ClassFileMakerSpy::getHeaderName() {
	return headerName_;
}

std::string ClassFileMakerSpy::getHeaderSkeleton() {
	return headerSkeleton_;
}

std::string ClassFileMakerSpy::getCppSkeleton() {
	return cppSkeleton_;
}

IOutputter* ClassFileMakerSpy::getOutputter() {
	return outputter_;
}
