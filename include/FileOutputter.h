/*
 * FileOutputter.h
 *
 *  Created on: 2013/08/14
 *      Author: furukawayoshihiro
 */

#ifndef FILEOUTPUTTER_H_
#define FILEOUTPUTTER_H_

#include "IOutputter.h"

class FileOutputter: public IOutputter {
public:
	FileOutputter();
	virtual ~FileOutputter();
	virtual void outputContents( std::string outputName, std::string contents );
};

#endif /* FILEOUTPUTTER_H_ */
