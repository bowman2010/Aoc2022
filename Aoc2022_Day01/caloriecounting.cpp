#include "caloriecounting.h"
#include <algorithm>
#include <fstream>
#include "check.h"

CalorieCounting::CalorieCounting(string fname)
{
    string str1;
    ifstream ifs(fname);
    CHECK(ifs);

    while (ifs.good()) {
        vector<unsigned> v1;
        while (getline(ifs,str1) && !str1.empty())
        {
            unsigned nbCals = stoi(str1);
            v1.push_back(nbCals);
        }
        elfCals.push_back(v1);
    }
}

void CalorieCounting::part1()
{
    cout << "Part #1" << endl;

    unsigned maxCount = 0;
    for (auto &ecal : elfCals ) {
        unsigned count = 0;
        for (unsigned n: ecal) count+=n;
        if (count>maxCount) maxCount=count;
    }
    cout << "Max calories count for one elf : " << maxCount << endl << endl;
}

void CalorieCounting::part2()
{
    vector<unsigned> v1;
    cout << "Part #2" << endl;

    for (auto &ecal : elfCals ) {
        unsigned count = 0;
        for (unsigned n: ecal) count+=n;
        v1.push_back(count);
    }
    sort(v1.begin(),v1.end(),greater<unsigned>());

    unsigned total=0;
    for (unsigned i=0; i<3; i++)
    {
        cout << "Elf #" << " carries " << v1[i] << " camories." << endl;
        total += v1[i];
    }
    cout << "Top 3 elves carry " << total << " total caloriess" << endl << endl;
}
