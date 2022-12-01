#ifndef AOC2022_H
#define AOC2022_H
#include <string>

#define PUZZLE_PATH "/home/bowman/Dev/AOC2022_Puzzles/"

std::string puzzlePath(std::string fname) {
    std::string ppath = PUZZLE_PATH+fname;
    return ppath;
}
#endif // AOC2022_H
