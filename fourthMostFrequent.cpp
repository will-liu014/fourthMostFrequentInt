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

	std::map<int, int> frequency;
	for (int i = 0; i < input.size(); i++) {
		frequency[input[i]]++;
	}

	std::vector<std::pair<int, int>> sorted;
	std::map<int, int> ::iterator j;
	for (j = frequency.begin(); j != frequency.end(); j++) {
		sorted.push_back(std::make_pair(j->first, j->second));
	}
	std::sort(sorted.begin(), sorted.end(), sortFreqDesc);

	for (int i = 0; i < sorted.size(); i++) {
		std::cout << sorted[i].first << " appears " << sorted[i].second << " time(s)\n";
	}

	return sorted[3].first;;
}

int main() {
	std::string sequence = "";
	std::cout << "Please input int using single space as a delimiter (i.e. 4 4 1 2 2 2 2 3 3 3 5 5 5 6 1 5 9)" << "\n\n";
	std::getline(std::cin, sequence);
	std::cout << fourthFreq(sequence) << '\n';
}
