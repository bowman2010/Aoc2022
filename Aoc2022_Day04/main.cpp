#include <iostream>
#include "aoc2022.h"
#include "campcleaning.h"

using namespace std;

int main()
{
    cout << "Aoc 2022 day 04" << endl;
    CampCleaning cc(puzzlePath("day04_input.txt"));
//    CampCleaning cc(puzzlePath("day04_test.txt"));
    cc.part1();
    cc.part2();
    return 0;
}
