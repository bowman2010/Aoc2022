#include <iostream>
#include "aoc2022.h"
#include "monkeygame.h"

using namespace std;

int main()
{
    cout << "Aoc2022 Day11 :  Monkey in the Middle" << endl;
    MonkeyGame game(puzzlePath("day11_input.txt"));
//    MonkeyGame game(puzzlePath("day11_test.txt"));
    game.part1();
    game.part2();
    return 0;
}
