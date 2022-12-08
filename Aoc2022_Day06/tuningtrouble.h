#ifndef TUNINGTROUBLE_H
#define TUNINGTROUBLE_H

#include <string>
using namespace std;

class TuningTrouble
{
    string input;
public:
    TuningTrouble(string fname);
    void part1();
    void part2();

protected:
    int startOfPacket(string s, size_t packetLength);
};

#endif // TUNINGTROUBLE_H
