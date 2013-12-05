/*
 * FileDAO.h
 *
 *  Created on: 2013/08/14
 *      Author: furukawayoshihiro
 */

#ifndef FILEDAO_H_
#define FILEDAO_H_

#include <fstream>
#include <iostream>

#include "IOutputter.h"
#include "IInputter.h"

class FileDAO: public IOutputter, IInputter {
public:
	FileDAO();
	virtual ~FileDAO();
	virtual void outputContents( std::string outputName, std::string contents );
	virtual void openInputter( std::string name );
	bool isExsist( std::string name );
private:
	std::ifstream inputStream_;
};

#endif /* FILEDAO_H_ */
