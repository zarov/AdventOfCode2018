// https://adventofcode.com/2018/day/5
#include "common.h"

int react_polymer(const std::string &polymer) {
    std::string copy = polymer;

    for (auto itp = copy.begin(); itp != copy.end();) {
        char a = *itp;
        ++itp;
        char b = *itp;

        if ((a + 32) == b || a == (b + 32)) {
            copy.erase(itp);
            --itp;
            copy.erase(itp);
            --itp;
        }
    }

    return copy.length();
}

void remove_unit_type(std::string &polymer, const char unit_type) {
    const char unit_type_min = unit_type + 32;
    for (auto itp = polymer.begin(); itp != polymer.end(); ++itp) {
        if ((*itp) == unit_type || (*itp) == unit_type_min) {
            polymer.erase(itp);
            --itp;
        }
    }
}

void day05(const input_t input) {
    // only one polymer
    std::string polymer = input.content[0];

    const int initial_remaining = react_polymer(polymer);

    int remaining, min_remaining = polymer.length();
    for (int c = 65; c != 90; c++) {
        std::string copy = polymer;
        remove_unit_type(copy, char(c));
        remaining = react_polymer(copy);

        if (remaining < min_remaining) min_remaining = remaining;
    }

    std::cout << "Remaining units after fully reacting the polymer: " << initial_remaining << std::endl;
    std::cout << "Length of the shortest polymer producible: " << min_remaining << std::endl;
}
