#ifndef HILLCLIMBING_H
#define HILLCLIMBING_H

#include <string>
#include <vector>

using namespace std;

struct Coord {
    int x;
    int y;
    Coord(int x, int y) : x(x), y(y) {}
};

using CharMap = vector<vector<char>>;

class HillClimbing
{
    unsigned mapW;
    unsigned mapH;
    Coord start = {0,0};
    Coord end  = {0,0};
    CharMap map;
public:
    HillClimbing(string fname);
    void part1();
    void part2();
private:
    inline char &mapAt(Coord c);
    unsigned manhattan(Coord a, Coord b);
    vector<Coord> accessibles(Coord c);
};

#endif // HILLCLIMBING_H
