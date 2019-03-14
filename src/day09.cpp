// https://adventofcode.com/2018/day/9
#include "common.h"

void day09(const input_t input) {
    std::string game = input.content[0];
    int np = stoi(game.substr(0, game.find(0x20)));
    int nm = stoi(game.substr(game.find("worth ") + 6, game.find(" points") - game.find("worth ") - 6));
    nm *= 100;

    std::list<int> play (1, 0);
    long score[np];
    memset(score, 0, np * sizeof(long));

    int cp = 0;
    auto itm = play.begin();
    for (int cm = 1; cm < nm; cm++) {
        cp = (cp + 1) % np;

        if ((cm % 23) == 0) {
            score[cp] += cm;
            for (int i = 0; i < 7; i++) {
                if (itm == play.begin()) itm = play.end();
                --itm;
            }
            score[cp] += (*itm);
            play.erase(itm);
            ++itm;
            if (itm == play.end()) itm = play.begin();
        } else {
            for (int i = 0; i < 2; i++) {
                if (itm == play.end()) itm = play.begin();
                ++itm;
            }
            play.insert(itm, cm);
            --itm;
            if (itm == play.begin()) itm = play.end();
        }

    }

    long winning = 0;
    for (long s : score)
        if (s > winning) winning = s;

    std::cout << "The winning Elf's score is: " << winning << std::endl;
}
