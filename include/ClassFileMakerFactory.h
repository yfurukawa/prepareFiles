/*
 * ClassFileMakerFactory.h
 *
 *  Created on: 2013/09/22
 *      Author: furukawayoshihiro
 */

#ifndef CLASSFILEMAKERFACTORY_H_
#define CLASSFILEMAKERFACTORY_H_

#include <vector>
#include "IClassFileMaker.h"
//#include "CommandLineArgumentsParser.h"

class CommandLineArgumentsParser;
class FileMakerList;
class IMakefileCreator;

class ClassFileMakerFactory {
private:
	ClassFileMakerFactory();
protected:
	CommandLineArgumentsParser* parser_;
	std::vector<std::string> classes_;
public:
	ClassFileMakerFactory(CommandLineArgumentsParser* parser);
	virtual ~ClassFileMakerFactory();
	void buildClassList(FileMakerList* list);
	IMakefileCreator* createMakefile();

protected:
	template <typename T> IClassFileMaker* createFileMaker(std::string className);
};

#endif /* CLASSFILEMAKERFACTORY_H_ */
