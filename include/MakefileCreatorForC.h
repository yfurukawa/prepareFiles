/**
 * MakefileCreatorForC.h<br>
 * C言語用のMakefileを生成する
 *
 * C言語用のMakefile及びその関連ファイル郡を生成する
 *
 *  Created on: 2013/09/28<br>
 *      Author: furukawayoshihiro
 */

#ifndef MAKEFILECREATORFORC_H_
#define MAKEFILECREATORFORC_H_

#include <string>

#include "IMakefileCreator.h"
#include "SubMakefileCreator.h"

class MakefileCreatorForC: public IMakefileCreator {
public:
	//! コンストラクタ
	/*!
	 * \param targetName 実行ファイル名
	 */
	MakefileCreatorForC(std::string targetName);
	//! デストラクタ
	virtual ~MakefileCreatorForC();
	//! 出力用オブジェクトを設定する
	/*!
	 * \param outputter 出力用オブジェクト
	 */
	virtual void setOutputter(IOutputter* outputter);
	//! 入力用オブジェクトを設定する
	/*!
	 * \param inputter 入力用オブジェクト
	 */
	virtual void setInputter(IInputter* inputter);
	//! Makefile及びその関連ファイル群を生成する
	/*!
	 * \param sourceClasses モジュールのソースファイルの一覧
	 * \param sourceObject モジュールのオブジェクトファイルの一覧
	 * \param testClasses テストクラスのソースファイルの一覧
	 * \param testObjects テストクラスのオブジェクトファイルの一覧
	 */
	virtual void createFiles(const std::string& sourceClasses, const std::string& sourceObjects,
							const std::string& testClasses, const std::string& testObjects);
	//! クラス名を返す（テスタビリティ向上用メソッド）
	/*!
	 * \return クラス名
	 */
	virtual const std::string getName() const { return "MakefileCreatorForC"; };

protected:
	//! デフォルトコンストラクタ
	MakefileCreatorForC();

	IOutputter* outputter_; //!< 出力用オブジェクト
	IInputter* inputter_; //!< 入力用オブジェクト
	std::string targetName_; //!< 実行ファイル名
	std::string targetNameForTest_; //!< ユニットテスト用実行ファイル名

private:
	//! Makefileの内容を生成する
	/*!
	 * \return Makefileの内容
	 */
	std::string createMakefileContents();
	SubMakefileCreator subCreator_; //!< 関連ファイルの生成用オブジェクト
};

#endif /* MAKEFILECREATORFORC_H_ */
