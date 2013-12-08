/**
 * SubMakefileCreator.h
 *
 *  Created on: 2013/11/26
 *      Author: M825504
 */

#ifndef SUBMAKEFILECREATOR_H_
#define SUBMAKEFILECREATOR_H_

#include <string>

#include "IOutputter.h"
#include "IInputter.h"

class SubMakefileCreator {
public:
	SubMakefileCreator();
	virtual ~SubMakefileCreator();
	void setOutputter(IOutputter* outputter);
	void setInputter(IInputter* inputter);
	void createFiles(const std::string& sourceClasses, const std::string& sourceObjects,
			const std::string& testClasses, const std::string& testObjects);

protected:
	IOutputter* outputter_;
	IInputter* inputter_;

private:
	std::string createProductionSources( const std::string& sourceClasses );
	std::string createProductionObjects( const std::string& sourceObjects );
	std::string createTestSources( const std::string& testClasses );
	std::string createTestObjects( const std::string& testObjects );
};

#endif /* SUBMAKEFILECREATOR_H_ */
