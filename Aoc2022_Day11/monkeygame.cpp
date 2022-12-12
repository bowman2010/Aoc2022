#include "monkeygame.h"
#include "ioUtils.h"
#include "strUtils.h"


//Monkey 0:
//  Starting items: 79, 98
//  Operation: new = old * 19
//  Test: divisible by 23
//    If true: throw to monkey 2
//    If false: throw to monkey 3

MonkeyGame::MonkeyGame(string fname)
{
    vector<bml::LinesBlock> vs = bml::loadBlocks(fname);
    unsigned monknr = 0;
    for (auto monkeyDef: vs) { // For each monkey definition

        Monkey monkey;
        monknr++;

        // Get the items
        string itemsList = bml::splitStr(monkeyDef[1],':')[1];
        auto items = bml::splitStr(itemsList,',');
        for (auto &item : items) monkey.addItem(stoi(item));

        // Get operation and value
        char op = monkeyDef[2][23];
        int opval = 1; // Not zero because of modulo
        string opvalstr = monkeyDef[2].substr(25);
        if (opvalstr.compare("old")==0) op = '^';
            else opval=stoi(opvalstr);
        monkey.setOp(op);
        monkey.setOpVal(opval);

        // Get test value
        int tstVal = stoi(monkeyDef[3].substr(21));
        monkey.setTestVal(tstVal);

        // Get throw destinations
        int throwTrue = stoi(monkeyDef[4].substr(29));
        int throwFalse = stoi(monkeyDef[5].substr(30));
        monkey.setTargetTrue(throwTrue);
        monkey.setTargetFalse(throwFalse);

        monkeys.push_back(monkey);
    }
}

void MonkeyGame::part1()
{
    cout << "Part #1 : " << endl;
    for (int round=1; round<=20; round++) {
        cout << " -- Round " << round << " --" << endl;
        int monkeyNr = 0;
        for(Monkey &monkey : monkeys) {
            cout << "  Monkey " << monkeyNr++ << ":" << endl;
            auto sendList = monkey.throwItems();
            for (auto snd : sendList) {
                cout << "Mokey throws item " << snd.second << " to monkey " << snd.first << endl;
                monkeys[snd.first].addItem(snd.second);
            }
            cout << endl;
        }
        cout << endl;
        monkeysList();
        cout << " -- End round --" << endl << endl;
    }

    cout << "Results" << endl;
    vector<int> activity;
    for (int i=0, total = monkeys.size(); i<total; ++i) {
        cout << "Monkey " << i << " activity = " << monkeys[i].getActivity() << endl;
        activity.push_back(monkeys[i].getActivity());
    }
    sort(activity.begin(),activity.end(),greater<int>());
    cout << "top activities : " << activity[0] << " " << activity[1] << endl;
    cout << "response : " << activity[0]*activity[1] << endl;
}

void MonkeyGame::monkeysList()
{
    unsigned i=0;
    for (auto m : monkeys)
        cout << "Monkey " << i++ << ": " << m.itemsStr() << endl;
}
