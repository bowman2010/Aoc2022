#ifndef CALORIECOUNTING_H
#define CALORIECOUNTING_H

#include <string>
#include <vector>

using namespace std;

class CalorieCounting
{
    vector<vector<unsigned>> elfCals;

public:
    CalorieCounting(string fname);
    void part1();
    void part2();
};

#endif // CALORIECOUNTING_H
