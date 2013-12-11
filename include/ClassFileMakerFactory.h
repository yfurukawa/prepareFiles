/**
 * ClassFileMakerFactory.h<br>
 * スケルトンコードを生成するFileMakerオブジェクトのファクトリ
 *
 * 言語に合ったFileMakerオブジェクトをインスタンス化し、
 * FileMakerListに追加する
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
	//! デフォルトコンストラクタ
	ClassFileMakerFactory();

public:
	//! コンストラクタ
	/*!
	 * \param parser コマンドライン引数のパーサ
	 */
	ClassFileMakerFactory(CommandLineArgumentsParser* parser);
	//! デストラクタ
	virtual ~ClassFileMakerFactory();
	//! FileMakerを生成し、FileMakerListに追加する
	/*!
	 * \param list FileMakerListオブジェクト
	 */
	void buildClassList(FileMakerList* list);

protected:
	CommandLineArgumentsParser* parser_; //!< コマンドライン引数のパーサオブジェクト
	std::vector<std::string> classes_; //!< コマンドライン引数で渡されたクラスの一覧

	//! 出力用オブジェクトがセットされたFileMakerオブジェクトを生成する
	/*!
	 * \param className クラス名
	 * \return FileMakerオブジェクト
	 */
	template <typename T> IClassFileMaker* createFileMaker(std::string className);
	//! FileMakerオブジェクトをFileMakerListに追加する
	/*!
	 * \param list FileMakerListオブジェクト
	 */
	template <typename T> void appendClassName( FileMakerList*& list );
	//! テストクラスのFileMakerオブジェクトをFileMakerListに追加する
	/*!
	 * \param list FileMakerListオブジェクト
	 */
	template <typename T> void appendTestClassName( FileMakerList*& list );
};

#endif /* CLASSFILEMAKERFACTORY_H_ */
