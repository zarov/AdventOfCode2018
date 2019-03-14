// https://adventofcode.com/2018/day/10
#include "common.h"

static const int SIZE = 301;

void day11(const input_t input) {
    int serial_number = stoi(input.content[0]);
    int grid[SIZE][SIZE];
    int power;
    int rack = 10;

    for (int x = 1; x < SIZE; x++) {
        rack++;
        for (int y = 1; y < SIZE; y++) {
            power = (rack * y + serial_number) * rack;
            if (power < 100) power = -5;
            else power = ((power / 100) % 10) - 5;
            grid[x][y] = power;
        }
    }

    int max_power = -100, xp, yp;
    for (int s = 1; s < SIZE - 1; s++) {
        for (int x = 1; x < SIZE - s - 2; x++) {
            for (int y = 1; y < SIZE - s - 2; y++) {
                power = 0;

                for (int i = 0; i < s; i++) {
                    for (int j = 0; j < s; j++) {
                        power += grid[x + i][y + j];
                    }
                }

                if (power > max_power) {
                    max_power = power;
                    xp = x;
                    yp = y;

                    // bruteforcing, but the result gets stuck at some point;
                    // just try it
                    std::cout << xp << "," << yp << "," << s << "\n";
                }
            }
        }
    }

    std::cout << "Total power of the largest total power square: " << max_power << std::endl;
    std::cout << "Coordinate of the top-left cell of this square: " << xp << "," << yp << std::endl;
}
