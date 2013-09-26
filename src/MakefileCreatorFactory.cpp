/*
 * MakefileCreatorFactory.cpp
 *
 *  Created on: 2013/09/26
 *      Author: furukawayoshihiro
 */
#include <iostream>

#include "MakefileCreatorFactory.h"
#include "MakefileCreatorForCpp.h"
#include "FileOutputter.h"

MakefileCreatorFactory::MakefileCreatorFactory() : parser_(NULL) {
	// TODO 自動生成されたコンストラクター・スタブ

}

MakefileCreatorFactory::MakefileCreatorFactory(CommandLineArgumentsParser* parser) : parser_(parser) {
}

MakefileCreatorFactory::~MakefileCreatorFactory() {
	// TODO Auto-generated destructor stub
}

IMakefileCreator* MakefileCreatorFactory::createMakefileCreator() {
	IMakefileCreator* creator = new MakefileCreatorForCpp(parser_->getTargetName());
	creator->setOutputter(new FileOutputter());
	return creator;
}
