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

class CommandLineArgumentsParser;
class FileMakerList;
class IMakefileCreator;

class ClassFileMakerFactory {
private:
	ClassFileMakerFactory();

public:
	ClassFileMakerFactory(CommandLineArgumentsParser* parser);
	virtual ~ClassFileMakerFactory();
	void buildClassList(FileMakerList* list);

protected:
	CommandLineArgumentsParser* parser_;
	std::vector<std::string> classes_;
	template <typename T> IClassFileMaker* createFileMaker(std::string className);
	template <typename T> void appendClassName( FileMakerList*& list );
	template <typename T> void appendTestClassName( FileMakerList*& list );
};

#endif /* CLASSFILEMAKERFACTORY_H_ */
