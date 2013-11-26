/*
 * MakefileCreatorForC.h
 *
 *  Created on: 2013/09/28
 *      Author: furukawayoshihiro
 */

#ifndef MAKEFILECREATORFORC_H_
#define MAKEFILECREATORFORC_H_

#include <string>

#include "IMakefileCreator.h"

class MakefileCreatorForC: public IMakefileCreator {
protected:
	IOutputter* outputter_;
	std::string sourceClasses_;
	std::string testClasses_;
	std::string targetName_;
	std::string targetNameForTest_;

protected:
	MakefileCreatorForC();

public:
	MakefileCreatorForC(std::string name);
	virtual ~MakefileCreatorForC();
	virtual void setOutputter(IOutputter* outputter);
	virtual void createFiles(const std::string& sourceClasses, const std::string& sourceObjects,
							const std::string& testClasses, const std::string& testObjects);
	virtual const std::string getName() const { return "MakefileCreatorForC"; };

private:
	std::string createExpectedMakefileContents(const std::string& sourceClasses,
			const std::string& sourceObjects, const std::string& testClasses,
			const std::string& testObjects);
};

#endif /* MAKEFILECREATORFORC_H_ */
