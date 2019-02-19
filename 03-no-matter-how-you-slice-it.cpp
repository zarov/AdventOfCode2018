// https://adventofcode.com/2018/day/3
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>

struct claim_t {
    int id;
    int x;
    int y;
    int w;
    int h;

    bool operator< (const claim_t &c) const { return y > c.y; }
};

int main() {
    std::string line;
    std::ifstream input ("03-input.txt");

    std::vector<claim_t> claims;
    claim_t claim;
    claim_t max_claim;

    if (input.is_open()) {
        int pos_a, pos_b;
        while (getline(input, line)) {
            pos_a = 1;
            pos_b = line.find(' ');
            claim.id = stoi(line.substr(pos_a, pos_b - pos_a));

            pos_a = pos_b;
            pos_b = line.find(',');
            claim.x = stoi(line.substr(pos_a + 3, pos_b - pos_a - 3));

            pos_a = pos_b;
            pos_b = line.find(':');
            claim.y = stoi(line.substr(pos_a + 1, pos_b - pos_a - 1));

            pos_a = pos_b;
            pos_b = line.find('x');
            claim.w = stoi(line.substr(pos_a + 2, pos_b - pos_a - 2));
            claim.h = stoi(line.substr(pos_b + 1));

            claims.push_back(claim);

            if (claim.x > max_claim.x) max_claim.x = claim.x;
            if (claim.y > max_claim.y) max_claim.y = claim.y;
            if (claim.w > max_claim.w) max_claim.w = claim.w;
            if (claim.h > max_claim.h) max_claim.h = claim.h;
        }
        input.close();
    }

    std::sort(claims.begin(), claims.end());

    int fabric[max_claim.w + max_claim.x][max_claim.h + max_claim.y];
    int covered = 0;
    auto itc = claims.begin();
    while (itc != claims.end()) {
        claim = *itc;
        for (int i = 0; i < claim.w; i++) {
            for (int j = 0; j < claim.h; j++) {
                fabric[claim.x + i][claim.y + j]++;

                if (fabric[claim.x + i][claim.y + j] == 2) covered++;
            }
        }

        itc++;
    }

    std::cout << "Square inches within two or more claims: " << covered << std::endl;

    return 0;
}
