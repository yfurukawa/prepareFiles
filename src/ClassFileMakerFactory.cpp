/**
 * ClassFileMakerFactory.cpp
 *
 *  Created on: 2013/09/22
 *      Author: furukawayoshihiro
 */

#include "ClassFileMakerFactory.h"
#include "CommandLineArgumentsParser.h"
#include "ClassFileMaker.h"
#include "CFileMaker.h"
#include "TestClassFileMaker.h"
#include "TestClassFileMakerForC.h"
#include "FileDAO.h"
#include "FileMakerList.h"

ClassFileMakerFactory::ClassFileMakerFactory() : parser_(NULL) {
	// TODO

}

ClassFileMakerFactory::~ClassFileMakerFactory() {
	// TODO Auto-generated destructor stub
}

ClassFileMakerFactory::ClassFileMakerFactory(CommandLineArgumentsParser* parser) : parser_(parser) {
}

void ClassFileMakerFactory::buildClassList(FileMakerList* list){
	classes_ = parser_->getClassName();

	if(parser_->getLanguage() == "cpp") {
		appendClassName< ClassFileMaker >( list );
		appendTestClassName< TestClassFileMaker >( list );
	}
	else {
		appendClassName< CFileMaker >( list );
		appendTestClassName<TestClassFileMakerForC>( list );
	}
}

/////////////////////////////////////////////////////////////////////
template< typename T >
IClassFileMaker* ClassFileMakerFactory::createFileMaker(std::string name) {
	IClassFileMaker* fileMaker = new T(name);
	fileMaker->setOutputter(new FileDAO());
	return fileMaker;
}

template < typename T >
void ClassFileMakerFactory::appendClassName( FileMakerList*& list ){
	for ( std::vector<std::string>::iterator classNameOfCreating = classes_.begin();
			classNameOfCreating != classes_.end(); ++classNameOfCreating ) {
		list->addClass( createFileMaker < T > ( *classNameOfCreating ) );
	}
}

template <typename T>
void ClassFileMakerFactory::appendTestClassName( FileMakerList*& list ){
	for ( std::vector<std::string>::iterator classNameOfCreating = classes_.begin();
			classNameOfCreating != classes_.end(); ++classNameOfCreating ) {
		list->addTestClass( createFileMaker < T > ( *classNameOfCreating ) );
	}
}

