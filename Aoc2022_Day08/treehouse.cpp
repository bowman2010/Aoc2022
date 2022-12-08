#include "treehouse.h"
#include "check.h"
#include "ioUtils.h"

TreeHouse::TreeHouse(string fname)
{
    treeLines = bml::loadLines(fname);
    mapHeight = treeLines.size();
    mapWidth  = treeLines[0].size();

    visibilityMap.resize(mapHeight);
    for (auto &vm: visibilityMap) {
        vm.resize(mapWidth);
    }
}

void TreeHouse::part1()
{
    cout << "Part #1" << endl;
    resetVisibility();
    cout << "     start Visibles : " << countVisible() << endl;
    checkFromWest();
    cout << " with West Visibles : " << countVisible() << endl;
    checkFromEast();
    cout << " with East Visibles : " << countVisible() << endl;
    checkFromNorth();
    cout << "with North Visibles : " << countVisible() << endl;
    checkFromSouth();
    cout << "with South Visibles : " << countVisible() << endl;
    cout << endl;
}

void TreeHouse::part2()
{
    cout << "Part #2" << endl;
    int bestLine, bestColumn;
    int bestScore = 0;

    for (int l=0; l<mapHeight; l++) {
        for (int c=0; c<mapHeight; c++) {
            int score = scenicScore(l,c);
            if (score>bestScore) {
                bestLine=l; bestColumn=c;
                bestScore = score;
            }
        }
    }

    cout << "Best scenic score at ("
         << bestLine << "," << bestColumn << "): "
         << bestScore << endl;
}

void TreeHouse::resetVisibility()
{
    for (int l=0; l<mapHeight; l++) {
        for (int c=0; c<mapHeight; c++) {
            visibilityMap[l][c] = false;
        }
    }
}

void TreeHouse::checkFromWest()
{
    for (int l=0; l<mapHeight; l++) {
        char hi = treeLines[l][0];
        visibilityMap[l][0] = true;
        for (int c=1; c<mapHeight; c++) {
            if (treeLines[l][c]>hi) {
                visibilityMap[l][c] = true;
                hi=treeLines[l][c];
            }
        }
    }
}

void TreeHouse::checkFromEast()
{
    for (int l=0; l<mapHeight; l++) {
        char hi = treeLines[l][mapWidth-1];
        visibilityMap[l][mapWidth-1] = true;
        for (int c=mapHeight-1; c>0; c--) {
            if (treeLines[l][c]>hi) {
                visibilityMap[l][c] = true;
                hi=treeLines[l][c];
            }
        }
    }
}

void TreeHouse::checkFromNorth()
{
    for (int c=0; c<mapWidth; c++) {
        char hi = treeLines[0][c];
        visibilityMap[0][c] = true;
        for (int l=1; l<mapHeight; l++) {
            if (treeLines[l][c]>hi) {
                visibilityMap[l][c] = true;
                hi=treeLines[l][c];
            }
        }
    }
}

void TreeHouse::checkFromSouth()
{
    for (int c=0; c<mapWidth; c++) {
        char hi = treeLines[mapHeight-1][c];
        visibilityMap[mapHeight-1][c] = true;
        for (int l=mapHeight-1; l>0; l--) {
            if (treeLines[l][c]>hi) {
                visibilityMap[l][c] = true;
                hi=treeLines[l][c];
            }
        }
    }
}

int TreeHouse::countVisible()
{
    int total = 0;
    for (auto &vl:visibilityMap) {
        for (auto vc: vl) {
            if (vc) total++;
        }
    }
    return total;
}

int TreeHouse::scenicScore(int line, int column)
{
    char localHeight = treeLines[line][column];

    int scoreNorth = 0;
    for (int l=line-1; l>=0 ; l--) {
        scoreNorth++;
        if (treeLines[l][column]>=localHeight) break;
    }

    int scoreSouth = 0;
    for (int l=line+1; l<mapHeight ; l++) {
        scoreSouth++;
        if (treeLines[l][column]>=localHeight) break;
    }

    int scoreWest = 0;
    for (int c=column-1; c>=0 ; c--) {
        scoreWest++;
        if (treeLines[line][c]>=localHeight) break;
    }

    int scoreEast = 0;
    for (int c=column+1; c<mapWidth; c++) {
        scoreEast++;
        if (treeLines[line][c]>=localHeight) break;
    }

    return scoreEast*scoreWest*scoreNorth*scoreSouth;
}
