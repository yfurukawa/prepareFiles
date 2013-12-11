/**
 * TestMainMakerSpy.cpp
 *
 *  Created on: 2013/09/22
 *      Author: furukawayoshihiro
 */

#include "TestMainMakerSpy.h"

TestMainMakerSpy::TestMainMakerSpy() {
	// TODO �����������ꂽ�R���X�g���N�^�[�E�X�^�u

}

TestMainMakerSpy::~TestMainMakerSpy() {
	// TODO Auto-generated destructor stub
}

const std::string TestMainMakerSpy::getCppSkeleton() const {
	return cppSkeleton_;
}

const IOutputter* TestMainMakerSpy::getOutputter() const {
	return outputter_;
}
