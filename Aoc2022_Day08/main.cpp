#include <iostream>
#include "aoc2022.h"
#include "treehouse.h"

using namespace std;

int main()
{
    TreeHouse th(puzzlePath("day08_input.txt"));
//    TreeHouse th(puzzlePath("day08_test.txt"));
    th.part1();
    th.part2();
    return 0;
}
