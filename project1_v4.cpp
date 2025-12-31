#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    char playAgain;
    int gamesPlayed = 0;
    int totalAttempts = 0;
    int gamesWon = 0;
    int highScore = 0;
    int fastestTime = 999999;   // no climits used

    cout << endl;
    cout << " NUMBER GUESSING GAME v4.1 " << endl;
    cout << "   With Time Tracking!    " << endl;
    cout << endl;

    do {
        gamesPlayed++;

        int difficulty;
        int maxNumber, maxAttempts;

        cout << " Game " << gamesPlayed << endl;
        cout << " Choose difficulty:" << endl;
        cout << " 1. Easy   (1-50,  10 attempts)" << endl;
        cout << " 2. Medium (1-100, 7 attempts)" << endl;
        cout << " 3. Hard   (1-200, 5 attempts)" << endl;
        cout << endl;

        do {
            cout << "Enter choice (1-3): ";
            cin >> difficulty;

            if (difficulty < 1 || difficulty > 3) {
                cout << " Invalid! Please enter 1, 2, or 3." << endl;
            }
        } while (difficulty < 1 || difficulty > 3);

        if (difficulty == 1) {
            maxNumber = 50;
            maxAttempts = 10;
            cout << " EASY MODE ACTIVATED" << endl;
        } else if (difficulty == 2) {
            maxNumber = 100;
            maxAttempts = 7;
            cout << " MEDIUM MODE ACTIVATED" << endl;
        } else {
            maxNumber = 200;
            maxAttempts = 5;
            cout << " HARD MODE ACTIVATED" << endl;
        }

        time_t startTime = time(0);

        int secretNumber = rand() % maxNumber + 1;
        int guess;
        int attempts = 0;
        bool won = false;

        cout << endl;
        cout << " Target: Number between 1 and " << maxNumber << endl;
        cout << " Attempts allowed: " << maxAttempts << endl;
        cout << " Timer started!" << endl;
        cout << endl;

        while (attempts < maxAttempts) {
            cout << " Attempt " << (attempts + 1) << "/" << maxAttempts << endl;
            cout << " Your guess: ";
            cin >> guess;

            if (guess < 1 || guess > maxNumber) {
                cout << " Invalid! Enter a number between 1 and " << maxNumber << endl;
                continue;
            }

            attempts++;

            if (guess < secretNumber) {
                cout << " Too low!" << endl;

                int distance = secretNumber - guess;
                if (distance > 50)
                    cout << " Hint: Much higher!" << endl;
                else if (distance > 20)
                    cout << " Hint: Higher!" << endl;
                else if (distance > 10)
                    cout << " Hint: A bit higher!" << endl;
                else
                    cout << " Hint: Very close! Slightly higher!" << endl;
            }
            else if (guess > secretNumber) {
                cout << " Too high!" << endl;

                int distance = guess - secretNumber;
                if (distance > 50)
                    cout << " Hint: Much lower!" << endl;
                else if (distance > 20)
                    cout << " Hint: Lower!" << endl;
                else if (distance > 10)
                    cout << " Hint: A bit lower!" << endl;
                else
                    cout << " Hint: Very close! Slightly lower!" << endl;
            }
            else {
                time_t endTime = time(0);
                int timeTaken = endTime - startTime;

                cout << endl;
                cout << " WINNER! CORRECT! " << endl;
                cout << " The number was: " << secretNumber << endl;
                cout << " Attempts used: " << attempts << "/" << maxAttempts << endl;
                cout << " Time taken: " << timeTaken << " seconds" << endl;

                if (timeTaken < fastestTime) {
                    fastestTime = timeTaken;
                    cout << " NEW FASTEST TIME!" << endl;
                }

                int timeBonus = (timeTaken <= 30) ? 20 : 0;
                int score = (maxAttempts - attempts + 1) * 10 * difficulty + timeBonus;

                cout << " Score: " << score << " points!" << endl;

                if (timeBonus > 0)
                    cout << " (includes +20 speed bonus!)" << endl;

                if (score > highScore) {
                    highScore = score;
                    cout << " NEW HIGH SCORE!" << endl;
                }

                won = true;
                gamesWon++;
                totalAttempts += attempts;
                break;
            }

            if (attempts < maxAttempts) {
                cout << " Remaining attempts: " << (maxAttempts - attempts) << endl;
            }
            cout << endl;
        }

        if (!won) {
            time_t endTime = time(0);
            int timeTaken = endTime - startTime;

            cout << endl;
            cout << " GAME OVER " << endl;
            cout << " The number was: " << secretNumber << endl;
            cout << " Time taken: " << timeTaken << " seconds" << endl;
            cout << " Better luck next time!" << endl;
        }

        cout << endl;
        cout << "Play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << endl;
    cout << " FINAL STATISTICS " << endl;
    cout << " Games played: " << gamesPlayed << endl;
    cout << " Games won: " << gamesWon << endl;

    if (gamesPlayed > 0) {
        cout << " Win rate: " << (gamesWon * 100) / gamesPlayed << "%" << endl;
    }

    if (gamesWon > 0) {
        double average = (double)totalAttempts / gamesWon;
        cout << " Average attempts per win: " << average << endl;
    }

    cout << " High score: " << highScore << " points" << endl;

    if (fastestTime < 999999) {
        cout << " Fastest win: " << fastestTime << " seconds" << endl;
    }

    cout << endl;
    cout << "Thanks for playing! Goodbye!" << endl;

    return 0;
}
