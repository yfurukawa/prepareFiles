/**
 * SubMakefileCreatorTest.cpp
 *
 *  Created on: 2013/11/26
 *      Author: M825504
 */

#include "SubMakefileCreatorTest.h"
#include "mocks/SubMakefileCreatorSpy.h"
#include "mocks/OutputterMock.h"

SubMakefileCreatorTest::SubMakefileCreatorTest() {
	// TODO 自動生成されたコンストラクター・スタブ
	sut = new SubMakefileCreatorSpy();
}

SubMakefileCreatorTest::~SubMakefileCreatorTest() {
	// TODO Auto-generated destructor stub
	delete sut;
}

TEST_F(SubMakefileCreatorTest, setOutputter) {
	IOutputter* outputter = new OutputterMock();
	sut->setOutputter( outputter );

	EXPECT_EQ(outputter, sut->getOutputter());
}

TEST_F(SubMakefileCreatorTest, createMakefile) {
	OutputterMock* dao = new OutputterMock();
	sut->setOutputter( dao );
	dao->setFileExsist( false );
	sut->setInputter( dao );

	sut->createFiles("Hoge.cpp Fuga.cpp Foo.cpp", "Hoge.o Fuga.o Foo.o", "../test/HogeTest.cpp ../test/FugaTest.cpp ../test/FooTest.cpp", "HogeTest.o FugaTest.o FooTest.o");
	EXPECT_EQ("SRC = Hoge.cpp Fuga.cpp Foo.cpp\n", dao->getContents(0));
	EXPECT_EQ("OBJ = Hoge.o Fuga.o Foo.o\n", dao->getContents(1));
	EXPECT_EQ("TEST_SRC = ../test/testMain.cpp ../test/HogeTest.cpp ../test/FugaTest.cpp ../test/FooTest.cpp\n", dao->getContents(2));
	EXPECT_EQ("TEST_OBJ = testMain.o HogeTest.o FugaTest.o FooTest.o\n", dao->getContents(3));

	delete dao;
}

TEST_F(SubMakefileCreatorTest, appendClassNameToExsistListFile) {
	OutputterMock* dao = new OutputterMock();
	sut->setOutputter( dao );
	dao->setFileExsist( true );
	sut->setInputter( dao );

	sut->createFiles("Hoge.cpp Fuga.cpp Foo.cpp", "Hoge.o Fuga.o Foo.o", "../test/HogeTest.cpp ../test/FugaTest.cpp ../test/FooTest.cpp", "HogeTest.o FugaTest.o FooTest.o");
	EXPECT_EQ("Exsist contents Hoge.cpp Fuga.cpp Foo.cpp\n", dao->getContents(0));
	EXPECT_EQ("Exsist contents Hoge.o Fuga.o Foo.o\n", dao->getContents(1));
	EXPECT_EQ("Exsist contents ../test/HogeTest.cpp ../test/FugaTest.cpp ../test/FooTest.cpp\n", dao->getContents(2));
	EXPECT_EQ("Exsist contents HogeTest.o FugaTest.o FooTest.o\n", dao->getContents(3));

	delete dao;
}
