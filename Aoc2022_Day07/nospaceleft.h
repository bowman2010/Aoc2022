#ifndef NOSPACELEFT_H
#define NOSPACELEFT_H

#include <string>
#include <vector>
#include <map>

using namespace std;


struct FsDir {
    FsDir *parent;
    map<string,FsDir*> subdirs;
    map<string,size_t> files;

    FsDir(FsDir *parent);
    FsDir* subdir(string dname);
    void addDir(string dname);
    void addFile(string fname,size_t size);
    size_t usage();
};

class NoSpaceLeft
{
    vector<string> input;
    FsDir fsRoot = nullptr;
    FsDir &currentDir = fsRoot;
public:
    NoSpaceLeft(string fname);
    void part1();
    void part2();
protected:
    void run_commands();
};

#endif // NOSPACELEFT_H
