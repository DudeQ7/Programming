CXX := g++
CXXFLAGS := -Wall -g -std=c++17 -I.
LDFLAGS := -pthread

# Jeśli masz zainstalowane gtest systemowo ustaw GTEST_LIBS domyślnie na -lgtest -lgtest_main
# W razie potrzeby możesz uruchomić "make gtest_build" (wymaga cmake) aby pobrać i zbudować googletest w third_party
GTEST_LIBS ?= -lgtest -lgtest_main
GTEST_DIR ?= third_party/googletest

SRCS := SpeedFormatter.cpp
TEST_SRCS := tests/test_main.cpp

OBJS := $(SRCS:.cpp=.o)
TEST_OBJS := $(TEST_SRCS:.cpp=.o)
ALL_OBJS := $(OBJS) $(TEST_OBJS)

TARGET := run_tests

.PHONY: all clean run gtest_build

all: $(TARGET)

# finalny target (test runner)
$(TARGET): $(ALL_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS) $(GTEST_LIBS)

# kompilacja obiektów
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# uruchom testy
run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(ALL_OBJS) $(TARGET)

# optional: pobierz i zbuduj googletest w third_party (wymaga cmake)
# po zbudowaniu możesz użyć bibliotek wskazując GTEST_LIBS i GTEST_DIR ręcznie
gtest_build:
	@if [ -d $(GTEST_DIR) ]; then echo "googletest already downloaded"; else \
	  git clone --depth=1 https://github.com/google/googletest.git $(GTEST_DIR); fi
	mkdir -p $(GTEST_DIR)/build
	cd $(GTEST_DIR)/build && cmake .. -DCMAKE_BUILD_TYPE=Release && cmake --build . --config Release
	@echo "Jeśli gtest się zbudował, ustaw zmienne w Makefile np:"
	@echo "  GTEST_LIBS=\"$(GTEST_DIR)/build/googlemock/gtest/libgtest.a $(GTEST_DIR)/build/googlemock/gtest/libgtest_main.a\" make"