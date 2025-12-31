#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
    srand(time(0));

    int gamesplayed = 0;
    int gameswon = 0;
    char playagain;
    int totalattempts = 0;

    cout << "================================" << endl;
    cout << "   NUMBER GUESSING GAME v3.0" << endl;
    cout << "    With Difficulty Levels!" << endl;
    cout << "================================" << endl;
    cout << endl;

    do{
        gamesplayed++;


        int difficulty;
        int maxnumber; int maxattempts;

        cout << "\n--- Game " << gamesplayed << " ---" << endl;
        cout << "Choose difficulty:" << endl;
        cout << "1. Easy   (1-50,  10 attempts)" << endl;
        cout << "2. Medium (1-100, 7 attempts)" << endl;
        cout << "3. Hard   (1-200, 5 attempts)" << endl;
        cout << "Enter choice (1-3): ";
        cin >> difficulty;


        if(difficulty == 1){
            maxnumber = 50;
            maxattempts = 10;
            cout << "Difficulty: EASY " << endl;
        }
        else if(difficulty == 2){
            maxnumber = 100;
            maxattempts = 7;
            cout << "Difficulty: MEDIUM " << endl;
        }
        else if(difficulty == 3){
            maxnumber = 200;
            maxattempts = 5;
            cout << "Difficulty: Hard " << endl;
        }
        else {
            cout << "Invalid Choice! Difficulty: MEDIUM " << endl;
            maxnumber = 100;
            maxattempts = 7;
            cout << "Difficulty: MEDIUM " << endl;
        }

        int secretnumber = rand() % maxnumber + 1;
        int guess;
        bool won = false;
        int attempts = 0;

        cout << "I am guessing of the no. between 1 to " << maxnumber << endl;
        cout << "You have " << maxattempts << " attempts" << endl;
        cout << endl;

        while(attempts < maxattempts){
            cout << "Attempts " << (attempts + 1) << "/" << maxattempts << " ---Enter Your Guess--- " << endl;
            cin >> guess;
            attempts++;
            cout << endl;

            if(guess < secretnumber){
                cout << "TOO! LOW" << endl;
            }
            else if(guess > secretnumber){
                cout << "TOO! HIGH" << endl;
            }
            else{
                cout << "CONGRATULATION! YOU WON" << endl;
                cout << "The number was " << secretnumber << endl; 
                cout << "You used " << attempts << " out of " << maxattempts << endl;

                int score = (maxattempts - attempts + 1) * 10;
                cout << "score: " << score << "points" << endl;

                gameswon++;
                won = true;
                totalattempts += attempts;
                break;
                }

                if(attempts < maxattempts){
                    cout << "Attempts remaining: " << (maxattempts - attempts) << endl;
                    cout << endl;
            }
        }

        if(!won){
            cout << endl;
            cout << "Game Over! You ran out of attempts." << endl;
            cout << "The no. was " << secretnumber << endl;
        }

        cout << endl;
        cout << "Play Again(Y/N)" << endl;
        cin >> playagain;

    }while( playagain == 'Y' || playagain == 'y');


    cout << endl;
    cout << "================================" << endl;
    cout << "      FINAL STATISTICS" << endl;
    cout << "================================" << endl;
    cout << "Games Played " << gamesplayed << endl;
    cout << "Games Won " << gameswon << endl;
    cout << "Win Rate " << (gameswon * 100) / gamesplayed << "%" << endl;

    if(gameswon > 0){
        double average = (double)totalattempts / gameswon;
        cout << "Average Games Per Win " << average << endl;        
    }

    cout << endl;
    cout << "------Thanks For Playing! GOODBYE-----";

    return 0;
}