// https://adventofcode.com/2018/day/6
#include "common.h"

struct point_t {
    int x, y, area = 0, valid = 1;

    point_t() : x(), y() {}
    point_t(int x, int y) : x(x), y(y) {}
    point_t min(const point_t &p) const {
        return { std::min(x, p.x), std::min(y, p.y) };
    }
    point_t max(const point_t &p) const {
        return { std::max(x, p.x), std::max(y, p.y) };
    }
};

void day06(const input_t input) {
    point_t points[input.length];
    point_t point;

    int i = 0, j, k;

    int sep;
    for (const auto line : input.content) {
        sep = line.find(',');
        point.x = stoi(line.substr(0, sep));
        point.y = stoi(line.substr(sep + 1));

        points[i++] = point;
    }

    // search for dimensions of grid
    point_t min_xy (100000, 100000);
    point_t max_xy (0, 0);
    for (point_t p : points) {
        min_xy = p.min(min_xy);
        max_xy = p.max(max_xy);
    }

    int J = max_xy.y + min_xy.y;
    int I = max_xy.x + min_xy.x + 1;

    // filling the grid
    int dmin, d, l, total = 0, t;
    for (j = 0; j < J; j++) {
        for (i = 0; i < I; i++) {
            dmin = max_xy.x * max_xy.y;
            l = -1;
            t = 0;

            for (k = 0; k < input.length; k++) {
                d = abs(points[k].x - i) + abs(points[k].y - j);
                t += d;
                if (d < dmin) {
                    dmin = d;
                    l = k;
                } else if (d == dmin) {
                    l = -1;
                }
            }

            if (t < 10000) total++;

            if (l > -1) {
                points[l].area++;
                if (i == 0 || j == (J - 1) || j == 0) points[l].valid = -1;
            }

        }

        if (l > -1) points[l].valid = -1;
    }

    int largest_area = 0;
    for (const point_t p : points) {
        if (p.area > largest_area && p.valid > 0) largest_area = p.area;
    }

    std::cout << "Size of the largest finite area: " << largest_area << std::endl;
    std::cout << "Size of the region containing all locations within total distance of 10000: " << total << std::endl;
}
