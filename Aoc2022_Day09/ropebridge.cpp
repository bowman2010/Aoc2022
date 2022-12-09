#include "ropebridge.h"
#include "ioUtils.h"
#include <sstream>

RopeBridge::RopeBridge(string fname)
{
    commands = bml::loadLines(fname);
}

void RopeBridge::part1()
{
    cout << "Part #1:" << endl;

    reset();
    runCommands();
    cout << "Tail positions count = " << tailTrack.size()-1 << endl;
}

void RopeBridge::part2()
{

}

void RopeBridge::showMap()
{
    int maxRow = 5;
    int maxCol = 6;

    char map[maxRow][maxCol];
    for (int r=0; r<maxRow; r++)
        for (int c=0; c<maxCol; c++)
            map[r][c] = '.';

    map[0][0] = 's';
    for (auto &p : tailTrack) {
        map[p.row][p.column] = '#';
    }
    map[tailPos.row][tailPos.column] = 'T';
    map[headPos.row][headPos.column] = 'H';
    cout << endl;
    for (int r=maxRow-1; r>=0; r--) {
        for (int c=0; c<maxCol; c++) cout << map[r][c];
        cout << endl;
    }
    cout << endl;
}

void RopeBridge::reset()
{
    headPos = Position(0,0);
    tailPos = Position(0,0);
    tailTrack.insert(tailPos);
}

void RopeBridge::runCommands()
{
    char direction;
    int steps;
    for (string &cmd: commands) {
        stringstream ssi(cmd);
        ssi >> direction;
        ssi >> steps;
        doCommand(direction,steps);
    }
}

void RopeBridge::doCommand(char direction, int steps)
{
    cout << "== " << direction << " " << steps << " ==" << endl;
    for (int i=0; i<steps; i++) {
        switch (direction) {
            case 'U' :  up(); break;
            case 'D' :  down(); break;
            case 'L' :  left(); break;
            case 'R' :  right(); break;
            default  : break;
        }
//        showMap();
    }
}

void RopeBridge::moveTailTo(int r, int c)
{
    tailPos = {r,c};
    tailTrack.insert(tailPos);
}

void RopeBridge::up()
{
    headPos.row++;
    if (!headPos.touch(tailPos)) moveTailTo(headPos.row-1,headPos.column);
}

void RopeBridge::down()
{
    headPos.row--;
    if (!headPos.touch(tailPos)) moveTailTo(headPos.row+1,headPos.column);
}

void RopeBridge::left()
{
    headPos.column--;
    if (!headPos.touch(tailPos)) moveTailTo(headPos.row,headPos.column+1);
}

void RopeBridge::right()
{
    headPos.column++;
    if (!headPos.touch(tailPos)) moveTailTo(headPos.row,headPos.column-1);
}

Position::Position()
{
    row=0; column=0;
}

Position::Position(int row, int column)
{
    this->row = row;
    this->column = column;
}

bool Position::touch(const Position &other)
{
    int dr = abs(other.row - row);
    int dc = abs(other.column - column);
    if (dr>1 || dc>1) return false;
    if (dr+dc<=2) return true;
    return false;
}

