#include "rucksacks.h"
#include <fstream>
#include <algorithm>
#include "check.h"

Rucksacks::Rucksacks(string fname)
{
    string str1;
    ifstream ifs(fname);
    CHECK(ifs);

    while (getline(ifs,str1)&&!str1.empty()) {
        sacks.push_back(str1);
    }
}

void Rucksacks::part1()
{
    unsigned total = 0;
    unsigned n = 1;
    for (string &sack : sacks)
    {
        pair<string,string> sp = splitInTwo(sack);
        cout << "Sack #" << n << " " << sp.first << "  -  " << sp.second << endl;
        set<char> charsInA = charsInString(sp.first);
        set<char> charsInB = charsInString(sp.second);
        for (char c: charsInA) {
            if (charsInB.find(c)!=charsInB.end()) {
                int charv = charValue(c);
                cout << "duplicate char : " << c << " value=" << charv << endl;
                total += charv;
            }
        }
        n++;
    }
    cout << "Total = " << total << endl;
}

void Rucksacks::part2()
{
    unsigned sum = 0;
    unsigned groupNr = 1;
    auto itr = sacks.begin();
    while (itr!=sacks.end()) {
        string sack1 = *itr++;
        string sack2 = *itr++;
        string sack3 = *itr++;
        cout << "Group " << groupNr++ << endl;
        cout << "  " << sack1 << endl;
        cout << "  " << sack2 << endl;
        cout << "  " << sack3 << endl;
        cout << endl;

        set<char> cis1 = charsInString(sack1);
        set<char> cis2 = charsInString(sack2);
        set<char> cis3 = charsInString(sack3);

        std::set<int> allchars;
        allchars.insert(cis1.begin(), cis1.end());
        allchars.insert(cis2.begin(), cis2.end());
        allchars.insert(cis3.begin(), cis3.end());

        for (char c: allchars) {
            if (
                    cis1.find(c)!=cis1.end()
                    && cis2.find(c)!=cis2.end()
                    && cis3.find(c)!=cis3.end()
            ) {
                cout << "Common char : " << c << endl;
                sum += charValue(c);
            }
        }
    }
    cout << "Priorities sum = " << sum << endl;
}

pair<string, string> Rucksacks::splitInTwo(string s)
{
    unsigned strlend2 = s.length()/2;
    return {
      s.substr(0,strlend2),
      s.substr(strlend2,strlend2)
    };
}

set<char> Rucksacks::charsInString(string s)
{
    set<char> cs;
    for (char c: s) {
        cs.emplace(c);
    }
    return cs;
}

int Rucksacks::charValue(char c)
{
    if (isupper(c)) return c-'A'+27;
    else return c-'a'+1;
}
