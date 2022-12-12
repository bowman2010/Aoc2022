#ifndef MONKEY_H
#define MONKEY_H

#include <vector>
#include <utility>
#include <string>

using namespace std;

using MonkeyNr = int;
using Item = unsigned long;

class Monkey
{
    bool trace = false;
    char op;
    int  opVal;
    int  testVal;
    int  targetTrue;
    int  targetFalse;
    int  activity;
    vector<Item> items;
public:
    Monkey();
    vector<pair<MonkeyNr,Item>> throwItems();

    string itemsStr();
    void addItem(Item item);

    void setOp(char newOp);
    void setOpVal(int newOpVal);
    void setTestVal(int newTestVal);
    void setTargetTrue(int newTargetTrue);
    void setTargetFalse(int newTargetFalse);
    int getActivity() const;
};

#endif // MONKEY_H
