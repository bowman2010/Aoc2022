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
    loadActions(puzzle[1]);
}

void SupplyStacks::part1()
{
    cout << "Part #1" << endl;

    for (CraneAction ca: actionsList)
        doCraneAction(ca);
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

void SupplyStacks::doCraneAction(CraneAction action)
{
    for (int cnt=0; cnt<action.count; cnt++) {
        char c = stacks[action.from-1].top();
        stacks[action.from-1].pop();
        stacks[action.to-1].push(c);
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
