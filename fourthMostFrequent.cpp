#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <limits>

bool sortFreqAsc(const int &x, const int &y) {
	return (x > y);
}

std::vector<int> parseSort(std::string in) {
	std::vector<std::string> split;

	std::string temp = "";
	for (auto i : in) {
		if (i == ' ') {
			split.push_back(temp);
			temp = "";
		}
		else temp += i;
	}
	split.push_back(temp);

	/*
	for (unsigned i = 0; i < input.length(); ++i) {
		if (input.at(i) != ' ') {
			temp += ""  + input.at(i);
		}
		if (i < input.length() - 1 && input.at(i + 1) == ' ') {
			split.push_back(std::stoi(temp));
			std::cout << temp << '\n';
			temp = "";
		}
	}
	*/

	int convert;
	std::vector<int> parseInt;
	for (int i = 0; i < split.size(); i++) {
		convert = std::stoi(split[i]);
		parseInt.push_back(convert);
	}
	std::sort(parseInt.begin(), parseInt.end(), sortFreqAsc);

	return parseInt;
}

bool sortFreqDesc(const std::pair<int, int> &x, const std::pair<int, int> &y) {
	return (x.second > y.second);
}

int fourthFreq(std::string in) {
	std::vector<int> input = parseSort(in);
	//throw std::invalid_argument("Error due to non Integer Input");
	//throw std::invalid_argument("Error due to not enough numbers to find 4th most frequent value");
	//throw std::invalid_argument("Error due to extra spaces being entered");
	//throw std::invalid_argument("Error due to ...");

	// count freq of each key
	std::map<int, int> frequency;
	for (int i = 0; i < input.size(); i++) {
		frequency[input[i]]++;
	}

	/*
	std::vector<std::vector<int>> freqChart;
	struct freq {
		std::stack<int> value, repeats;
	};
	*/
	/*
	std::vector<std::string> tab;
	std::vector<int> freq;
	int index = 0, tempcount;

	if (std::binary_search(tab.begin(), tab.end(), input.at(0)))
		std::cout << "true";

	for (int i = 0; i < input.size(); i++) {
		if (std::binary_search(tab.begin(), tab.end(), input.at(i))) {
			tempcount = freq.at(index) + 1;
			freq.assign(index,tempcount);
		}
		else {
			tab.push_back(input.at(i));
			freq.push_back(1);
			index++;
		}
	}
		////////////////////////////////
	int freq = 1, index = 0;
	tab.push_back(std::make_pair(input.at(0),freq));
	for (int i = 1; i < input.size(); i++) {
		// if current value matches index in vector, add one to frequency else make new index
		freq = 1;
		if (input.at(i) == tab.at(index).first) {
			freq = tab.at(index).second + 1;
			tab.assign(index,std::make_pair(input.at(i),freq));
		}
		else {
			tab.push_back(std::make_pair(input.at(i), freq));
			index++;
		}
	}
	*/

	// sort by freq using vector pair since map sorts by key
	std::vector<std::pair<int, int>> sorted;
	std::map<int, int> ::iterator j;
	for (j = frequency.begin(); j != frequency.end(); j++) {
		sorted.push_back(std::make_pair(j->first, j->second));
	}
	std::sort(sorted.begin(), sorted.end(), sortFreqDesc);

	/*
	for (int i = 0; i < sorted.size(); i++) {
		std::cout << sorted[i].first << " appears " << sorted[i].second << " time(s)\n";
	}
	*/

	// frequency of fourth most freq value
	int repeats = sorted[0].second, nFreq = 0, value = 0;
	for (int i = 0; i < sorted.size(); i++) {
		if (sorted[i].second < repeats) {
			repeats = sorted[i].second;
			value = sorted[i].first;
			nFreq++;
			if (nFreq == 3) {
				break;
			}
		}
	}

	return value;
}

int main() {
	std::string sequence = "";
	std::cout << "Please input int using single space as a delimiter (i.e. 4 4 1 2 2 2 2 3 3 3 5 5 5 6 1 5 9)" << "\n\n";
	std::getline(std::cin, sequence);
	//std::cout << "\nFourth most frequent value is: " << fourthFreq(sequence) << '\n';
	std::cout << fourthFreq(sequence) << '\n';
}