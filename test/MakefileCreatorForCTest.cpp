/**
 * MakefileCreatorForCTest.cpp
 *
 *  Created on: 2013/09/28
 *      Author: furukawayoshihiro
 */

#include <string>

#include "MakefileCreatorForCTest.h"
#include "mocks/OutputterMock.h"

MakefileCreatorForCTest::MakefileCreatorForCTest() : sut(NULL){
  sut = new MakefileCreatorForCSpy("targetName");
}

MakefileCreatorForCTest::~MakefileCreatorForCTest() {
  delete sut;
}

TEST_F(MakefileCreatorForCTest, setOutputter) {
  IOutputter* outputter = new OutputterMock();
  sut->setOutputter( outputter );

  EXPECT_EQ(outputter, sut->getOutputter());
}

TEST_F(MakefileCreatorForCTest, createMakefile) {
  OutputterMock* outputter = new OutputterMock();
  sut->setOutputter( outputter );
  OutputterMock* inputter = new OutputterMock();
  sut->setInputter( inputter );

  std::string expected = createExpectedMakefileContents();

  sut->createFiles("Hoge.c Fuga.c Foo.c", "Hoge.o Fuga.o Foo.o", "../test/HogeTest.c ../test/FugaTest.c ../test/FooTest.c", "HogeTest.o FugaTest.o FooTest.o");
  EXPECT_EQ(expected, outputter->getContents(0));
  EXPECT_EQ("SRC = Hoge.c Fuga.c Foo.c\n", outputter->getContents(1));
  EXPECT_EQ("OBJ = Hoge.o Fuga.o Foo.o\n", outputter->getContents(2));
  EXPECT_EQ("TEST_SRC = ../test/testMain.cpp ../test/HogeTest.c ../test/FugaTest.c ../test/FooTest.c\n", outputter->getContents(3));
  EXPECT_EQ("TEST_OBJ = testMain.o HogeTest.o FugaTest.o FooTest.o\n", outputter->getContents(4));
}

std::string MakefileCreatorForCTest::createExpectedMakefileContents() {
  std::string contents;
  contents  = "CC = gcc\n";
  contents += "RM = rm -f\n";
  contents += "INCLUDE = -I/usr/incude -I/usr/local/include\n";
  contents += "LIB_DIR = -L/usr/lib64 -L/usr/local/lib64\n";
  contents += "LIB = -lpthread\n";
  contents += "OPT = -O0 -g3 -Wall -fmessage-length=0 -fprofile-arcs -ftest-coverage\n";
  contents += "TARGET = targetName\n";
  contents += "include productionSources.mk\n";
  contents += "\n";
  contents += "all: $(SRC:.cpp=.o) main.o\n";
  contents += "\t$(CC) $(INCLUDE) $(LIB_DIR) $(OPT) -o $(TARGET) $(SRC:.cpp=.o) main.o";
  contents += "\n";
  contents += "$(SRC:.cpp=.o): $(SRC)\n";
  contents += "\t$(CC) $(INCLUDE) $(LIB_DIR) $(OPT) -c $(SRC)\n";
  contents += "\n";
  contents += "main.o: main.c\n";
  contents += "\t$(CC) $(INCLUDE) $(LIB_DIR) $(OPT) -c main.c\n";
  contents += "\n";
  contents += ".PHONY: clean\n";
  contents += "clean:\n";
  contents += "\t$(RM) *.o $(TARGET) $(TEST_TARGET) gmon.out *.gc* *.xml *.exe *.txt\n";
  contents += "\n";
  contents += "\n";
  contents += "TEST_CC = g++\n";
  contents += "TEST_TARGET = targetNameTest\n";
  contents += "TEST_INCLUDE = -I../test -I.\n";
  contents += "TEST_LIB = -lgtest\n";
  contents += "TEST_OPT = -O0 -g3 -Wall -fmessage-length=0 -pg -fprofile-arcs -ftest-coverage\n";
  contents += "include testSources.mk\n";
  contents += "\n";
  contents += "test: $(SRC:.cpp=.o) $(TEST_SRC:.cpp=.o)\n";
  contents += "\t$(TEST_CC) $(INCLUDE) $(TEST_INCLUDE) $(LIB_DIR) $(TEST_OPT) -o $(TEST_TARGET) $(SRC:.cpp=.o) $(TEST_SRC:.cpp=.o) $(LIB) $(TEST_LIB)\n";
  contents += "\n";
  contents += "$(TEST_SRC:.cpp=.o): $(TEST_SRC)\n";
  contents += "\t$(TEST_CC) $(INCLUDE) $(TEST_INCLUDE) $(LIB_DIR) $(LIB) $(TEST_LIB) $(TEST_OPT) -c $(TEST_SRC)\n";

  return contents;
}
