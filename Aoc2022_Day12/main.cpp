#include <iostream>
#include "aoc2022.h"
#include "hillclimbing.h"

using namespace std;

int main()
{
    cout << "Aoc2022 Day12 :  Hill Climbing Algorithm" << endl;
    HillClimbing hill(puzzlePath("day12_input.txt"));
    hill.part1();
    hill.part2();
    return 0;
}
