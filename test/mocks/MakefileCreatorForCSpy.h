/**
 * MakefileCreatorForCSpy.h
 *
 *  Created on: 2013/09/28
 *      Author: furukawayoshihiro
 */

#ifndef MAKEFILECREATORFORCSPY_H_
#define MAKEFILECREATORFORCSPY_H_

#include <string>

#include "MakefileCreatorForC.h"

class MakefileCreatorForCSpy: public MakefileCreatorForC {
private:
	MakefileCreatorForCSpy();
public:
	MakefileCreatorForCSpy(std::string targetName);
	virtual ~MakefileCreatorForCSpy();
	const IOutputter* getOutputter() const;

};

#endif /* MAKEFILECREATORFORCSPY_H_ */
