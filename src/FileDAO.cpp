/**
 * FileDAO.cpp
 *
 *  Created on: 2013/08/14
 *      Author: furukawayoshihiro
 */


#include "FileDAO.h"

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

void FileDAO::openInputter( std::string name ) {
	inputStream_.exceptions( std::ios::failbit | std::ios::badbit);
	inputStream_.open(name.c_str(), std::ios::in );
}

bool FileDAO::isExsist( std::string name ){
	try {
		inputStream_.exceptions( std::ios::failbit | std::ios::badbit);
		inputStream_.open(name.c_str(), std::ios::in );
		return true;
	}
	catch (...) {
		return false;
	}
	return false;
}

std::string FileDAO::readData(){
	std::string exceptionMessage("File is not opened.");
	throw exceptionMessage;
	return "";
}

