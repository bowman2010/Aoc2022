#include "cathoderaytube.h"
#include "ioUtils.h"

CathodeRayTube::CathodeRayTube(string fname)
{
    program = bml::loadLines(fname);
    compile();
}

void CathodeRayTube::part1()
{
    cout << endl << "Part #1:" << endl;
    breakPoints = { 20, 60, 100, 140, 180, 220 };
    runProgram();
    cout << "Sum of strengths : " << strengthSum << endl;
}

void CathodeRayTube::part2()
{
    cout << endl << "Part #2:" << endl;
    clearCrt();
    runDisplay();
    displayCrt();
}

void CathodeRayTube::compile()
{
    for (string &progline : program)
    {
        if (progline.starts_with("noop")) compiled.push_back(0);
        else if (progline.starts_with("add")) {
            compiled.push_back(0);
            compiled.push_back(stoi(progline.substr(5)));
        }
    }
}

void CathodeRayTube::runProgram()
{
    regX = 1;
    unsigned cycle = 0;
    strengthSum = 0;
    for (int n: compiled) {
        cycle++;
        if (breakPoints.contains(cycle)) {
            int strength =cycle+regX;
            cout << "BreakPoint " << cycle << " regX=" << regX << " strength=" << strength << endl;
            strengthSum += cycle*regX;
        }
        regX += n;
    }
}

void CathodeRayTube::clearCrt()
{
    for (auto &l: crt)
        for (char &c: l) c=' ';
}

void CathodeRayTube::displayCrt()
{
    cout << "Crt:" << endl;
    for (auto l: crt) {
        cout << " |";
        for (char c: l) cout << c;
        cout << "|" << endl;
    }
}

void CathodeRayTube::runDisplay()
{
    regX = 1;
    unsigned cycle = 0;

    for (int n: compiled) {
        cycle++;
        unsigned crtX = (cycle-1)%CRT_WIDTH;
        unsigned crtY = (cycle-1)/CRT_WIDTH;

        if (crtX>=regX-1 && crtX<=regX+1) crt[crtY][crtX] = '#';
//            else crt[crtY][crtX] = '.';

        cout << "crt " << crtX << " " << crtY << endl;

        regX += n;
    }
}
