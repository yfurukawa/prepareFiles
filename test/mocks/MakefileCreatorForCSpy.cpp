/*
 * MakefileCreatorForCSpy.cpp
 *
 *  Created on: 2013/09/28
 *      Author: furukawayoshihiro
 */

#include <iostream>

#include "MakefileCreatorForCSpy.h"

MakefileCreatorForCSpy::MakefileCreatorForCSpy() {
	// TODO �����������ꂽ�R���X�g���N�^�[�E�X�^�u

}

MakefileCreatorForCSpy::~MakefileCreatorForCSpy() {
	// TODO Auto-generated destructor stub
}

MakefileCreatorForCSpy::MakefileCreatorForCSpy(std::string targetName) : MakefileCreatorForC(targetName){
}

const IOutputter* MakefileCreatorForCSpy::getOutputter() const {
	return outputter_;
}

const std::string MakefileCreatorForCSpy::getSourceClasses() const {
	return sourceClasses_;
}

const std::string MakefileCreatorForCSpy::getTestClasses() const {
	return testClasses_;
}
