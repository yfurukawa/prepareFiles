/*
 * FileOutputter.h
 *
 *  Created on: 2013/08/14
 *      Author: furukawayoshihiro
 */

#ifndef FILEOUTPUTTER_H_
#define FILEOUTPUTTER_H_

#include "IOutputter.h"
#include "IInputter.h"

class FileDAO: public IOutputter, IInputter {
public:
	FileDAO();
	virtual ~FileDAO();
	virtual void outputContents( std::string outputName, std::string contents );
	virtual void openInputter( std::string name );
};

#endif /* FILEOUTPUTTER_H_ */
