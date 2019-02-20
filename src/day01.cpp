// https://adventofcode.com/2018/day/1
#include "common.h"

int read_repetitions(int frequencies[], int len) {
    int repeated = 0;
    int resulting = 0;
    std::set<int> repetitions;

    while (!repeated) {
        for (int i = 0; i < len; ++i) {
            resulting += frequencies[i];
            if (repetitions.count(resulting)) {
                repeated = resulting;
                break;
            } else {
                repetitions.insert(resulting);
            }
        }
    }

    return resulting;
}

void day01(const input_t input) {
    int frequencies[input.length];
    int fq;
    int resulting = 0;
    for (int i = 0; i < input.length; ++i) {
        fq = std::stoi(input.content[i]);
        frequencies[i] = fq;
        resulting += fq;
    }

    int repeated = read_repetitions(frequencies, input.length);

    std::cout << "Resulting frequency: " << resulting << std::endl;
    std::cout << "First repeated frequency: " << repeated << std::endl;
}
