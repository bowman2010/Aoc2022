#ifndef CAMPCLEANING_H
#define CAMPCLEANING_H

#include <string>
#include <vector>
#include "elvespairjob.h"

using namespace std;

class CampCleaning
{
    vector<ElvesPairJob> jobs;
public:
    CampCleaning(string fname);
    void part1();
    void part2();
};

#endif // CAMPCLEANING_H
