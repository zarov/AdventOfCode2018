// https://adventofcode.com/2018/day/7
#include "common.h"

void day07(const input_t input) {
    std::map<char, std::string> steps, steps_inv, queue;
    std::string order, steps_list;

    for (auto line : input.content) {
        steps_list += line[36];
        steps[line[5]] += line[36];
        steps_inv[line[36]] += line[5];
    }

    for (auto s : steps) {
        if (steps_list.find(s.first) == -1) {
            queue[s.first] = s.second;
        }
    }

    bool insert;
    while (!queue.empty()) {
        auto q = *(queue.begin());
        order += q.first;

        for (auto s : q.second) {
            insert = true;
            for (auto si : steps_inv[s]) {
                if (order.find(si) == -1) {
                    insert = false;
                    break;
                }
            }
            if (insert) {
                queue[s] = steps[s];
            }
        }

        queue.erase(q.first);
    }

    std::cout << "Order to do the steps: " << order << std::endl;
}
