/*
 * OutputterMock.cpp
 *
 *  Created on: 2013/08/13
 *      Author: furukawayoshihiro
 */

#include "OutputterMock.h"

OutputterMock::OutputterMock() : name_("outputterMock"), numberOfCall_(0), isExsist_(false) {
	// TODO �����������ꂽ�R���X�g���N�^�[�E�X�^�u

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

void OutputterMock::openInputter( std::string name ){
}



std::string OutputterMock::readData(){
	return "";
}



bool OutputterMock::isExsist( std::string name ){
	return isExsist_;
}

int OutputterMock::getNumberOfCall() {
	return outputName_.size();
}

void OutputterMock::setFileExsist( bool isExsist ){
	isExsist_ = isExsist;
}

