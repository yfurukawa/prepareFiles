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

const std::string TestClassFileMakerSpy::getHeaderName() const {
	return headerName_;
}

const std::string TestClassFileMakerSpy::getHeaderSkeleton() const {
	return headerSkeleton_;
}

const std::string TestClassFileMakerSpy::getCppSkeleton() const {
	return cppSkeleton_;
}

const IOutputter* TestClassFileMakerSpy::getOutputter() const {
	return outputter_;
}

