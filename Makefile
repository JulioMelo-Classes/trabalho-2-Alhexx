SRC_DIR = src
INCLUDE_DIR = include
BIN_DIR = bin
DATA_DIR = data

CXX ?= g++
CFLAGS = -std=c++11 -Wall -g
LFLAGS =
F =

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%.o)
EXE = $(BIN_DIR)/concordo

install: setup clean $(EXE)

setup:
	echo -n ===SETTING UP ' '
	mkdir -p $(SRC_DIR) $(BIN_DIR) $(INCLUDE_DIR) $(DATA_DIR)
	echo OK

clean:
	echo -n ===CLEANING $(BIN_DIR)/ ' '
	rm -f $(BIN_DIR)/*.o $(EXE)
	echo OK

$(EXE): $(OBJ)
	echo -n ===LINKING ' '
	$(CXX) $^ -I $(INCLUDE_DIR) -o $@ $(LFLAGS)
	echo OK

$(OBJ): $(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	echo -n ===COMPILING $< ' '
	$(CXX) -c $< -I $(INCLUDE_DIR) -o $@ $(CFLAGS)
	echo OK

single:
	echo -n ===COMPILING $(F) ' '
	$(CXX) -c $(F) -I $(INCLUDE_DIR) -o $(F:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%.o) $(CFLAGS)
	echo OK
	echo -n ===LINKING ' '
	$(CXX) $(OBJ) -I $(INCLUDE_DIR) -o $(EXE) $(LFLAGS)
	echo OK

run:
ifeq ($(strip $(F)),)
	./$(EXE)
else
	./$(EXE) < $(F)
endif

test:
	for file in $(DATA_DIR)/* ; do echo ===TESTING $${file} ; ./$(EXE) < $${file} ; done

debug:
	echo $(SRC)
	echo $(OBJ)
	echo $(EXE)

.PHONY: install setup clean $(EXE) $(OBJ) single run test debug
.SILENT: install setup clean $(EXE) $(OBJ) single run test debug
