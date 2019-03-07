#include <fstream>
#include "common.h"

struct day_t {
    void (*fn)(input_t);
    std::string filename;
};

static const day_t days[] = {
    { day01, "input/day01.txt" },
    { day02, "input/day02.txt" },
    { day03, "input/day03.txt" },
    { day04, "input/day04.txt" },
    { day05, "input/day05.txt" }
};

void read_input(input_t &input, const std::string &filename) {
    std::string line;
    std::ifstream file (filename);

    if (file.is_open()) {
        while (getline(file, line)) {
            input.content.push_back(line);
            input.length++;
        }

        file.close();
    }
}

int main() {
    for (day_t day : days) {
        input_t input;
        read_input(input, day.filename);
        std::cout << "--------------" << std::endl;
        day.fn(input);
    }

    return 0;
}
