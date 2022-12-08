#include "nospaceleft.h"
#include "ioUtils.h"
#include <sstream>

NoSpaceLeft::NoSpaceLeft(string fname)
{
    input = bml::loadLines(fname);
}

void NoSpaceLeft::part1()
{
    run_commands();
    fsim.findMaxN(100000);
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
            fsim.cd(dname);
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
                    fsim.mkdir(s2);
                } else {
                    fsim.mkfile(s2,stoi(s1));
                }
                itr++;
            }
        }
    }
}


