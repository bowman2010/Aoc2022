#include "monkey.h"
#include <iostream>
#include <sstream>


Monkey::Monkey()
{
    activity = 0;
}

vector<pair<MonkeyNr, Item>> Monkey::throwItems()
{
    vector<pair<MonkeyNr, Item>> vitems;

    for (Item item: items) {
        activity++;

        if (trace)
        cout << "Monkey inspects an item with a worry level of " << item << endl;

        switch(op) {
        case '+' :
            item+=opVal;
            if (trace)
            cout << "  Worry level increases by " << opVal << " to " << item << endl;
            break;
        case '*':
            item*=opVal;
            if (trace)
            cout << "  Worry level is multiplied by " << opVal << " to " << item << endl;
            break;
        case '^':
            item=item*item;
            if (trace)
            cout << "  Worry level is squared to " << item << endl;
            break;
        }

        item=item/3;
        if (trace)
        cout << "Monkey gets bored with item. Worry level is divided by 3 to " << item << endl;

        if (item%testVal==0) {
            if (trace)
            cout << "Current worry level is divisible by " << opVal << endl;
            if (trace)
            cout << "Item with worry level " << item << " is thrown to monkey " << targetTrue << endl;
            vitems.push_back(make_pair(targetTrue,item));
        } else {
            if (trace)
            cout << "Current worry level is not divisible by " << testVal << endl;
            if (trace)
            cout << "Item with worry level " << item << " is thrown to monkey " << targetFalse << endl;
            vitems.push_back(make_pair(targetFalse,item));
        }
    }
    items.clear();
    return vitems;
}

string Monkey::itemsStr()
{
    stringstream sso;
    for (auto item : items)
        sso << item << ",";
    return sso.str();
}

void Monkey::addItem(Item item)
{
    items.push_back(item);
}

void Monkey::setOp(char newOp)
{
    op = newOp;
}

void Monkey::setOpVal(int newOpVal)
{
    opVal = newOpVal;
}

void Monkey::setTestVal(int newTestVal)
{
    testVal = newTestVal;
}

void Monkey::setTargetTrue(int newTargetTrue)
{
    targetTrue = newTargetTrue;
}

void Monkey::setTargetFalse(int newTargetFalse)
{
    targetFalse = newTargetFalse;
}

int Monkey::getActivity() const
{
    return activity;
}

