/**
 * ClassFileMakerMock.cpp
 *
 *  Created on: 2013/08/16
 *      Author: furukawayoshihiro
 */

#include "ClassFileMakerMock.h"

ClassFileMakerMock::ClassFileMakerMock() : numberOfCretatedFiles_(0) {
	// TODO �����������ꂽ�R���X�g���N�^�[�E�X�^�u

}

ClassFileMakerMock::~ClassFileMakerMock() {
	// TODO Auto-generated destructor stub
}

void ClassFileMakerMock::createFiles() {
	++numberOfCretatedFiles_;
}

const unsigned int ClassFileMakerMock::getNumberOfCreatedFile() {
	return numberOfCretatedFiles_;
}
