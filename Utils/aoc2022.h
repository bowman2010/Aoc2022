#ifndef AOC2022_H
#define AOC2022_H
#include <string>
#include <cstdlib>

#define PUZZLES_PATH "/home/bowman/Dev/Cpp_Projects/Aoc2022/Puzzles/"

std::string puzzlePath(std::string fname) {
        std::string ppath(PUZZLES_PATH);
        ppath.append("/"+fname);
        return ppath;
}
#endif // AOC2022_H
