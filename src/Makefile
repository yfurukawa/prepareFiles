CC = g++
RM = rm -f
CP = cp
INCLUDE = -I/usr/incude -I/usr/local/include -I../include
LIB_DIR = -L/usr/lib -L/usr/local/lib -L/usr/lib64 -L/usr/local/lib64
INSTALL_DIR = /usr/local/bin
LIB = -lpthread
OPT = -O0 -g3 -Wall -Wnon-virtual-dtor -Woverloaded-virtual -fmessage-length=0 -fprofile-arcs -ftest-coverage
TARGET = prepareFiles
SRC= IClassFileMaker.cpp ClassFileMaker.cpp IOutputter.cpp FileDAO.cpp TestClassFileMaker.cpp CommandLineArgumentsParser.cpp \
     FileMakerList.cpp IMakefileCreator.cpp MakefileCreatorForCpp.cpp TestMainMaker.cpp ClassFileMakerFactory.cpp MakefileCreatorFactory.cpp \
     CFileMaker.cpp TestClassFileMakerForC.cpp MakefileCreatorForC.cpp SubMakefileCreator.cpp

all: $(SRC:.cpp=.o) main.o 
	$(CC) $(INCLUDE) $(LIB_DIR) $(OPT) -o $(TARGET) $(SRC:.cpp=.o) main.o

$(SRC:.cpp=.o): $(SRC)
	$(CC) $(INCLUDE) $(LIB_DIR) $(OPT) -c $(SRC)

main.o: main.cpp
	$(CC) $(INCLUDE) $(LIB_DIR) $(OPT) -c main.cpp
	
.PHONY: clean
clean:
	$(RM) *.o $(TARGET) $(TEST_TARGET) gmon.out *.gc* *.xml *.exe Fuga.cpp Hoge.cpp *.txt

.PHONY: install
install:
	$(CP) $(TARGET) $(INSTALL_DIR)

TEST_TARGET = prepareFilesTest
TEST_INCLUDE = -I../test -I.
TEST_LIB = -lgtest
TEST_OPT = -O0 -g3 -Wall -fmessage-length=0 -pg -fprofile-arcs -ftest-coverage
TEST_SRC = ../test/testMain.cpp ../test/ClassFileMakerTest.cpp ../test/mocks/ClassFileMakerSpy.cpp ../test/mocks/OutputterMock.cpp \
../test/FileDAOTest.cpp ../test/TestClassFileMakerTest.cpp ../test/mocks/TestClassFileMakerSpy.cpp \
../test/CommandLineArgumentsParserTest.cpp ../test/FileMakerListTest.cpp ../test/mocks/FileMakerListSpy.cpp \
../test/mocks/ClassFileMakerMock.cpp ../test/MakefileCreatorForCppTest.cpp ../test/mocks/MakefileCreatorForCppSpy.cpp \
../test/TestMainMakerTest.cpp ../test/mocks/TestMainMakerSpy.cpp ../test/ClassFileMakerFactoryTest.cpp \
../test/mocks/CommandLineArgumentsParserMock.cpp ../test/MakefileCreatorFactoryTest.cpp ../test/CFileMakerTest.cpp \
../test/mocks/CFileMakerSpy.cpp ../test/TestClassFileMakerForCTest.cpp ../test/mocks/TestClassFileMakerForCSpy.cpp \
../test/MakefileCreatorForCTest.cpp ../test/mocks/MakefileCreatorForCSpy.cpp ../test/SubMakefileCreatorTest.cpp \
../test/mocks/SubMakefileCreatorSpy.cpp ../test/mocks/FileDAOSpy.cpp

TEST_OBJ = testMain.o ClassFileMakerTest.o ClassFileMakerSpy.o OutputterMock.o FileDAOTest.o TestClassFileMakerTest.o \
TestClassFileMakerSpy.o CommandLineArgumentsParserTest.o FileMakerListTest.o FileMakerListSpy.o ClassFileMakerMock.o \
MakefileCreatorForCppTest.o MakefileCreatorForCppSpy.o TestMainMakerTest.o TestMainMakerSpy.o ClassFileMakerFactoryTest.o \
CommandLineArgumentsParserMock.o MakefileCreatorFactoryTest.o CFileMakerTest.o CFileMakerSpy.o TestClassFileMakerForCTest.o \
TestClassFileMakerForCSpy.o MakefileCreatorForCTest.o MakefileCreatorForCSpy.o SubMakefileCreatorTest.o SubMakefileCreatorSpy.o \
FileDAOSpy.o
	
test: $(SRC:.cpp=.o) $(TEST_OBJ)
	$(CC) $(INCLUDE) $(TEST_INCLUDE) $(LIB_DIR) $(TEST_OPT) -o $(TEST_TARGET) $(SRC:.cpp=.o) $(TEST_OBJ) $(LIB) $(TEST_LIB)

$(TEST_OBJ): $(TEST_SRC)
	$(CC) $(INCLUDE) $(TEST_INCLUDE) $(LIB_DIR) $(LIB) $(TEST_LIB) $(TEST_OPT) -c $(TEST_SRC)

