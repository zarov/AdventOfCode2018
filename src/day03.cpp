// https://adventofcode.com/2018/day/3
#include "common.h"

struct claim_t {
    int id;
    int x;
    int y;
    int w;
    int h;

    bool operator< (const claim_t &c) const { return y > c.y; }
};

void day03(const input_t input) {
    std::vector<claim_t> claims;
    claim_t claim;
    claim_t max_claim = { 0, 0, 0, 0 };

    int pos_a, pos_b;
    for (auto line : input.content) {
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

    std::sort(claims.begin(), claims.end());

    int fabric[max_claim.w + max_claim.x][max_claim.h + max_claim.y];
    int covered = 0;
    auto itc = claims.cbegin();
    while (itc != claims.cend()) {
        claim = *itc;
        for (int i = 0; i < claim.w; i++) {
            for (int j = 0; j < claim.h; j++) {
                fabric[claim.x + i][claim.y + j]++;

                if (fabric[claim.x + i][claim.y + j] == 2) covered++;
            }
        }

        ++itc;
    }

    int clean_claim = 1;
    itc = claims.cbegin();
    while (itc != claims.cend()) {
        claim = *itc;
        clean_claim = 1;
        for (int i = 0; i < claim.w; i++) {
            for (int j = 0; j < claim.h; j++) {
                if (fabric[claim.x + i][claim.y + j] > 1) {
                    clean_claim = 0;
                    break;
                }
            }

            if (clean_claim == 0) break;
        }

        if (clean_claim == 1) {
            clean_claim = claim.id;
            break;
        }

        ++itc;
    }

    std::cout << "Square inches within two or more claims: " << covered << std::endl;
    std::cout << "Claim that came clean and can be cut: " << clean_claim << std::endl;
}
