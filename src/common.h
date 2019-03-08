#ifndef COMMON_H
#define COMMON_H

#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <vector>

struct input_t {
    std::vector<std::string> content;
    int length = 0;
};

void day01(const input_t);
void day02(const input_t);
void day03(const input_t);
void day04(const input_t);
void day05(const input_t);
void day06(const input_t);

#endif
