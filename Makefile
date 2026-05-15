TARGET = rdpo
CXX = g++
CXXFLAGS = -std=c++17 -I./include -fprofile-arcs -ftest-coverage
LDFLAGS = -lgtest -lgtest_main -pthread -lgcov --coverage

PREF_SRC = src
PREF_OBJ = obj

SRC = $(wildcard $(PREF_SRC)/*.cpp)
OBJ = $(patsubst $(PREF_SRC)/%.cpp, $(PREF_OBJ)/%.o, $(SRC))

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

$(PREF_OBJ)/%.o: $(PREF_SRC)/%.cpp
	@mkdir -p $(PREF_OBJ)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean coverage

clean:
	rm -rf $(TARGET) $(PREF_OBJ) coverage.info out

coverage:
	lcov --ignore-errors inconsistent --capture --directory $(PREF_OBJ) --directory . --output-file coverage.info --no-external
	genhtml --ignore-errors inconsistent coverage.info --output-directory ./out
