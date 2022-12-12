#include "hillclimbing.h"

#include "ioUtils.h"

HillClimbing::HillClimbing(string fname)
{
    auto input = bml::loadLines(fname);
    mapH = input.size();
    mapW = input[0].length();
    map.resize(mapH);
    for (auto &n: map) n.resize(mapW);

    unsigned x=0, y=0;
    for(string l: input) {
        for (x=0; x<mapW; x++) {
            char c=l.at(x);
            map[y][x] = c;
            if (c=='S') start=Coord(x,y);
            if (c=='E') end=Coord(x,y);
        }
        y++;
    }
}

void HillClimbing::part1()
{

}

void HillClimbing::part2()
{

}

inline char &HillClimbing::mapAt(Coord c)
{
    return map[c.y][c.x];
}

unsigned HillClimbing::manhattan(Coord a, Coord b)
{
    return abs(a.x-b.x)+abs(a.y-b.y);
}

vector<Coord> HillClimbing::accessibles(Coord c)
{
    vector<Coord> rv;
    Coord next(c);

}

