/*
 * ClassFileMaker.cpp
 *
 *  Created on: 2013/08/13
 *      Author: furukawayoshihiro
 */

#include "ClassFileMaker.h"

ClassFileMaker::ClassFileMaker() : name_(NULL){
	// TODO �����������ꂽ�R���X�g���N�^�[�E�X�^�u

}

ClassFileMaker::ClassFileMaker(std::string name) : name_(name) {
}

ClassFileMaker::~ClassFileMaker() {
	// TODO Auto-generated destructor stub
}

std::string ClassFileMaker::getName() {
	return name_;
}

std::string ClassFileMaker::getClassName() {
	return name_+".cpp";
}

void ClassFileMaker::createHeaderFile() {
}

void ClassFileMaker::createImplementsFile() {
}
