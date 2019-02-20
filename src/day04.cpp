// https://adventofcode.com/2018/day/4
#include "common.h"

int get_time(std::string record) {
    return stoi(record.substr(15, 2));
}

void day04(const input_t input) {
    std::vector<std::string> records = input.content;
    std::map<std::string, int[60]> guards;

    std::sort(records.begin(), records.end());

    std::string guard_id;
    std::string record;
    int asleep_time = 0;
    int wake_time = 0;
    int m;

    for (auto it = records.cbegin(); it != records.cend(); ++it) {
        record = *it;

        if (record.compare(19, 1, "f") == 0) {
            asleep_time = get_time(record);
        } else if (record.compare(19, 1, "w") == 0) {
            wake_time = get_time(record);
            for (m = asleep_time; m < wake_time; ++m) guards[guard_id][m]++;
        } else {
            guard_id = record.substr(26, record.find("b") - 27);
        }
    }

    int most_asleep_minute = 0;
    std::string most_asleep_guard;
    int most_regular_minute = 0;
    std::string most_regular_guard;
    for (auto g : guards) {
        asleep_time = std::accumulate(std::begin(g.second), std::end(g.second), 0);
        if (asleep_time > most_asleep_minute) {
            most_asleep_guard = g.first;
            most_asleep_minute = asleep_time;
        }

        for (m = 0; m < 60; ++m) {
            if (g.second[m] > most_regular_minute) {
                most_regular_minute = g.second[m];
                most_regular_guard = g.first;
            }
        }
    }

    most_asleep_minute = std::distance(
            std::begin(guards[most_asleep_guard]),
            std::max_element(std::begin(guards[most_asleep_guard]), std::end(guards[most_asleep_guard])));

    most_regular_minute = std::distance(
            std::begin(guards[most_regular_guard]),
            std::max_element(std::begin(guards[most_regular_guard]), std::end(guards[most_regular_guard])));

    std::cout << "Most asleep guard is #" << most_asleep_guard << std::endl;
    std::cout << "He sleeps the most at " << most_asleep_minute << std::endl;
    std::cout << "Therefore the ID multiplied by the minute is " << stoi(most_asleep_guard) * most_asleep_minute << std::endl;
    std::cout << std::endl;
    std::cout << "Most regular guard is #" << most_regular_guard << std::endl;
    std::cout << "He sleeps the most at " << most_regular_minute << std::endl;
    std::cout << "Therefore the ID multiplied by the minute is " << stoi(most_regular_guard) * most_regular_minute << std::endl;
}
