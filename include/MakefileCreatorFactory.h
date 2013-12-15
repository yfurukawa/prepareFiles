/**
 * MakefileCreatorFactory.h<br>
 * MakefileCreatorのオブジェクトを生成する
 *
 * C又はC++用のMakefileCreatorオブジェクトを生成する
 *
 *  Created on: 2013/09/26
 *      Author: furukawayoshihiro
 */

#ifndef MAKEFILECREATORFACTORY_H_
#define MAKEFILECREATORFACTORY_H_

#include "CommandLineArgumentsParser.h"
class IMakefileCreator;

class MakefileCreatorFactory {
public:
	//! コンストラクタ
	/*!
	 * \param parser コマンドライン引数のパーサオブジェクト
	 */
	MakefileCreatorFactory(CommandLineArgumentsParser* parser);
	//! デストラクタ
	virtual ~MakefileCreatorFactory();
	//! 言語に合わせたMakefileCreatorオブジェクトを生成する
	/*!
	 * \return MakefileCreatorオブジェクト
	 */
	IMakefileCreator* createMakefileCreator();

protected:
	CommandLineArgumentsParser* parser_; //!< コマンドライン引数のパーサオブジェクト

private:
	//! デフォルトコンストラクタ
	MakefileCreatorFactory();
};

#endif /* MAKEFILECREATORFACTORY_H_ */
