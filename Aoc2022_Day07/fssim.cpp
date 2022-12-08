#include "fssim.h"
#include <iostream>
#include <queue>

using namespace std;

FsSim::FsSim()
{
    rootfs = FsDir();
    currentDir = &rootfs;
}

void FsSim::cd(string s)
{
    if (s.compare("/")==0) {
        currentDir = &rootfs;
        return;
    }
    if (s.compare("..")==0) {
        currentDir = currentDir->parent;
        return;
    }
    FsDir *dir = currentDir->subdir(s);
    if (dir!=nullptr) currentDir=dir;
    else { cout << "Cannot cd to " << s << endl; }
}

void FsSim::mkdir(string dname)
{
    currentDir->mkdir(dname);
}

void FsSim::mkfile(string fname, long sze)
{
    currentDir->mkfile(fname,sze);
}

void FsSim::findMaxN(long n)
{
    queue<FsDir*> q;
    long total = 0;
    q.push(&rootfs);
    while (!q.empty()) {
        FsDir* d = q.front(); q.pop();
        long n2 = d->usageRec();
        if (n2<=n) {
            cout << "Sze: " << n2 << endl;
            total+=n2;
        }
        for (auto &nd: d->subdirs) q.push(&nd.second);
    }
    cout << "Total = " << total << endl;
}


void FsDir::mkdir(string dname)
{
    if (subdirs.count(dname)==0) {
        subdirs.insert(make_pair(dname,FsDir(this)));
    } else {
        cout << "dir already exist : " << dname << endl;
    }
}

void FsDir::mkfile(string fname, long size)
{
    if (files.count(fname)==0) {
        files.insert(make_pair(fname, size));
    } else {
        cout << "file already exist : " << fname << endl;
    }
}

FsDir *FsDir::subdir(string dname)
{
    auto sdptr = subdirs.find(dname);
    if (sdptr==subdirs.end()) return nullptr;
    return &(sdptr->second);
}

long FsDir::usage()
{
    long usg = 0;
    for (auto &f: files) {
        usg+=f.second;
    }
    return usg;
}

long FsDir::usageRec()
{
    long usg = usage();
    for (auto &d: subdirs) {
        usg+=d.second.usage();
    }
    return usg;
}
