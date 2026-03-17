#compiler
CXX = g++ 
CXXFLAGS = -Wall -g -std=c++17
Target run_tests
SRCS = SpeedFormatter.cpp tests/test_main.cpp
OBJS = $(SRCS:.cpp=.o)
all :$(TARGET)
$(TARGET) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
%.o %.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
run: $(TARGET)
	./$(TARGET)
clean
	rm -f $(OBJS) $(TARGET)