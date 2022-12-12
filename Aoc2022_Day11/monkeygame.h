#ifndef MONKEYGAME_H
#define MONKEYGAME_H

#include <string>
#include "monkey.h"

using namespace std;


class MonkeyGame
{
    vector<Monkey> monkeys;
public:
    MonkeyGame(string fname);
    void part1();
    void part2();
private:
    void play(unsigned nbRounds, bool maxworry);
};

#endif // MONKEYGAME_H
