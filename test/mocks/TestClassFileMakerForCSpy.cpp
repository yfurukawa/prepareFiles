/*
 * TestClassFileMakerForCSpy.cpp
 *
 *  Created on: 2013/09/28
 *      Author: furukawayoshihiro
 */

#include "TestClassFileMakerForCSpy.h"

TestClassFileMakerForCSpy::TestClassFileMakerForCSpy() {
	// TODO 自動生成されたコンストラクター・スタブ

}

TestClassFileMakerForCSpy::~TestClassFileMakerForCSpy() {
	// TODO Auto-generated destructor stub
}

TestClassFileMakerForCSpy::TestClassFileMakerForCSpy(std::string name) : TestClassFileMakerForC(name) {
}

const std::string TestClassFileMakerForCSpy::getHeaderName() const {
	return headerName_;
}

const std::string TestClassFileMakerForCSpy::getHeaderSkeleton() const {
	return headerSkeleton_;
}

const std::string TestClassFileMakerForCSpy::getCppSkeleton() const {
	return cSkeleton_;
}

const IOutputter* TestClassFileMakerForCSpy::getOutputter() const {
	return outputter_;
}
