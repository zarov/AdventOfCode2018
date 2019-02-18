// https://adventofcode.com/2018/day/1
#include <iostream>
#include <fstream>
#include <list>
#include <set>

int read_repetitions(std::list<int> frequencies, std::set<int> repetitions) {
    int repeated = 0;
    int resulting = 0;

    while (!repeated) {
        for (std::list<int>::iterator it = frequencies.begin(); it != frequencies.end(); it++) {
            resulting += *it;
            if (repetitions.count(resulting) > 0) {
                repeated = resulting;
                break;
            } else {
                repetitions.insert(resulting);
            }
        }
    }

    return repeated;
}

int main() {
    std::string line;
    std::ifstream input ("01-input.txt");

    int frequency;
    std::list<int> frequencies;

    int resulting;

    if (input.is_open()) {
        while (getline(input, line)) {
            frequency = std::stoi(line);
            frequencies.push_back(frequency);
            resulting += frequency;
        }

        input.close();
    }

    int repeated;
    std::set<int> repetitions;

    while (!repeated) repeated = read_repetitions(frequencies, repetitions);

    std::cout << "Resulting frequency: " << resulting << std::endl;
    std::cout << "First repeated frequency: " << repeated << std::endl;

    return 0;
}
