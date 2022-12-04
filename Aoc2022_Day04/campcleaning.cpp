#include "campcleaning.h"
#include <fstream>
#include "check.h"


CampCleaning::CampCleaning(string fname)
{
    string s1;
    ifstream ifs(fname);
    CHECK(ifs);
    while (getline(ifs,s1) && !s1.empty())
    {
        ElvesPairJob ep(s1);
        jobs.push_back(ep);
    }
    cout << "Loaded " << jobs.size() << " job lines" << endl;
}

void CampCleaning::part1()
{
    cout << "Part #1" << endl;
    unsigned total = 0;
    for (ElvesPairJob epj : jobs) {
        if (epj.fullContained()) total++;
    }
    cout << "Total of fully contained jobs : " << total << endl;
    cout << endl;
}

void CampCleaning::part2()
{
    cout << "Part #2" << endl;
    unsigned total = 0;
    for (ElvesPairJob epj : jobs) {
        if (epj.overlap()) {
            total++;
        }
    }
    cout << "Total of overlapping jobs : " << total << endl;
    cout << endl;
}
