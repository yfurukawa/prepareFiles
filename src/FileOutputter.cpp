/**
 * FileOutputter.cpp
 *
 *  Created on: 2013/08/14
 *      Author: furukawayoshihiro
 */

#include <fstream>
#include <iostream>

#include "FileOutputter.h"

FileDAO::FileDAO() {
	// TODO �����������ꂽ�R���X�g���N�^�[�E�X�^�u

}

FileDAO::~FileDAO() {
	// TODO Auto-generated destructor stub
}

void FileDAO::outputContents(std::string outputName,
		std::string contents) {
	std::ofstream outFile(outputName.c_str(), std::ios::out | std::ios::trunc);

	outFile << contents;
}

void FileDAO::openInputter( std::string name ){
}

