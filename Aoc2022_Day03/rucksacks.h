#ifndef RUCKSACKS_H
#define RUCKSACKS_H

#include <string>
#include <vector>
#include <set>

using namespace std;

class Rucksacks
{
    vector<string> sacks;
public:
    Rucksacks(string fname);
    void part1();
    void part2();
private:
    pair<string,string> splitInTwo(string s);
    set<char> charsInString(string s);
    int charValue(char c);
};

#endif // RUCKSACKS_H
