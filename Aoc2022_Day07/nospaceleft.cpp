#include "nospaceleft.h"
#include "ioUtils.h"
#include <sstream>

NoSpaceLeft::NoSpaceLeft(string fname)
{
    input = bml::loadLines(fname);
    fsRoot = new FsDir(nullptr);
}

void NoSpaceLeft::part1()
{
    run_commands();
    cout << "here" << endl;
}

void NoSpaceLeft::part2()
{

}

void NoSpaceLeft::run_commands()
{

    auto itr = input.begin();

    while (itr<input.end()) {
        if (itr->compare(0,4,"$ cd")==0) {
            string dname = itr->substr(5);

            if (dname.compare("/")==0) {
                currentDir = fsRoot;
            }
            else {
                currentDir = currentDir.subdir(dname);
            }
            itr++;
        }
        else
        if (itr->compare(0,4,"$ ls")==0) {
             itr++;
            while (itr<input.end() && itr->compare(0,1,"$")!=0) {
                string s1,s2;
                stringstream ssi(*itr);
                ssi >> s1; ssi >> s2;
                if (s1.compare("dir")==0) {
                    currentDir.addDir(s2);
                } else {
                    currentDir.addFile(s2,stoi(s1));
                }
                itr++;
            }
        }
    }
}


FsDir::FsDir(FsDir *parent)
{
    this->parent = parent;
}

FsDir *FsDir::subdir(string dname)
{
    if (dname.compare("..")==0) return parent;
    auto df = subdirs.find(dname);
    if (df==subdirs.end()) {
        cout << "dir not found : " << dname << endl;
        return nullptr;
    }
    return df->second;
}

void FsDir::addDir(string dname)
{
    subdirs.insert(make_pair(dname,new FsDir(this)));
}

void FsDir::addFile(string fname, size_t size)
{
    files.insert(make_pair(fname,size));
}

size_t FsDir::usage()
{
    return 0;
}
