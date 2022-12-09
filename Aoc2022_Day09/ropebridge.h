#ifndef ROPEBRIDGE_H
#define ROPEBRIDGE_H

#include <string>
#include <vector>
#include <set>

using namespace std;

struct Position {
    int row;
    int column;
    Position();
    Position(int  row, int column);
    bool touch(const Position &other );
};

/* Set need a comparator */
struct PosComp {
    bool operator()(const Position& p1,
                    const Position& p2) const
    {
        // Use manhattan distance
        int diff1 = p1.column - p2.column;
        int diff2 = p1.row - p2.row;
        return abs(diff1)+abs(diff2);
    }
};

class RopeBridge
{
    vector<string> commands;
    Position headPos;
    Position tailPos;
    set<Position,PosComp> tailTrack;
public:
    RopeBridge(string fname);
    void part1();
    void part2();
    void showMap();
private:
    void reset();
    void runCommands();
    void doCommand(char direction, int steps);
    void moveTailTo(int r, int c);
    void up();
    void down();
    void left();
    void right();
};

#endif // ROPEBRIDGE_H
