// https://adventofcode.com/2018/day/8
#include "common.h"

struct node_t {
    std::vector<int> metadata;
    std::vector<node_t> children;
    int value = 0;
};

int read_num(std::string::const_iterator &it) {
    std::string n = "";
    while ((*it) != 0x20 && (*it) != 0x12) {
        n += (*it);
        ++it;
    }
    ++it;
    return stoi(n);
}

node_t read_node(std::string::const_iterator &it, int &sum) {
    node_t node;

    int nc = read_num(it);
    int nm = read_num(it);

    for (int i = 0; i < nc; i++) {
        node.children.push_back(read_node(it, sum));
    }

    int num;
    for (int i = 0; i < nm; i++) {
        num = read_num(it);

        node.metadata.push_back(num);
        sum += node.metadata[i];

        if (nc == 0) {
            node.value += num;
        } else if (node.children.size() > num - 1) {
            node.value += node.children[num - 1].value;
        }
    }

    return node;
}

void day08(const input_t input) {
    int sum = 0;
    auto it = input.content[0].begin();
    node_t tree = read_node(it, sum);

    std::cout << "The sum of all metadata entries is: " << sum << std::endl;
    std::cout << "The value of the root node is: " << tree.value << std::endl;
}
