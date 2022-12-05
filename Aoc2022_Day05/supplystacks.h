#ifndef SUPPLYSTACKS_H
#define SUPPLYSTACKS_H

#include <string>
#include <vector>
#include <stack>
#include <array>

using namespace std;

struct CraneAction {
    int count;
    int from;
    int to;
    CraneAction(string s);
};

class SupplyStacks
{
    array<stack<char>,9> orig_stacks;
    array<stack<char>,9> stacks;
    vector<CraneAction> actionsList;
public:
    SupplyStacks(string fname);
    void part1();
    void part2();
private:
    void loadMap(vector<string> &mapDefStr);
    void loadActions(vector<string> &actionsdef);
    void doCrane9000Action(CraneAction action);
    void doCrane9001Action(CraneAction action);
    void displayStacks();
};

#endif // SUPPLYSTACKS_H
