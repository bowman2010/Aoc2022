#ifndef AOC2022_H
#define AOC2022_H
#include <string>
#include <cstdlib>

#define PUZZLES_PATH "/home/bowman/Dev/Cpp_Projects/Aoc2022/Puzzles/"

std::string puzzlePath(std::string fname) {
    if(const char* ve = std::getenv("AOC2022_PPATH"))
    {
        std::string ppath(ve);
        ppath.append("/"+fname);
        return ppath;
    }
    else exit(2);
}
#endif // AOC2022_H
