
// Dice game application

// more dice more decisions  = harder!  Challenge Yourself!!
// class for dice game
// create another class for Example:
// player class - scorecard class
// at least one additional class
// player has name, high score, et cetera
// due on march 2nd
// what objects are in the game?
/*
                ^^^^^^^^^^ Slam Game Rules ^^^^^^^^^^
                            Provided by:
                www.tactic.net/site/rules/UK/02480.pdf

A game where the object is to end up with a loser, rather than a winner. For 2–8 players.
You will also need paper and pencil.
Aim of the game: To leave the game and scoring 15 points as soon as possible, by
rolling a predetermined number.
How to play: Decide who starts. That player rolls one die to decide the slam in the
game, ie. the number everyone will try to roll.
The turn order proceeds clockwise. Every time it is your turn, you roll all three dice
and keep on re-rolling for as long as you roll at least one slam. For every slam, you score
1 point. As soon as you make a roll without any die showing a slam, your turn is over.
Example: The 3 is the slam. In your first roll you get one 3, and score 1 point. You
roll again, get a 3 once again, and score another point. Once again you roll, but this time
no 3 shows. Pass the dice to the next player – but at least you scored 2 points in your
turn.
If two dice both show slam, this is called a small slam and scores 5 points. Note that
you must score 15 points exactly to get out of the game; if you already have 14 points
and roll a small slam, your throw is not valid and your turn is over.
If all three dice show slam, this is called a grand slam and immediately gives you a
score of 15 points (regardless of what you had before then). The last player left in the
game is the loser.
*/
#include <iostream>
#include <time.h>
#include <stdlib.h>
// Using 2 player model because of time constraints
//
class Die   // Die class
{
private:
    int num;
public:
    Die(); // default constructor
    void roll(); // function to roll
    int getNum(); // function to get the number
};
Die::Die()
{
    num = 1;
    srand((unsigned)time(NULL));
}
void Die::roll()
{
    num = rand() % 6 + 1;
}
int Die::getNum()
{
    return num;
}
class Player    // Player class
{
private:
    int score;
public:
    Player();   // default constructor
    void setScore(int newScore);    // Function to set player score
    int getScore();     // Function to get player score
};
Player::Player()
{

}
void Player::setScore(int newScore)
{
    score = newScore;
}
int Player::getScore()
{
    return score;
}

using namespace std;

int main()
{
    Die dice1;
    Die dice2;
    Die dice3;
    Die diceTarget;
    Player p1;
    int score1 = 0;
    Player p2;
    int score2 = 0;
    diceTarget.roll();
    int slam = diceTarget.getNum();
    cout <<"\nThe target number is: " << slam << endl;  // the target number determines how a player scores
    const int winState = 15;
do  // loop until winner achieved
{


    do  // loop for player 1 turn, rolling die and setting score
    {
        cout << "Player one roll :" << endl;
        dice1.roll();
        dice2.roll();
        dice3.roll();
        cout <<"You rolled " << endl;
        cout << dice1.getNum() << " _ "
        << dice2.getNum() << " _ " << dice3.getNum() << endl;
            if (dice1.getNum() == slam  || dice2.getNum() == slam || dice3.getNum() == slam)
            {
                if (p1.getScore() == winState)
                {
                    cout << "Player 1 wins!";
                    exit (0);
                }
                score1++;
                p1.setScore(score1);
                cout << "Your score is: " << p1.getScore() << endl;
            }
    }while(dice1.getNum() == slam  || dice2.getNum() == slam || dice3.getNum() == slam);

    do  // player 2 turn
    {
        cout << "Player two roll :" << endl;
        dice1.roll();
        dice2.roll();
        dice3.roll();
        cout <<"You rolled " << endl;
        cout << dice1.getNum() << " _ "
        << dice2.getNum() << " _ " << dice3.getNum() << endl;
            if (dice1.getNum() == slam  || dice2.getNum() == slam || dice3.getNum() == slam)
            {
                if (p2.getScore() == winState)
                {
                    cout << "Player 2 wins!";
                    exit (0);
                }
                score2++;
                p2.setScore(score2);
                cout << "Your score is: " << p2.getScore() << endl;
            }
    }while(dice1.getNum() == slam  || dice2.getNum() == slam || dice3.getNum() == slam);
    if (p1.getScore() == 15)
        cout << "Player 1 wins!" << endl;   // when winState achieved a player wins
    if (p2.getScore() == 15)
        cout << "Player 2 wins!" << endl;
}while(p1.getScore() < 15 || (p2.getScore() < 15));
    return 0;
}
