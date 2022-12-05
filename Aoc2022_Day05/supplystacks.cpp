#include "supplystacks.h"
#include "check.h"
#include "ioUtils.h"
#include "strUtils.h"

#include <sstream>
#include <fstream>
#include <cctype>

SupplyStacks::SupplyStacks(string fname)
{
    vector<bml::LinesBlock> puzzle = bml::loadBlocks(fname);

    loadMap(puzzle[0]);
    orig_stacks = stacks;
    loadActions(puzzle[1]);
}

void SupplyStacks::part1()
{
    cout << "Part #1" << endl;
    stacks = orig_stacks;
    for (CraneAction ca: actionsList)
        doCrane9000Action(ca);
    displayStacks();
}

void SupplyStacks::part2()
{
    cout << "Part #2" << endl;
    stacks = orig_stacks;
    for (CraneAction ca: actionsList)
        doCrane9001Action(ca);
    displayStacks();
}

void SupplyStacks::loadMap(vector<string> &mapDef)
{
    mapDef.pop_back();
    while(!mapDef.empty()) {
        string s = mapDef.back();
        for (int i=0; i<9; i++) {
            if (isalpha(s[i*4+1])) {
                stacks[i].push(s[i*4+1]);
            }
        }
        mapDef.pop_back();
    }
}

void SupplyStacks::loadActions(vector<string> &actionsdef)
{
    for (string &line: actionsdef)
        actionsList.push_back(CraneAction(line));

}

void SupplyStacks::doCrane9000Action(CraneAction action)
{
    for (int cnt=0; cnt<action.count; cnt++) {
        char c = stacks[action.from-1].top();
        stacks[action.from-1].pop();
        stacks[action.to-1].push(c);
    }
}

void SupplyStacks::doCrane9001Action(CraneAction action)
{
    stack<char> temp;

    for (int cnt=0; cnt<action.count; cnt++) {
        char c = stacks[action.from-1].top();
        stacks[action.from-1].pop();
        temp.push(c);
    }

    while (!temp.empty()) {
        char c = temp.top();
        stacks[action.to-1].push(c);
        temp.pop();
    }

}

void SupplyStacks::displayStacks()
{
    for (auto st : stacks) cout << st.top();
    cout << endl;
}

CraneAction::CraneAction(string s)
{
    stringstream ssi(s);
    string dummyStr;

    ssi >> dummyStr; ssi >> count;
    ssi >> dummyStr; ssi >> from;
    ssi >> dummyStr; ssi >> to;
}
