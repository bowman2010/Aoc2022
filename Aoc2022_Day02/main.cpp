#include <iostream>
#include "aoc2022.h"
#include "prsgame.h"

using namespace std;

int main()
{

    cout << "AOC 2022 Day #1" << endl << endl;
    PrsGame game(puzzlePath("day02_input.txt"));
//    PrsGame game(puzzlePath("day02_test.txt"));
    game.part1();
    game.part2();
    return 0;
}
