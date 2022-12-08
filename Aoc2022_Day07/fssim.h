#ifndef FSSIM_H
#define FSSIM_H

#include <string>
#include <map>

using namespace std;

struct FsDir {
    FsDir* parent;
    map<string,FsDir> subdirs;
    map<string,int> files;

    FsDir(FsDir* p=nullptr) : parent(p) {};
    void mkdir(string dname);
    void mkfile(string fname, long size);
    FsDir *subdir(string dname);
    long usage();
    long usageRec();
    long maxn(long n);
};

class FsSim
{
    FsDir rootfs;
    FsDir* currentDir = &rootfs;
public:
    FsSim();
    void cd(string s);
    void mkdir(string dname);
    void mkfile(string fname, long sze);
    void findMaxN(long n);
};

#endif // FSSIM_H
