/**
 * ClassFileMaker.h<br>
 * c++言語用のスケルトンを作成する
 *
 * コンストラクタ引数で渡されたクラス名からソース、ヘッダ及びオブジェクトの
 * 各ファイル名を生成すると共に、ソースコードとヘッダファイルの
 * スケルトンを生成する
 *
 *  Created on: 2013/08/13<br>
 *      Author: furukawayoshihiro
 */

#ifndef CLASSFILEMAKER_H_
#define CLASSFILEMAKER_H_

#include <iostream>
#include "IClassFileMaker.h"
#include "IOutputter.h"

class ClassFileMaker: public IClassFileMaker {
public:
	 //! コンストラクタ
	/*!
	 * \param name モジュール名
	 */
	ClassFileMaker( std::string name );
	//! デストラクタ
	virtual ~ClassFileMaker();
	//! コンストラクタ引数で渡されたクラスのヘッダ及びソースファイルを生成する
	virtual void createFiles();
	//! コンストラクタ引数で渡されたモジュール名を返す
	/*!
	 * \return コンストラクタ引数で渡されたモジュール名
	 */
	virtual const std::string getName() const;
	//! ソースコードのファイル名を返す
	/*!
	 * \return ソースファイル名
	 */
	virtual const std::string getClassName() const;
	//! コンパイルで生成されるオブジェクトファイル名を返す
	/*!
	 * \return オブジェクトファイル名
	 */
	virtual const std::string getObjectName() const;
	//! コンテンツを出力するオブジェクトを設定する
	virtual void setOutputter(IOutputter* outputter);

protected:
	const std::string name_; //!< コンストラクタ引数で渡されたクラス名
	const std::string className_; //!< ソースファイル名
	const std::string headerName_; //!< ヘッダファイル名
	const std::string objectName_; //!< オブジェクトファイル名（*.o）
	std::string headerSkeleton_; //!< ヘッダファイルのスケルトンコンテンツ
	std::string cppSkeleton_; //!< ソースファイルのスケルトンコンテンツ
	IOutputter* outputter_; //!< 出力用オブジェクト

	//! デフォルトコンストラクタ
	ClassFileMaker();


private:
	//! ヘッダファイルのコンテンツを作成する
	virtual void createHeaderFile();
	//! ソースファイルのコンテンツを作成する
	virtual void createImplementsFile();
	//! 出力用オブジェクトを保持しているかどうか返す
	/*!
	 * \return出力用オブジェクトの有無　（true：保持　false:未保持）
	 */
	bool isOutputterSet();
};

#endif /* CLASSFILEMAKER_H_ */
