/**
 * FileMakerList.h
 *
 *  Created on: 2013/08/15
 *      Author: furukawayoshihiro
 */

#ifndef FILEMAKERLIST_H_
#define FILEMAKERLIST_H_

#include <vector>
#include "IClassFileMaker.h"

typedef std::string const (IClassFileMaker::*PFUNC)() const;

class FileMakerList {
public:
	//! コンストラクタ
	FileMakerList();
	//! デストラクタ
	virtual ~FileMakerList();
	//! クラスのスケルトンを生成するオブジェクトをリストに追加する
	/*!
	 * \param fileMaker クラスのスケルトンを生成するオブジェクト
	 */
	void addClass(IClassFileMaker* fileMaker);
	//! テストクラスのスケルトンを生成するオブジェクトをリストに追加する
	/*!
	 * \param fileMaker テストクラスのスケルトンを生成するオブジェクト
	 */
	void addTestClass(IClassFileMaker* fileMaker);
	//! クラス及びテストクラスのスケルトンを生成する
	void createFiles();
	//! コマンドライン引数で指定されたクラス名からクラスのファイル名のリストを生成する
	/*!
	 * \return クラスのファイル名のリスト
	 */
	std::string getClassFileList();
	//! コマンドライン引数で指定されたクラス名からクラスのオブジェクトファイルのファイル名のリストを生成する
	/*!
	 * \return クラスのオブジェクトファイルのファイル名のリスト
	 */
	std::string getObjectFileList();
	//! コマンドライン引数で指定されたクラス名からテストクラスのファイル名のリストを生成する
	/*!
	 * \return テストクラスのファイル名のリスト
	 */
	std::string getTestClassFileList();
	//! コマンドライン引数で指定されたクラス名からテストクラスのオブジェクトファイルのファイル名のリストを生成する
	/*!
	 * \return テストクラスのオブジェクトファイルのファイル名のリスト
	 */
	std::string getTestObjectFileList();

protected:
	std::vector<IClassFileMaker*> classFileMaker_; //!< クラスのスケルトンを生成するオブジェクトのリスト
	std::vector<IClassFileMaker*> testClassFileMaker_; //!< テストクラスのスケルトンを生成するオブジェクトのリスト

	//! クラスのスケルトンを生成するオブジェクトのリストを破棄する
	void destroyClassList();
	//! テストクラスのスケルトンを生成するオブジェクトのリストを破棄する
	void destroyTestClassList();

private:
	//! オブジェクトのリストを破棄する
	/*!
	 * \param list スケルトンを生成するオブジェクトのリスト
	 */
	void destroyList( std::vector<IClassFileMaker*>& list );
	//! オブジェクトのリストを舐めてファイルを生成する
	/*!
	 * \param list スケルトンを生成するオブジェクトのリスト
	 */
	void conductToCreate( std::vector<IClassFileMaker*>& list );
	//! オブジェクトのリストを舐めてメソッドを実行する
	/*!
	 * \param fileMaker スケルトンを生成するオブジェクトのリスト
	 * \param func 実行するメソッドの関数ポインタ
	 */
	std::string executeMethodIterativery( std::vector<IClassFileMaker*>& fileMaker, PFUNC func );
};

#endif /* FILEMAKERLIST_H_ */
