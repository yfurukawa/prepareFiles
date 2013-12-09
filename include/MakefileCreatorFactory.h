/*
 * MakefileCreatorFactory.h
 *
 *  Created on: 2013/09/26
 *      Author: furukawayoshihiro
 */

#ifndef MAKEFILECREATORFACTORY_H_
#define MAKEFILECREATORFACTORY_H_

#include "CommandLineArgumentsParser.h"
class IMakefileCreator;

class MakefileCreatorFactory {
private:
	MakefileCreatorFactory();
protected:
	CommandLineArgumentsParser* parser_;
public:
	MakefileCreatorFactory(CommandLineArgumentsParser* parser);
	virtual ~MakefileCreatorFactory();
	IMakefileCreator* createMakefileCreator();
};

#endif /* MAKEFILECREATORFACTORY_H_ */
