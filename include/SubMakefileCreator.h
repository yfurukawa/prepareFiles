/**
 * SubMakefileCreator.h<br>
 * Makefileの関連ファイルを生成する
 *
 * Makefileにインクルードされるソースファイルやオブジェクトファイルの一覧を
 * 記述したファイルを生成する
 *
 *  Created on: 2013/11/26<br>
 *      Author: yfurukawa
 */

#ifndef SUBMAKEFILECREATOR_H_
#define SUBMAKEFILECREATOR_H_

#include <string>

#include "IOutputter.h"
#include "IInputter.h"

class SubMakefileCreator {
public:
	//! コンストラクタ
	SubMakefileCreator();
	//! デストラクタ
	virtual ~SubMakefileCreator();
	//! 出力用オブジェクトを設定する
	/*!
	 * \param outputter 出力用オブジェクト
	 */
	void setOutputter(IOutputter* outputter);
	//! 入力用オブジェクトを設定する
	/*!
	 * \param inputter 入力用オブジェクト
	 */
	void setInputter(IInputter* inputter);
	//! Makefileの関連ファイル群を生成する
	/*!
	 * \param sourceClasses クラスのソースファイルの一覧
	 * \param sourceObject クラスのオブジェクトファイルの一覧
	 * \param testClasses テストクラスのソースファイルの一覧
	 * \param testObjects テストクラスのオブジェクトファイルの一覧
	 */
	void createFiles(const std::string& sourceClasses, const std::string& sourceObjects,
			const std::string& testClasses, const std::string& testObjects);

protected:
	IOutputter* outputter_; //!< 出力用オブジェクト
	IInputter* inputter_; //!< 入力用オブジェクト

	//! 既存のファイルにクラスを追加する
	/*!
	 * \param appendNames 追加するクラス名の一覧
	 * \param fileName 追加対象のファイル名
	 */
	void appendClass( const std::string& appendNames, char* fileName );

private:
	//! Makefileのマクロとプロダクションクラスのソースファイルの一覧を生成する
	/*!
	 * \param sourceClasses クラスのソースファイルの一覧
	 */
	std::string createProductionSources( const std::string& sourceClasses );
	//! Makefileのマクロとプロダクションクラスのオブジェクトファイルの一覧を生成する
	/*!
	 * \param sourceObject クラスのオブジェクトファイルの一覧
	 */
	std::string createProductionObjects( const std::string& sourceObjects );
	//! Makefileのマクロとテストクラスのソース・ファイルの一覧を生成する
	/*!
	 * \param testClasses テストクラスのソースファイルの一覧
	 */
	std::string createTestSources( const std::string& testClasses );
	//! Makefileのマクロとテストクラスのオブジェクトファイルの一覧を生成する
	/*!
	 * \param testObjects テストクラスのオブジェクトファイルの一覧
	 */
	std::string createTestObjects( const std::string& testObjects );
};

#endif /* SUBMAKEFILECREATOR_H_ */
