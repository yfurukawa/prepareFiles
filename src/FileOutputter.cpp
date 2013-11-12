/**
 * FileOutputter.cpp
 *
 *  Created on: 2013/08/14
 *      Author: furukawayoshihiro
 */

#include <fstream>

#include "FileOutputter.h"

FileOutputter::FileOutputter() {
	// TODO �����������ꂽ�R���X�g���N�^�[�E�X�^�u

}

FileOutputter::~FileOutputter() {
	// TODO Auto-generated destructor stub
}

void FileOutputter::outputContents(std::string outputName,
		std::string contents) {
	std::ofstream outFile(outputName.c_str(), std::ios::out | std::ios::trunc);

	outFile << contents;
}
