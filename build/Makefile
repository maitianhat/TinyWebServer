CXX = g++
CXXFLAGS = -std=c++14 -O2 -Wall -g

TARGET = server
OBJS = ../src/main.cpp ../src/webserver.cpp

all: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o ../bin/$(TARGET)

clean:
	rm -rf ../bin/$(OBJS) $(TARGET)