/*
 * MakefileCreatorForCpp.cpp
 *
 *  Created on: 2013/08/24
 *      Author: furukawayoshihiro
 */

#include "MakefileCreatorForCpp.h"

MakefileCreatorForCpp::MakefileCreatorForCpp() : outputter_(NULL) {
	// TODO �����������ꂽ�R���X�g���N�^�[�E�X�^�u

}

MakefileCreatorForCpp::~MakefileCreatorForCpp() {
	// TODO Auto-generated destructor stub
}

void MakefileCreatorForCpp::setOutputter(IOutputter* outputter) {
	outputter_ = outputter;
}
