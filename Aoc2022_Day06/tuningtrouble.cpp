#include "tuningtrouble.h"
#include <fstream>
#include <sstream>
#include <set>
#include "check.h"

TuningTrouble::TuningTrouble(string fname)
{
    fstream ifs(fname);
    CHECK(ifs);
    getline(ifs,input);
    CHECK(!input.empty());
}

void TuningTrouble::part1()
{
    cout << "Part #1" << endl;
    cout << "  response : " << startOfPacket(input,4);
}

void TuningTrouble::part2()
{
    cout << "Part #2" << endl;
    cout << "  response : " << startOfPacket(input,14);
}

int TuningTrouble::startOfPacket(string s, size_t packetLength)
{
    set<char> foundChars;
    for (size_t startPos=0; startPos<s.length(); startPos++) {

        foundChars.clear();
        foundChars.insert(s[startPos]);

        size_t npos;
        for (npos=1; npos<packetLength; npos++) {
            if (foundChars.count(s[startPos+npos])) break;
            foundChars.insert(s[startPos+npos]);
        }
        if (npos==packetLength) return startPos+npos;
    }
    return -1;
}




