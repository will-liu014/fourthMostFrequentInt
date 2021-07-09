CXX=g++-11

all: fourthMostFrequent
	

fourthMostFrequent:
	$(CXX) -o fourth fourthMostFrequent.cpp

clean:
	rm fourthMostFrequent
