/*
 * MakefileMakerForCppTest.cpp
 *
 *  Created on: 2013/08/24
 *      Author: furukawayoshihiro
 */

#include <iostream>

#include "MakefileCreatorForCppTest.h"
#include "mocks/OutputterMock.h"

MakefileCreatorForCppTest::MakefileCreatorForCppTest() {
	// TODO �����������ꂽ�R���X�g���N�^�[�E�X�^�u
	sut = new MakefileCreatorForCppSpy("targetName");
}

MakefileCreatorForCppTest::~MakefileCreatorForCppTest() {
	// TODO Auto-generated destructor stub
	delete sut;
}

TEST_F(MakefileCreatorForCppTest, setOutputter) {
	IOutputter* outputter = new OutputterMock();
	sut->setOutputter( outputter );

	EXPECT_EQ(outputter, sut->getOutputter());
}

TEST_F(MakefileCreatorForCppTest, setSourceClass) {
	std::string source("Hoge.cpp Fuga.cpp Foo.cpp");

	sut->setSourceClasses(source);
	EXPECT_EQ(source, sut->getSourceClasses());
}

TEST_F(MakefileCreatorForCppTest, setTestClass) {
	std::string test("HogeTest.cpp Fuga.cpp Foo.cpp");

	sut->setTestClasses(test);
	EXPECT_EQ(test, sut->getTestClasses());
}

TEST_F(MakefileCreatorForCppTest, createMakefile) {
	OutputterMock* outputter = new OutputterMock();
	sut->setOutputter( outputter );

	std::string expected = createExpectedMakefileContents("Hoge.cpp Fuga.cpp Foo.cpp", "Hoge.o Fuga.o Foo.o", "HogeTest.cpp Fuga.cpp Foo.cpp", "HogeTest.o Fuga.o Foo.o");

	sut->createFiles("Hoge.cpp Fuga.cpp Foo.cpp", "Hoge.o Fuga.o Foo.o", "HogeTest.cpp Fuga.cpp Foo.cpp", "HogeTest.o Fuga.o Foo.o");
	EXPECT_EQ(expected, outputter->getContents(0));
}

std::string MakefileCreatorForCppTest::createExpectedMakefileContents(std::string source, std::string object, std::string test, std::string testObject) {
	std::string contents;
	contents  = "CC = g++\n";
	contents += "RM = rm -f\n";
	contents += "INCLUDE = -I/usr/incude -I/usr/local/include\n";
	contents += "LIB_DIR = -L/usr/lib -L/usr/local/lib\n";
	contents += "LIB =\n";
	contents += "OPT = -O0 -g3 -Wall -fmessage-length=0\n";
	contents += "TARGET = targetName\n";
	contents += "SRC= " + source + "\n";
	contents += "OBJ= " + object + "\n";
	contents += "\n";
	contents += "all: $(OBJ) main.o\n";
	contents += "\t$(CC) $(INCLUDE) $(LIB_DIR) $(OPT) -o $(TARGET) $(OBJ) main.o";
	contents += "\n";
	contents += "$(OBJ): $(SRC)\n";
	contents += "\t$(CC) $(INCLUDE) $(LIB_DIR) $(OPT) -c $(SRC)\n";
	contents += "\n";
	contents += "main.o: main.cpp\n";
	contents += "\t$(CC) $(INCLUDE) $(LIB_DIR) $(OPT) -c main.cpp";
	contents += "\n";
	contents += "clean:\n";
	contents += "\t$(RM) *.o $(TARGET) $(TEST_TARGET) gmon.out *.gc* *.xml\n";
	contents += "\n";
	contents += "\n";
	contents += "TEST_TARGET = targetNameTest\n";
	contents += "TEST_INCLUDE = -I../test -I.\n";
	contents += "TEST_LIB = -lgtest\n";
	contents += "TEST_OPT = -O0 -g3 -Wall -fmessage-length=0 -pg -fprofile-arcs -ftest-coverage\n";
	contents += "TEST_SRC =" + test + "\n";
	contents += "TEST_OBJ =" + testObject + "\n";
	contents += "\n";
	contents += "test: $(OBJ) $(TEST_OBJ)\n";
	contents += "\t$(CC) $(INCLUDE) $(TEST_INCLUDE) $(LIB_DIR) $(TEST_OPT) -o $(TEST_TARGET) $(OBJ) $(TEST_OBJ) $(LIB) $(TEST_LIB)\n";
	contents += "\n";
	contents += "$(TEST_OBJ): $(TEST_SRC)\n";
	contents += "\t$(CC) $(INCLUDE) $(TEST_INCLUDE) $(LIB_DIR) $(LIB) $(TEST_LIB) $(TEST_OPT) -c $(TEST_SRC)\n";

	return contents;
}