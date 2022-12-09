#include <iostream>
#include "aoc2022.h"
#include "ropebridge.h"

using namespace std;

int main()
{
    cout << "AoC 2022 Day 9" << endl;
    RopeBridge bridge(puzzlePath("day09_input.txt"));
//    RopeBridge bridge(puzzlePath("day09_test.txt"));

    bridge.part1();
    return 0;
}
