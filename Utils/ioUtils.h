#ifndef IOUTILS_H
#define IOUTILS_H


#include <string>
#include <fstream>
#include <vector>
#include "check.h"

namespace bml {

using LinesBlock = std::vector<std::string>;

LinesBlock loadLines(std::string file_name)
{
    std::ifstream ifs(file_name);
    CHECK(ifs);

    std::vector<std::string> lines;
    std::string s;
    while (std::getline(ifs,s)) {
        lines.push_back(s);
    }
    return lines;
}

std::vector<LinesBlock> loadBlocks(std::string file_name)
{
    std::ifstream ifs(file_name);
    CHECK(ifs);

    std::vector<LinesBlock> topBlocks;

    std::string s;
    while (ifs.good()) {
        LinesBlock block;
        while (std::getline(ifs,s) && !s.empty()) {
            block.push_back(s);
        }
        topBlocks.push_back(block);
    }
    return topBlocks;
}


} // Eof namespace


#endif // IOUTILS_H
