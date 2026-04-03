CXX = g++
CXXFLAGS = -Wall -std=c++17

TARGET = spl_calculator
OBJS = SPL_Calculator.o main.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

SPL_Calculator.o: SPL_Calculator.cpp SPL_Calculator.h
	$(CXX) $(CXXFLAGS) -c SPL_Calculator.cpp

main.o: main.cpp SPL_Calculator.h
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f *.o $(TARGET)
