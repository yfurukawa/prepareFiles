/*
 * IClassFileMaker.cpp
 *
 *  Created on: 2013/08/13
 *      Author: furukawayoshihiro
 */

#include "IClassFileMaker.h"

IClassFileMaker::~IClassFileMaker() {
	// TODO Auto-generated destructor stub
}

IClassFileMaker::IClassFileMaker() {
	// TODO 自動生成されたコンストラクター・スタブ

}

void IClassFileMaker::createClassFile() {
	createHeaderFile();
	createImplementsFile();
}
