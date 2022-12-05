#include <iostream>
#include "strUtils.h"

using namespace std;

int main()
{


    string s0 = "  TheString   ";
    string s1 = bml::toLower(s0);
    string s2 = bml::toUpper(s0);
    string s3 = bml::trim(s0);
    string s4 = bml::trimLeft(s0);
    string s5 = bml::trimRight(s0);

    cout << "s0 : [" << s0 << "]" << endl;
    cout << "s1 : [" << s1 << "]" << endl;
    cout << "s2 : [" << s2 << "]" << endl;
    cout << "s3 : [" << s3 << "]" << endl;
    cout << "s4 : [" << s4 << "]" << endl;
    cout << "s5 : [" << s5 << "]" << endl;
    cout << endl;

}
