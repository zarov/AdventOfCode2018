// https://adventofcode.com/2018/day/10
#include "common.h"

static const int IT = 20000;
static const int WIDTH = 65;

struct point_t {
    int x, y, vx, vy;
};

bool comp_x(point_t a, point_t b) { return a.x < b.x; }
bool comp_y(point_t a, point_t b) { return a.y < b.y; }

void day10(const input_t input) {
    std::vector<point_t> stars;
    point_t star;

    for (auto line : input.content) {
        star.x = stoi(line.substr(10, 6));
        star.y = stoi(line.substr(18, 6));
        star.vx = stoi(line.substr(36, 2));
        star.vy = stoi(line.substr(40, 2));
        stars.push_back(star);
    }

    int min_x, min_y, max_x, max_y;
    char c;
    for (int i = 0; i < IT; i++) {
        min_x = (*(min_element(stars.begin(), stars.end(), comp_x))).x;
        min_y = (*(min_element(stars.begin(), stars.end(), comp_y))).y;
        max_x = (*(max_element(stars.begin(), stars.end(), comp_x))).x;
        max_y = (*(max_element(stars.begin(), stars.end(), comp_y))).y;

        if (min_x + WIDTH > max_x && min_y + WIDTH > max_y) {
            for (int y = min_y; y <= max_y; y++) {
                for (int x = min_x; x <= max_x; x++) {
                    c = 0x2E;
                    for (auto its = stars.begin(); its != stars.end(); ++its) {
                        if ((*its).x == x && (*its).y == y) c = 0x23;
                    }
                    std::cout << c;
                }
                std::cout << "\n";
            }
            std::cout << "\n" << "Seconds to wait: " << i << "\n";
        }

        for (auto its = stars.begin(); its != stars.end(); ++its) {
            star = (*its);
            star.x += star.vx;
            star.y += star.vy;
            (*its) = star;
        }
    }
}
