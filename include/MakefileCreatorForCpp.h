/**
 * MakefileMakerForCpp.h
 *
 * This class makes a Makefile and four related files for c++ language.
 *
 *  Created on: 2013/08/24
 *      Author: furukawayoshihiro
 */

#ifndef MAKEFILECREATORFORCPP_H_
#define MAKEFILECREATORFORCPP_H_

#include "IMakefileCreator.h"
#include "SubMakefileCreator.h"

class MakefileCreatorForCpp: public IMakefileCreator {
protected:
	IOutputter* outputter_;
	IInputter* inputter_;
	std::string targetName_;
	std::string targetNameForTest_;

protected:
	MakefileCreatorForCpp();

public:
	MakefileCreatorForCpp(std::string name);
	virtual ~MakefileCreatorForCpp();
	virtual void setOutputter(IOutputter* outputter);
	virtual void setInputter(IInputter* inputter);
	virtual void createFiles(const std::string& sourceClasses, const std::string& sourceObjects,
							const std::string& testClasses, const std::string& testObjects);
	virtual const std::string getName() const { return "MakefileCreatorForCpp"; };

private:
	std::string createMakefileContents();
	SubMakefileCreator subCreator;
};

#endif /* MAKEFILECREATORFORCPP_H_ */
