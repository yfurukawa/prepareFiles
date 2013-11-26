/*
 * MakefileCreatorForCppSpy.cpp
 *
 *  Created on: 2013/08/25
 *      Author: furukawayoshihiro
 */

#include "MakefileCreatorForCppSpy.h"

MakefileCreatorForCppSpy::MakefileCreatorForCppSpy() {
	// TODO �����������ꂽ�R���X�g���N�^�[�E�X�^�u
}

MakefileCreatorForCppSpy::MakefileCreatorForCppSpy(std::string targetName) : MakefileCreatorForCpp( targetName ){
}

MakefileCreatorForCppSpy::~MakefileCreatorForCppSpy() {
	// TODO Auto-generated destructor stub
}

const IOutputter* MakefileCreatorForCppSpy::getOutputter() const {
	return outputter_;
}

