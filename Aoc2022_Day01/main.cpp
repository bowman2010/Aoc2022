#include <iostream>
#include "aoc2022.h"
#include "caloriecounting.h"

using namespace std;

int main()
{
//    CalorieCounting calcount(puzzlePath("day01_test.txt"));

    cout << "AOC 2022 Day #1" << endl << endl;
    CalorieCounting calcount(puzzlePath("day01_input.txt"));
    calcount.part1();
    calcount.part2();
    return 0;
}
