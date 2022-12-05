#include <iostream>
#include "aoc2022.h"
#include "supplystacks.h"

using namespace std;

int main()
{
    cout << "AoC 2022 Day 5" << endl;

    SupplyStacks supplyStacks(puzzlePath("day05_input.txt"));
    supplyStacks.part1();
    supplyStacks.part2();

    return 0;
}
