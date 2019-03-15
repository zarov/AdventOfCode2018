// https://adventofcode.com/2018/day/12
#include "common.h"

static const int N = 200;

void day12(const input_t input) {
    std::string pots = input.content[0].substr(15);
    std::set<std::string> mutations;

    for (int i = 2; i < input.length; i++) {
        if (input.content[i][9] == 0x23)
            mutations.insert(input.content[i].substr(0, 5));
    }

    // add some empty pots
    pots.append(pots.length() * 10, 0x2E);
    pots.insert(0, pots.length(), 0x2E);

    std::string next_generation (pots, 0);
    std::string five_pots;
    for (int i = 0; i < N; i++) {
        for (int p = 2; p < pots.length(); p++) {
            five_pots = pots.substr(p - 2, 5);

            if (mutations.find(five_pots) != mutations.end()) next_generation[p] = 0x23;
            else next_generation[p] = 0x2E;
        }

        pots = next_generation;
    }

    int sum = 0, half = pots.length() / 2 - 1;
    auto it = pots.cbegin();
    for (int p = -half; p < half; p++)
        if ((*(++it)) == 0x23)
            sum += p;

    long mega_sum = (5e10 - N) * 80 + sum;

    std::cout << "After " << N << " generations, sum of the number of each pot which contain a plant: " << sum << std::endl;
    std::cout << "After 50 billion generations, sum is: " << mega_sum << std::endl;
}
