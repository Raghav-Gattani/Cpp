#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
    srand(time(0));
    
    char playagain;
    int gamesplayed = 0;
    int totalattempts = 0;
    
    cout << "================================" << endl;
    cout << "   NUMBER GUESSING GAME v2.0" << endl;
    cout << "================================" << endl;
    cout << endl;
    
    
    do {
        gamesplayed++;
        
        int secretNumber = rand() % 100 + 1;
        int guess;
        int attempts = 0;
        
        cout << "\n--- Game " << gamesplayed << " ---" << endl;
        cout << "I'm thinking of a number between 1 and 100" << endl;
        cout << endl;
        
        
        while (true) {
            cout << "Enter your guess: ";
            cin >> guess;
            attempts++;
            
            if (guess < secretNumber) {
                cout << " Too low! Try again." << endl;
            } 
            else if (guess > secretNumber) {
                cout << " Too high! Try again." << endl;
            } 

            else{
                cout << endl;
                cout << " Congratulations! You got it!" << endl;
                cout << "The number was: " << secretNumber << endl;
                cout << "Attempts this game" << attempts << endl;
                totalattempts += attempts;
                break;
            }
        }

        cout << endl;
        cout << "PlayAgain (Y/N)" << endl;
        cin >> playagain;
    } while( playagain == 'Y' || playagain == 'y' );

     cout << endl;
    cout << "================================" << endl;
    cout << "      GAME STATISTICS" << endl;
    cout << "================================" << endl;
    cout << "Games Played: " << gamesplayed << endl;
    cout << "Total Attempts: " << totalattempts << endl;

    if ( gamesplayed > 0){
        double average =  double(totalattempts) / gamesplayed;
        cout << "Average Per Game: " << average << endl;
    }

     cout << endl;
    cout << "Thanks for playing! Goodbye! 👋" << endl;
    
    return 0;
}