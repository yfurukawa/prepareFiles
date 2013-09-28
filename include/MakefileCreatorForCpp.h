/*
 * MakefileMakerForCpp.h
 *
 *  Created on: 2013/08/24
 *      Author: furukawayoshihiro
 */

#ifndef MAKEFILECREATORFORCPP_H_
#define MAKEFILECREATORFORCPP_H_

#include "IMakefileCreator.h"

class MakefileCreatorForCpp: public IMakefileCreator {
protected:
	IOutputter* outputter_;
	std::string sourceClasses_;
	std::string testClasses_;
	std::string targetName_;
	std::string targetNameForTest_;

protected:
	MakefileCreatorForCpp();

public:
	MakefileCreatorForCpp(std::string name);
	virtual ~MakefileCreatorForCpp();
	virtual void setOutputter(IOutputter* outputter);
	virtual void setSourceClasses(std::string sourceClass);
	virtual void setTestClasses(std::string testClasses);
	virtual void createFiles(const std::string sourceClasses, const std::string sourceObjects,
							const std::string testClasses, const std::string testObjects);
	virtual const std::string getName() const { return "MakefileCreatorForCpp"; };

private:
	std::string createExpectedMakefileContents(const std::string sourceClasses,
			const std::string sourceObjects, const std::string testClasses,
			const std::string testObjects);
};

#endif /* MAKEFILECREATORFORCPP_H_ */
