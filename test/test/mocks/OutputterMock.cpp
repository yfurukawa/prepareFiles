/*
 * OutputterMock.cpp
 *
 *  Created on: 2013/08/13
 *      Author: furukawayoshihiro
 */

#include "OutputterMock.h"

OutputterMock::OutputterMock() : name_("outputterMock"), numberOfCall_(0) {
	// TODO 自動生成されたコンストラクター・スタブ

}

OutputterMock::~OutputterMock() {
	// TODO Auto-generated destructor stub
}

void OutputterMock::outputContents(std::string outputName,
		std::string contents) {
	outputName_.push_back(outputName);
	contents_.push_back(contents);
}

std::string OutputterMock::getOutputName(unsigned int index) {
	return outputName_[index];
}

std::string OutputterMock::getContents(unsigned int index) {
	return contents_[index];
}

int OutputterMock::getNumberOfCall() {
	return outputName_.size();
}
