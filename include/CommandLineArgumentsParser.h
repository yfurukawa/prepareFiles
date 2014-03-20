/**
 * CommandLineArgumentsParser.h<br>
 * コマンドライン引数をパースする
 *
 * コマンドライン引数をパースして引数に正しいオプションが指定されていること
 * をチェックすると共にクラス名をClassFileMakerFactoryに渡す
 *
 *  Created on: 2013/08/14<br>
 *      Author: furukawayoshihiro
 */

#ifndef COMMANDLINEARGUMENTSPARSER_H_
#define COMMANDLINEARGUMENTSPARSER_H_

#include <string>
#include <vector>
#include <stdexcept>

class CommandLineArgumentsParser {
public:
	//! コンストラクタ
	CommandLineArgumentsParser();
	//! デストラクタ
	virtual ~CommandLineArgumentsParser();
	//! コマンドライン引数をパースする
	/*!
	 * \param argc コマンド名を含むコマンドライン引数の数
	 * \param argv コマンド名を含むコマンドライン引数の文字列
	 */
	void parseArguments(int argc, char** argv) throw (std::invalid_argument);
	//! 生成すべき対象言語を返す
	/*!
	 * \return 言語（C又はC++）
	 */
	std::string getLanguage();
	//! 実行ファイルのファイル名を返す
	/*!
	 * \return 実行ファイル名（デフォルト：a.out）
	 */
	std::string getTargetName();
	//! クラス名のリストをvector型のコンテナに入れて返す
	/*!
	 * \return クラス名のリスト
	 */
	std::vector<std::string> getClassName();
	//! Makefile生成の要否を返す
	/*!
	 * \return 要否（true：要、false：否）
	 */
	const bool isNecessaryToCreateMakefile() const;

protected:
	std::vector<std::string>(className_); //!< スケルトンを生成するクラス名のリスト
	std::string language_; //!< 生成対象の言語
	std::string targetName_; //!< 実行ファイル名
	bool needToCreateMakefile_; //!< Makefile生成の要否

private:
	//! コマンドライン引数の数が規定数に達しているか
	/*!
	 * \param argc コマンド名を含むコマンドライン引数の数
	 * \return 判定結果（true：達している、false：達していない）
	 */
	bool isArgumentEnough(int argc);
	//! 生成する言語の設定プションが複数含まれているか
	/*!
	 * \param argc コマンド名を含むコマンドライン引数の数
	 * \param argv コマンド名を含むコマンドライン引数の文字列
	 * \return 判定結果（true：含まれている、false：含まれていない）
	 */
	bool isContainLanguageSettingMultiple(int argc, char** argv);
	//! 規定外のオプションが含まれているか
	/*!
	 * \param argc コマンド名を含むコマンドライン引数の数
	 * \param argv コマンド名を含むコマンドライン引数の文字列
	 * \return 判定結果（true：含まれている、false：含まれていない）
	 */
	bool isThereUnkownOption(int argc, char** argv);
	//! オプションかどうか判定する
	/*!
	 * \param argument 判定対象の引数
	 * \return 判定結果（true：オプション、false：オプションではない）
	 */
	bool isOption(std::string argument);
	//! 正しいオプションかどうか判定する
	/*!
	 * \param argument 判定対象のオプション
	 * \return 判定結果（true：正しい、false：正しくない）
	 */
	bool isCorrectOption(std::string argument);
	//! 生成対象の言語がc++かどうか
	/*!
	 * \param argument 判定対象のオプション
	 * \return 判定結果（true：c++、false：c++ではない）
	 */
	bool isLanguageCpp(std::string argument);
	//! 生成対象の言語がcかどうか
	/*!
	 * \param argument 判定対象のオプション
	 * \return 判定結果（true：c、false：cではない）
	 */
	bool isLanguageC(std::string argument);
	//! 実行ファイルのファイル名指定オプションかどうか
	/*!
	 * \param argument 判定対象のオプション
	 * \return 判定結果（true：実行ファイルのファイル名指定オプション、
	 * false：実行ファイルのファイル名指定オプションではない）
	 */
	bool isTargetNameOption(std::string argument);
	//! Makefileを生成する必要があるかどうか
	/*!
	 * \param argument 判定対象のオプション
	 * \return 判定結果（true：生成する、false：生成しない）
	 */
	bool isMakefileCreatingOption(std::string argument);
	//! Makefileにクラスを追加するだけかどうか
	/*!
	 * \param argument 判定対象のオプション
	 * \return 判定結果（true：追加するのみ、false：Makefileを再生成する
	 */
	bool isAppendOption(std::string argument);
	//! コマンドライン引数をパースしてオプションを判定する
	/*!
	 * \param argument コマンドライン引数
	 */
	void parseOption(std::string argument);
};

#endif /* COMMANDLINEARGUMENTSPARSER_H_ */
