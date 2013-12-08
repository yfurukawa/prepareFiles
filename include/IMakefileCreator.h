/*
 * IMakefileCreator.h
 *
 *  Created on: 2013/08/24
 *      Author: furukawayoshihiro
 */

#ifndef IMAKEFILECREATOR_H_
#define IMAKEFILECREATOR_H_

#include <iostream>
#include <string>
#include "IOutputter.h"
#include "IInputter.h"

class IMakefileCreator {
public:
	IMakefileCreator();
	virtual ~IMakefileCreator();
	virtual void setOutputter(IOutputter* outputter) = 0;
	virtual void setInputter(IInputter* inputter) = 0;
	virtual void createFiles(const std::string& sourceClasses, const std::string& sourceObjects,
							const std::string& testClasses, const std::string& testObjects) = 0;
	virtual const std::string getName() const = 0;
};

#endif /* IMAKEFILECREATOR_H_ */
