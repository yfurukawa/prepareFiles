/**
 * MakefileCreatorFactory.cpp
 *
 *  Created on: 2013/09/26
 *      Author: furukawayoshihiro
 */
#include <iostream>

#include "MakefileCreatorFactory.h"
#include "MakefileCreatorForCpp.h"
#include "MakefileCreatorForC.h"
#include "FileDAO.h"

MakefileCreatorFactory::MakefileCreatorFactory() : parser_(NULL) {
	// TODO �����������ꂽ�R���X�g���N�^�[�E�X�^�u

}

MakefileCreatorFactory::MakefileCreatorFactory(CommandLineArgumentsParser* parser) : parser_(parser) {
}

MakefileCreatorFactory::~MakefileCreatorFactory() {
	// TODO Auto-generated destructor stub
}

IMakefileCreator* MakefileCreatorFactory::createMakefileCreator() {
	IMakefileCreator* creator;
	if(parser_->getLanguage() == "cpp") {
		creator = new MakefileCreatorForCpp(parser_->getTargetName());
	}
	else {
		creator = new MakefileCreatorForC(parser_->getTargetName());
	}
	creator->setOutputter(new FileDAO());
	return creator;
}
