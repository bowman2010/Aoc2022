#include "prsgame.h"
#include <check.h>
#include <fstream>

PrsGame::PrsGame(string fname)
{
    string str1;
    ifstream ifs(fname);
    CHECK(ifs);

    while (getline(ifs,str1)) {
        rounds.push_back(str1);
    }
}

void PrsGame::part1()
{
    unsigned playerScore = 0;
    unsigned oppenentScore = 0;

    for (string round : rounds) {
        auto scores = play(round[0],round[2]);
        oppenentScore += scores.first;
        playerScore   += scores.second;
    }
    cout << "Part 1:" << endl;
    cout << "Player score   : " << playerScore << endl;
    cout << "Opponent score : " << oppenentScore << endl;
    cout << endl;
}

void PrsGame::part2()
{
    unsigned playerScore = 0;
    unsigned oppenentScore = 0;

    for (string round : rounds) {
        auto scores = play(round[0],shouldPlay(round[0],round[2]));
        oppenentScore += scores.first;
        playerScore   += scores.second;
    }
    cout << "Part 2:" << endl;
    cout << "Player score   : " << playerScore << endl;
    cout << "Opponent score : " << oppenentScore << endl;
    cout << endl;
}

Scores PrsGame::play(char p1, char p2)
{
    switch (p1) {
        case (A_ROCK) : {
            switch (p2) {
            case (B_ROCK)       : return { ROCK_SCORE+DRAW_SCORE,   ROCK_SCORE+DRAW_SCORE       };
            case (B_PAPER)      : return { ROCK_SCORE+LOST_SCORE,   PAPER_SCORE+WIN_SCORE       };
            case (B_SCISSOR)    : return { ROCK_SCORE+WIN_SCORE,    SCISSOR_SCORE+LOST_SCORE    };
            default: CHECK_FAIL();
            }; break;
        }; break;

        case (A_PAPER) : {
            switch (p2) {
            case (B_ROCK)       : return { PAPER_SCORE+WIN_SCORE,   ROCK_SCORE+LOST_SCORE       };
            case (B_PAPER)      : return { PAPER_SCORE+DRAW_SCORE,  PAPER_SCORE+DRAW_SCORE      };
            case (B_SCISSOR)    : return { PAPER_SCORE+WIN_SCORE,   SCISSOR_SCORE+WIN_SCORE     };
            default: CHECK_FAIL();
            }; break;
        }; break;

        case (A_SCISSOR) : {
            switch (p2) {
            case (B_ROCK)       : return { SCISSOR_SCORE+LOST_SCORE, ROCK_SCORE+WIN_SCORE       };
            case (B_PAPER)      : return { SCISSOR_SCORE+WIN_SCORE,  PAPER_SCORE+LOST_SCORE     };
            case (B_SCISSOR)    : return { SCISSOR_SCORE+LOST_SCORE, SCISSOR_SCORE+DRAW_SCORE   };
            default: CHECK_FAIL();
            }; break;
        }; break;

    default : CHECK_FAIL();
    }
}

char PrsGame::shouldPlay(char p1, char goal)
{
    switch (goal) {
        case SHOULD_DRAW : {
            switch(p1) {
                case(A_ROCK)    : return B_ROCK;
                case(A_PAPER)   : return B_PAPER;
                case(A_SCISSOR) : return B_SCISSOR;
            }
        };

        case SHOULD_WIN : {
            switch(p1) {
                case(A_ROCK)    : return B_PAPER;
                case(A_PAPER)   : return B_SCISSOR;
                case(A_SCISSOR) : return B_ROCK;
            }
        };

        case SHOULD_LOOSE: {
            switch(p1) {
                case(A_ROCK)    : return B_SCISSOR;
                case(A_PAPER)   : return B_ROCK;
                case(A_SCISSOR) : return B_PAPER;
            }
        };
    }
    return '?';
}
