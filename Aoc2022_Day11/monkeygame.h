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

    void monkeysList();
};

#endif // MONKEYGAME_H
