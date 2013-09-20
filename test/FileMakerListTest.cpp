/*
 * FileMakerListTest.cpp
 *
 *  Created on: 2013/08/15
 *      Author: furukawayoshihiro
 */

#include "FileMakerListTest.h"
#include "mocks/ClassFileMakerSpy.h"
#include "mocks/TestClassFileMakerSpy.h"
#include "IClassFileMaker.h"
#include "mocks/ClassFileMakerMock.h"

FileMakerListTest::FileMakerListTest() : sut(NULL) {
	// TODO �����������ꂽ�R���X�g���N�^�[�E�X�^�u

}

FileMakerListTest::~FileMakerListTest() {
	// TODO Auto-generated destructor stub
}

void FileMakerListTest::SetUp() {
	sut = new FileMakerListSpy();
}

void FileMakerListTest::TearDown() {
	delete sut;
}

TEST_F(FileMakerListTest, addListAClass) {
	IClassFileMaker* fileMaker = new ClassFileMakerSpy("Hoge");
	sut->addClass(fileMaker);

	EXPECT_EQ("Hoge", sut->getClassFileMaker()->getName());
}

TEST_F(FileMakerListTest, addListSeveralClasses) {
	IClassFileMaker* fileMaker1 = new ClassFileMakerSpy("Hoge");
	IClassFileMaker* fileMaker2 = new ClassFileMakerSpy("Fuga");
	IClassFileMaker* fileMaker3 = new ClassFileMakerSpy("Foo");
	sut->addClass(fileMaker1);
	sut->addClass(fileMaker2);
	sut->addClass(fileMaker3);

	EXPECT_EQ("Hoge", sut->getClassFileMaker()->getName());
	EXPECT_EQ("Fuga", sut->getClassFileMaker()->getName());
	EXPECT_EQ("Foo", sut->getClassFileMaker()->getName());
}

TEST_F(FileMakerListTest, destoryListedClass) {
	IClassFileMaker* fileMaker1 = new ClassFileMakerSpy("Hoge");
	IClassFileMaker* fileMaker2 = new ClassFileMakerSpy("Fuga");
	IClassFileMaker* fileMaker3 = new ClassFileMakerSpy("Foo");
	sut->addClass(fileMaker1);
	sut->addClass(fileMaker2);
	sut->addClass(fileMaker3);

	EXPECT_EQ(3, sut->getNumberOfClassFileMaker());
	sut->destroyClassList();
	EXPECT_EQ(0, sut->getNumberOfClassFileMaker());
}

TEST_F(FileMakerListTest, addListATestClass) {
	IClassFileMaker* fileMaker = new TestClassFileMakerSpy("Hoge");
	sut->addTestClass(fileMaker);

	EXPECT_EQ("HogeTest", sut->getTestClassFileMaker()->getName());
}

TEST_F(FileMakerListTest, addListSeveralTestClasses) {
	IClassFileMaker* fileMaker1 = new TestClassFileMakerSpy("Hoge");
	IClassFileMaker* fileMaker2 = new TestClassFileMakerSpy("Fuga");
	IClassFileMaker* fileMaker3 = new TestClassFileMakerSpy("Foo");
	sut->addTestClass(fileMaker1);
	sut->addTestClass(fileMaker2);
	sut->addTestClass(fileMaker3);

	EXPECT_EQ("HogeTest", sut->getTestClassFileMaker()->getName());
	EXPECT_EQ("FugaTest", sut->getTestClassFileMaker()->getName());
	EXPECT_EQ("FooTest", sut->getTestClassFileMaker()->getName());
}

TEST_F(FileMakerListTest, destoryListedTestClass) {
	IClassFileMaker* fileMaker1 = new TestClassFileMakerSpy("Hoge");
	IClassFileMaker* fileMaker2 = new TestClassFileMakerSpy("Fuga");
	IClassFileMaker* fileMaker3 = new TestClassFileMakerSpy("Foo");
	sut->addTestClass(fileMaker1);
	sut->addTestClass(fileMaker2);
	sut->addTestClass(fileMaker3);

	EXPECT_EQ(3, sut->getNumberOfTestClassFileMaker());
	sut->destroyTestClassList();
	EXPECT_EQ(0, sut->getNumberOfTestClassFileMaker());
}

TEST_F(FileMakerListTest, conductAClassToCreateFiles) {
	IClassFileMaker* fileMaker = new ClassFileMakerMock();
	IClassFileMaker* testFileMaker = new ClassFileMakerMock();
	sut->addClass(fileMaker);
	sut->addTestClass(testFileMaker);

	sut->createFiles();

	EXPECT_EQ(1, dynamic_cast<ClassFileMakerMock*>(fileMaker)->getNumberOfCreatedFile());
	EXPECT_EQ(1, dynamic_cast<ClassFileMakerMock*>(testFileMaker)->getNumberOfCreatedFile());
}

TEST_F(FileMakerListTest, getClassFileList) {
	IClassFileMaker* fileMaker1 = new ClassFileMakerSpy("Hoge");
	IClassFileMaker* fileMaker2 = new ClassFileMakerSpy("Fuga");
	IClassFileMaker* fileMaker3 = new ClassFileMakerSpy("Foo");
	sut->addClass(fileMaker1);
	sut->addClass(fileMaker2);
	sut->addClass(fileMaker3);

	EXPECT_EQ(3, sut->getNumberOfClassFileMaker());
	EXPECT_EQ("Hoge.cpp Fuga.cpp Foo.cpp ", sut->getClassFileList());
}

TEST_F(FileMakerListTest, getObjectFileList) {
	IClassFileMaker* fileMaker1 = new ClassFileMakerSpy("Hoge");
	IClassFileMaker* fileMaker2 = new ClassFileMakerSpy("Fuga");
	IClassFileMaker* fileMaker3 = new ClassFileMakerSpy("Foo");
	sut->addClass(fileMaker1);
	sut->addClass(fileMaker2);
	sut->addClass(fileMaker3);

	EXPECT_EQ(3, sut->getNumberOfClassFileMaker());
	EXPECT_EQ("Hoge.o Fuga.o Foo.o ", sut->getObjectFileList());
}

TEST_F(FileMakerListTest, getTestClassFileList) {
	IClassFileMaker* fileMaker1 = new TestClassFileMakerSpy("Hoge");
	IClassFileMaker* fileMaker2 = new TestClassFileMakerSpy("Fuga");
	IClassFileMaker* fileMaker3 = new TestClassFileMakerSpy("Foo");
	sut->addTestClass(fileMaker1);
	sut->addTestClass(fileMaker2);
	sut->addTestClass(fileMaker3);

	EXPECT_EQ(3, sut->getNumberOfTestClassFileMaker());
	EXPECT_EQ("HogeTest.cpp FugaTest.cpp FooTest.cpp ", sut->getTestClassFileList());
	sut->destroyTestClassList();
}

TEST_F(FileMakerListTest, getTestObjectFileList) {
	IClassFileMaker* fileMaker1 = new TestClassFileMakerSpy("Hoge");
	IClassFileMaker* fileMaker2 = new TestClassFileMakerSpy("Fuga");
	IClassFileMaker* fileMaker3 = new TestClassFileMakerSpy("Foo");
	sut->addTestClass(fileMaker1);
	sut->addTestClass(fileMaker2);
	sut->addTestClass(fileMaker3);

	EXPECT_EQ(3, sut->getNumberOfTestClassFileMaker());
	EXPECT_EQ("HogeTest.o FugaTest.o FooTest.o ", sut->getTestObjectFileList());
	sut->destroyTestClassList();
}
