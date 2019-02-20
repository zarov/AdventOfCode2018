// https://adventofcode.com/2018/day/2
#include "common.h"

void day02(const input_t input) {
    std::vector<std::string> boxes = input.content;
    int twos = 0, threes = 0;
    std::string common;

    std::sort(boxes.begin(), boxes.end());

    for (auto it = boxes.begin(); it != boxes.end();) {
        std::string a = *it;
        ++it;
        std::string b = *it;

        // checksum
        std::map<char,int> fq;
        for (const char& c : a) fq[c]++;

        int two = 0, three = 0;
        for (const auto& f : fq) {
            if (f.second == 2) two = 1;
            if (f.second == 3) three = 1;
        }

        twos += two;
        threes += three;

        // common letters
        auto ita = a.begin();
        auto itb = b.begin();
        while (++ita, ++itb, ita != a.end()) {
            if (*ita != *itb) {
                a.erase(ita);
                ita--;
            }
        }

        if (a.length() >= b.length() -1) common = a;
    }

    std::cout << "The checksum is " << twos * threes << std::endl;
    std::cout << "Common letters are " << common << std::endl;
}
