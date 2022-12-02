#ifndef PRSGAME_H
#define PRSGAME_H

#include <string>
#include <vector>

using namespace std;


#define ROCK_SCORE      1
#define PAPER_SCORE     2
#define SCISSOR_SCORE   3

#define LOST_SCORE  0
#define DRAW_SCORE  3
#define WIN_SCORE   6

#define A_ROCK      'A'
#define A_PAPER     'B'
#define A_SCISSOR   'C'

#define B_ROCK      'X'
#define B_PAPER     'Y'
#define B_SCISSOR   'Z'

#define SHOULD_LOOSE 'X'
#define SHOULD_DRAW  'Y'
#define SHOULD_WIN   'Z'

using Scores = pair<short,short>;

class PrsGame
{
    vector<string> rounds;
public:
    PrsGame(string fname);
    void part1();
    void part2();
private:
    Scores play(char p1, char p2);
    char shouldPlay(char p1, char goal);
};

#endif // PRSGAME_H
