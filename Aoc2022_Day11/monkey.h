#ifndef MONKEY_H
#define MONKEY_H

#include <vector>
#include <utility>
#include <string>

using namespace std;

using MonkeyNr = int;
using Item = unsigned long long;

class Monkey
{
    bool trace = false;
    char op;
    int  opVal;
    int  testVal;
    int  targetTrue;
    int  targetFalse;
    unsigned long long activity;
    vector<Item> items;
public:
    Monkey();
    vector<pair<MonkeyNr,Item>> throwItems(bool maxworry=false);

    string itemsStr();
    void addItem(Item item);

    void setOp(char newOp);
    void setOpVal(int newOpVal);
    void setTestVal(int newTestVal);
    void setTargetTrue(int newTargetTrue);
    void setTargetFalse(int newTargetFalse);
    unsigned long long getActivity() const;
};

#endif // MONKEY_H
