// https://adventofcode.com/2018/day/8
#include "common.h"

struct node_t {
    std::vector<int> metadata;
    std::vector<node_t> children;
    node_t parent;
};

node_t read_tree(node_t tree, std::string content) {

}

void day08(const input_t input) {
    const std::string license = input.content[1];
    node_t root, current;
    current = root;

    std::string c;
    auto it = license.cbegin();
    while (it != license.cend()) {
        c = "";
        while (it != license.cend()) {
            ++it;
            if ((*it) == 0x20) break;
            c += (*it);
        }

        std::cout << c<<std::endl;
    }
}
