// https://adventofcode.com/2018/day/7
#include "common.h"

const int WORKER = 5;

struct elf_t {
    char step = 0x0;
    std::string queue;
    int time = 0;
};

void day07(const input_t input) {
    std::map<char, std::string> steps, steps_inv, queue;
    std::string order, steps_list;
    elf_t elves[WORKER];

    for (auto line : input.content) {
        steps_list += line[36];
        steps[line[5]] += line[36];
        steps_inv[line[36]] += line[5];
    }

    // find the first steps
    for (auto s : steps) {
        if (steps_list.find(s.first) == -1) {
            queue[s.first] = s.second;
        }
    }

    bool insert, working = true;
    int time = 0;
    while (working) {
        for (int i = 0; i < WORKER; ++i) {
            if ((elves[i].step - 4) == elves[i].time) {
                order += elves[i].step;

                // update the queue
                for (auto s : elves[i].queue) {
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

                elves[i].step = 0x0;
                elves[i].time = 0;
            }
        }

        working = false;
        for (int i = 0; i < WORKER; ++i) {
            if (elves[i].step == 0x0 && !queue.empty()) {
                auto q = *(queue.begin());
                elves[i].step = q.first;
                elves[i].queue = q.second;
                queue.erase(q.first);
            }

            if (elves[i].step != 0x0) {
                working = true;
                elves[i].time++;
            }
        }

        if (working) time++;
    }

    std::cout << "Order to do the steps with five workers: " << order << std::endl;
    std::cout << "Time to complete all steps: " << time << std::endl;
}
