#include <iostream>
#include "aoc2022.h"
#include "cathoderaytube.h"

using namespace std;

int main()
{
    cout << "AoC day 10 : cathode ray tube" << endl << endl;
    CathodeRayTube cr(puzzlePath("day10_input.txt"));
    cr.part1();
    cr.part2();
    return 0;
}
