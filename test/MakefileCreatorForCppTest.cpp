/**
 * MakefileMakerForCppTest.cpp
 *
 *  Created on: 2013/08/24
 *      Author: furukawayoshihiro
 */

#include <iostream>

#include "MakefileCreatorForCppTest.h"
#include "mocks/OutputterMock.h"

MakefileCreatorForCppTest::MakefileCreatorForCppTest() {
	// TODO
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

TEST_F(MakefileCreatorForCppTest, createMakefile) {
	OutputterMock* outputter = new OutputterMock();
	sut->setOutputter( outputter );
	OutputterMock* inputter = new OutputterMock();
	sut->setInputter( inputter );

	std::string expected = createExpectedMakefileContents();

	sut->createFiles("Hoge.cpp Fuga.cpp Foo.cpp", "Hoge.o Fuga.o Foo.o", "../test/HogeTest.cpp ../test/FugaTest.cpp ../test/FooTest.cpp", "HogeTest.o FugaTest.o FooTest.o");
	EXPECT_EQ(expected, outputter->getContents(0));
	EXPECT_EQ("SRC = Hoge.cpp Fuga.cpp Foo.cpp\n", outputter->getContents(1));
	EXPECT_EQ("OBJ = Hoge.o Fuga.o Foo.o\n", outputter->getContents(2));
	EXPECT_EQ("TEST_SRC = ../test/testMain.cpp ../test/HogeTest.cpp ../test/FugaTest.cpp ../test/FooTest.cpp\n", outputter->getContents(3));
	EXPECT_EQ("TEST_OBJ = testMain.o HogeTest.o FugaTest.o FooTest.o\n", outputter->getContents(4));
}

std::string MakefileCreatorForCppTest::createExpectedMakefileContents() {
	std::string contents;
	contents  = "CC = g++\n";
	contents += "RM = rm -f\n";
	contents += "INCLUDE = -I/usr/incude -I/usr/local/include\n";
	contents += "LIB_DIR = -L/usr/lib -L/usr/local/lib\n";
	contents += "LIB = -lpthread\n";
	contents += "OPT = -O0 -g3 -Wall -Wnon-virtual-dtor -Woverloaded-virtual -fmessage-length=0 -fprofile-arcs -ftest-coverage\n";
	contents += "TARGET = targetName\n";
	contents += "include productionSources.mk\n";
	contents += "\n";
	contents += "all: $(SRC:.cpp=.o) main.o\n";
	contents += "\t$(CC) $(INCLUDE) $(LIB_DIR) $(OPT) -o $(TARGET) $(SRC:.cpp=.o) main.o";
	contents += "\n";
	contents += "$(SRC:.cpp=.o): $(SRC)\n";
	contents += "\t$(CC) $(INCLUDE) $(LIB_DIR) $(OPT) -c $(SRC)\n";
	contents += "\n";
	contents += "main.o: main.cpp\n";
	contents += "\t$(CC) $(INCLUDE) $(LIB_DIR) $(OPT) -c main.cpp";
	contents += "\n";
	contents += ".PHONY: clean\n";
	contents += "clean:\n";
	contents += "\t$(RM) *.o $(TARGET) $(TEST_TARGET) gmon.out *.gc* *.xml *.exe *.txt\n";
	contents += "\n";
	contents += "\n";
	contents += "TEST_TARGET = targetNameTest\n";
	contents += "TEST_INCLUDE = -I../test -I.\n";
	contents += "TEST_LIB = -lgtest\n";
	contents += "TEST_OPT = -O0 -g3 -Wall -fmessage-length=0 -pg -fprofile-arcs -ftest-coverage\n";
	contents += "include testSources.mk\n";
	contents += "include testObjects.mk\n";
	contents += "\n";
	contents += "test: $(OBJ) $(TEST_OBJ)\n";
	contents += "\t$(CC) $(INCLUDE) $(TEST_INCLUDE) $(LIB_DIR) $(TEST_OPT) -o $(TEST_TARGET) $(OBJ) $(TEST_OBJ) $(LIB) $(TEST_LIB)\n";
	contents += "\n";
	contents += "$(TEST_OBJ): $(TEST_SRC)\n";
	contents += "\t$(CC) $(INCLUDE) $(TEST_INCLUDE) $(LIB_DIR) $(LIB) $(TEST_LIB) $(TEST_OPT) -c $(TEST_SRC)\n";

	return contents;
}
