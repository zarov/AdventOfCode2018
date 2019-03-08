#include <fstream>
#include <unistd.h>
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
    { day05, "input/day05.txt" },
    { day06, "input/day06.txt" }
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

void do_day(day_t day) {
    input_t input;
    read_input(input, day.filename);
    day.fn(input);
}

int main(int argc, char *argv[]) {
    int opt;
    while ((opt = getopt(argc, argv, "a:d:")) != -1) {
        switch (opt) {
            case 'd':
                do_day(days[atoi(optarg) - 1]);
                break;
            case 'a':
            case '?':
                for (day_t day : days) {
                    do_day(day);
                    std::cout << "--------------" << std::endl;
                }
                break;
        }
    }

    return 0;
}
