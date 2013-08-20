/*
 * TestClassFileMakerSpy.cpp
 *
 *  Created on: 2013/08/14
 *      Author: furukawayoshihiro
 */

#include "TestClassFileMakerSpy.h"

TestClassFileMakerSpy::TestClassFileMakerSpy() {
	// TODO 自動生成されたコンストラクター・スタブ

}

TestClassFileMakerSpy::TestClassFileMakerSpy(std::string name) : TestClassFileMaker(name) {

}

TestClassFileMakerSpy::~TestClassFileMakerSpy() {
	// TODO Auto-generated destructor stub
}

const std::string TestClassFileMakerSpy::getHeaderName() {
	return headerName_;
}

std::string TestClassFileMakerSpy::getHeaderSkeleton() {
	return headerSkeleton_;
}

std::string TestClassFileMakerSpy::getCppSkeleton() {
	return cppSkeleton_;
}

IOutputter* TestClassFileMakerSpy::getOutputter() {
	return outputter_;
}
