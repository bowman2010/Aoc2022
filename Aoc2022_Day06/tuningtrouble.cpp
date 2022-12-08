#include "tuningtrouble.h"
#include <fstream>
#include <sstream>
#include "check.h"

TuningTrouble::TuningTrouble(string fname)
{
    fstream ifs(fname);
    CHECK(ifs);
    getline(ifs,input);
    CHECK(!input.empty());
}

constexpr bool check4(char *c)
{
    return     c[0]!=c[1] && c[0]!=c[2] && c[0]!=c[3]
            && c[1]!=c[2] && c[1]!=c[3]
            && c[2]!=c[3];
}

void TuningTrouble::part1()
{
    stringstream ssi(input);
    char ch4[4]; char nextCh;

    unsigned    charCount =4;
    size_t      charPtr = 0;

    ssi.get(ch4,5);

    while (!check4(ch4) && ssi.get(nextCh)) {
        ch4[charPtr] = nextCh;
        charPtr = (charPtr+1)%4;
        charCount++;
    }
    cout << "Part 1 = " << charCount << endl;

}

bool TuningTrouble::checkNoDupes(const unsigned n, const char *s) const
{
    return false;
}

constexpr bool checkN(size_t n, char *str)
{
    return true;
}



