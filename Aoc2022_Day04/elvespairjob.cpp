#include "elvespairjob.h"
#include <sstream>
#include <iostream>

ElvesPairJob::ElvesPairJob(std::string s)
{
    stringstream ssi(s);
    string sa,sb;
    string sa1,sa2,sb1,sb2;

    getline(ssi,sa,',');
    getline(ssi,sb,',');

    stringstream ssa(sa);
    getline(ssa,sa1,'-');
    getline(ssa,sa2,'-');

    stringstream ssb(sb);
    getline(ssb,sb1,'-');
    getline(ssb,sb2,'-');

    A1 = stoi(sa1);
    A2 = stoi(sa2);
    B1 = stoi(sb1);
    B2 = stoi(sb2);

}

bool ElvesPairJob::fullContained() const
{
    return ( A1>=B1 && A2<=B2 ) || ( B1>=A1 && B2<=A2 );
}

bool ElvesPairJob::overlap() const
{
    return     ( A1>=B1 && A1<=B2)
            || ( A2>=B1 && A2<=B1)
            || ( B1>=A1 && B1<=A2)
            || ( B2>=A1 && B2<=A2)
            ;
}

string ElvesPairJob::str() const
{
    stringstream sso;
    sso << A1 << "-" << A2 << "," << B1 << "-" << B2;
    return sso.str();
}
