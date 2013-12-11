/**
 * CFileMaker.h
 *
 *  Created on: 2013/09/26
 *      Author: furukawayoshihiro
 */

#ifndef CFILEMAKER_H_
#define CFILEMAKER_H_

#include <string>

#include "IClassFileMaker.h"

class CFileMaker: public IClassFileMaker {
protected:
	const std::string name_;
	const std::string moduleName_;
	const std::string headerName_;
	const std::string objectName_;
	std::string headerSkeleton_;
	std::string cSkeleton_;
	IOutputter* outputter_;
protected:
	CFileMaker();
public:
	CFileMaker(std::string name);
	virtual ~CFileMaker();
	virtual void createFiles();
	virtual const std::string getClassName() const;
	virtual const std::string getName() const;
	virtual const std::string getObjectName() const;
	virtual void setOutputter(IOutputter* outputter);

private:
	virtual void createHeaderFile();
	virtual void createImplementsFile();
	bool isOutputterSet();
};

#endif /* CFILEMAKER_H_ */
