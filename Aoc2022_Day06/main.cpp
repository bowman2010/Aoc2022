#include <iostream>
#include "aoc2022.h"
#include "tuningtrouble.h"

using namespace std;

int main()
{
    cout << "Aoc 2022 Day 6" << endl;

    TuningTrouble ttr(puzzlePath("day06_input.txt"));
    ttr.part1();
    return 0;
}
