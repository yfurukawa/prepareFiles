/**
 * CFileMakerSpy.h
 *
 *  Created on: 2013/09/26
 *      Author: furukawayoshihiro
 */

#ifndef CFILEMAKERSPY_H_
#define CFILEMAKERSPY_H_

#include "CFileMaker.h"

class CFileMakerSpy: public CFileMaker {
protected:
	CFileMakerSpy();
public:
	CFileMakerSpy(std::string name);
	virtual ~CFileMakerSpy();
	const std::string getHeaderName() const;
	const std::string getHeaderSkeleton() const;
	const std::string getCppSkeleton() const;
	const IOutputter* getOutputter() const;
};

#endif /* CFILEMAKERSPY_H_ */
