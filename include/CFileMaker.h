/**
 * CFileMaker.h<br>
 * c言語用のスケルトンを作成する
 *
 * 引数で渡されたモジュール名からソース、ヘッダ及びオブジェクトの
 * 各ファイル名を生成すると共に、ソースコードとヘッダファイルの
 * スケルトンを生成する
 *
 *  Created on: 2013/09/26<br>
 *      Author: furukawayoshihiro
 */

#ifndef CFILEMAKER_H_
#define CFILEMAKER_H_

#include <string>

#include "IClassFileMaker.h"

class CFileMaker: public IClassFileMaker {
public:
	 //! コンストラクタ
	/*!
	 * \param name モジュール名
	 */
	CFileMaker(std::string name);
	 //! デストラクタ
	virtual ~CFileMaker();
	 //! コンストラクタ引数で渡されたモジュールのヘッダ及びソースファイルを生成する
	virtual void createFiles();
	//! コンストラクタ引数で渡されたモジュール名を返す
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
	const std::string name_; //!< コンストラクタ引数で渡されたモジュール名
	const std::string moduleName_; //!< ソースファイル名
	const std::string headerName_; //!< ヘッダファイル名
	const std::string objectName_; //!< オブジェクトファイル名（*.o）
	std::string headerSkeleton_; //!< ヘッダファイルのスケルトンコンテンツ
	std::string cSkeleton_; //!< ソースファイルのスケルトンコンテンツ
	IOutputter* outputter_; //!< 出力用オブジェクト

	//! デフォルトコンストラクタ
	CFileMaker();

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

#endif /* CFILEMAKER_H_ */
