#ifndef ELVESPAIRJOB_H
#define ELVESPAIRJOB_H
#include <string>

using namespace std;
class ElvesPairJob
{
    unsigned A1;
    unsigned A2;
    unsigned B1;
    unsigned B2;
public:
    ElvesPairJob(std::string s);
    bool fullContained() const;
    bool overlap() const;
    string str() const;
};

#endif // ELVESPAIRJOB_H
