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

protected:
    bool checkNoDupes(const unsigned n, const char *s) const;
};

#endif // TUNINGTROUBLE_H
