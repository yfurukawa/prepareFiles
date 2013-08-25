/*
 * IMakefileCreator.h
 *
 *  Created on: 2013/08/24
 *      Author: furukawayoshihiro
 */

#ifndef IMAKEFILECREATOR_H_
#define IMAKEFILECREATOR_H_

#include <iostream>
#include "IOutputter.h"

class IMakefileCreator {
public:
	IMakefileCreator();
	virtual ~IMakefileCreator();
	virtual void setOutputter(IOutputter* outputter) = 0;
	virtual void setSourceClasses(std::string sourceClass) = 0;
	virtual void setTestClasses(std::string testClasses) = 0;
	virtual void createFiles(const std::string sourceClasses, const std::string sourceObjects,
							const std::string testClasses, const std::string testObjects) = 0;
};

#endif /* IMAKEFILECREATOR_H_ */
