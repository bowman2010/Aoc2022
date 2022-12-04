#include <iostream>
#include "strUtils.h"

using namespace std;

int main()
{
    string s = "TheString";
    string s2 = bml::leftPad(s,20,'.');
    cout << s2 << endl;
    string s3 = bml::rightPad(s,20,'.');
    cout << s3 << endl;
    return 0;
}
