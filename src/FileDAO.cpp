/**
 * FileDAO.cpp
 *
 *  Created on: 2013/08/14
 *      Author: furukawayoshihiro
 */


#include "FileDAO.h"

#ifdef __MINGW32__
#else
#include "boost/filesystem.hpp"
#endif

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

#ifdef __MINGW32__
	try {
		inputStream_.exceptions( std::ios::failbit | std::ios::badbit);
		inputStream_.open(name.c_str(), std::ios::in );
		return true;
	}
	catch (...) {
		return false;
	}

#else
	boost::filesystem::path pathToFile(name.c_str());
	return boost::filesystem::exists( pathToFile );
#endif

}


