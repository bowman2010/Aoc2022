#ifndef NOSPACELEFT_H
#define NOSPACELEFT_H

#include "fssim.h"
#include <string>
#include <vector>
#include <map>

using namespace std;


class NoSpaceLeft
{
    vector<string> input;
    FsSim fsim;
public:
    NoSpaceLeft(string fname);
    void part1();
    void part2();
protected:
    void run_commands();
};

#endif // NOSPACELEFT_H
