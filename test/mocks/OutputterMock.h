/*
 * OutputterMock.h
 *
 *  Created on: 2013/08/13
 *      Author: furukawayoshihiro
 */

#ifndef OUTPUTTERMOCK_H_
#define OUTPUTTERMOCK_H_

#include <string>
#include <vector>

#include "IOutputter.h"

class OutputterMock: public IOutputter {
private:
	const std::string name_;
	std::vector<std::string> outputName_;
	std::vector<std::string> contents_;
	unsigned int numberOfCall_;

public:
	OutputterMock();
	virtual ~OutputterMock();
	const std::string getName() { return name_; }
	virtual void outputContents( std::string outputName, std::string contents );
	std::string getOutputName(unsigned int index);
	std::string getContents(unsigned int index);
	int getNumberOfCall();
};

#endif /* OUTPUTTERMOCK_H_ */
