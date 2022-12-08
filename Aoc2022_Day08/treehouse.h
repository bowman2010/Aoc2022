#ifndef TREEHOUSE_H
#define TREEHOUSE_H

#include <string>
#include <vector>
using namespace std;

class TreeHouse
{
    int mapWidth;
    int mapHeight;
    vector<string> treeLines;
    vector<vector<bool>> visibilityMap;
public:
    TreeHouse(string fname);
    void part1();
    void part2();
private:
    void resetVisibility();
    void checkFromWest();
    void checkFromEast();
    void checkFromNorth();
    void checkFromSouth();
    int countVisible();
    int scenicScore(int line, int column);
};

#endif // TREEHOUSE_H
