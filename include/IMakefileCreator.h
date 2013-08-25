/*
 * IMakefileCreator.h
 *
 *  Created on: 2013/08/24
 *      Author: furukawayoshihiro
 */

#ifndef IMAKEFILECREATOR_H_
#define IMAKEFILECREATOR_H_

#include "IOutputter.h"

class IMakefileCreator {
public:
	IMakefileCreator();
	virtual ~IMakefileCreator();
	virtual void setOutputter(IOutputter* outputter) = 0;

};

#endif /* IMAKEFILECREATOR_H_ */
