#ifndef CATHODERAYTUBE_H
#define CATHODERAYTUBE_H

#include <array>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define CRT_WIDTH 40
#define CRT_HEIGHT 6

class CathodeRayTube
{
    vector<string> program;
    vector<int> compiled;
    array<array<char,CRT_WIDTH>,CRT_HEIGHT> crt;

    set<unsigned> breakPoints;
    int regX;
    int strengthSum;
public:
    CathodeRayTube(string fname);
    void part1();
    void part2();
private:
    void compile();
    void runProgram();
    void clearCrt();
    void displayCrt();
    void runDisplay();
};

#endif // CATHODERAYTUBE_H
