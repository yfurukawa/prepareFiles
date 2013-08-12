CC = g++
RM = rm -f
INCLUDE = -I/usr/incude -I/usr/local/include
LIB_DIR = -L/usr/lib -L/usr/local/lib
LIB =
OPT = -O0 -g3 -Wall -fmessage-length=0
TARGET = prepareFiles
SRC= 
OBJ= 

$(TARGET): $(OBJ) main.o 
	$(CC) $(INCLUDE) $(LIB_DIR) $(OPT) -o $(TARGET) $(OBJ) main.o

$(OBJ): $(SRC) main.cpp
	$(CC) $(INCLUDE) $(LIB_DIR) $(OPT) -c $(SRC)

main.o: main.cpp
	$(CC) $(INCLUDE) $(LIB_DIR) $(OPT) -c main.cpp
clean:
	$(RM) *.o $(TARGET) $(TEST_TARGET) gmon.out *.gc* *.xml


TEST_TARGET = prepareFilesTest
TEST_INCLUDE = -I../test -I.
TEST_LIB = -lgtest
TEST_OPT = -O0 -g3 -Wall -fmessage-length=0 -pg -fprofile-arcs -ftest-coverage
TEST_SRC = ../test/testMain.cpp 

TEST_OBJ = testMain.o 
	
test: $(OBJ) $(TEST_OBJ)
	$(CC) $(INCLUDE) $(TEST_INCLUDE) $(LIB_DIR) $(TEST_OPT) -o $(TEST_TARGET) $(OBJ) $(TEST_OBJ) $(LIB) $(TEST_LIB)

$(TEST_OBJ): $(TEST_SRC)
	$(CC) $(INCLUDE) $(TEST_INCLUDE) $(LIB_DIR) $(LIB) $(TEST_LIB) $(TEST_OPT) -c $(TEST_SRC)

