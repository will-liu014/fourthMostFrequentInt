CXX=g++

all: fourthMostFrequent
	

fourthMostFrequent:
	$(CXX) -std=c++11 -o fourth fourthMostFrequent.cpp

clean:
	rm fourthMostFrequent
