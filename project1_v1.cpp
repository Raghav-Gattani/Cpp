#include<iostream>
#include<cstdlib>   // for rand() and srand()
#include<ctime>    //for time
using namespace std;

int main(){

    srand(time(0));

    // generate a random no. between 1 to 100
    int secretnumber = rand() % 100 + 1;
    int guess;
    int chance = 0;


    cout << "================================" << endl;
    cout << "   NUMBER GUESSING GAME v1.0" << endl;
    cout << "================================" << endl;
    cout << "I'm thinking of a number between 1 and 100" << endl;
    cout << endl;
    
    //Game loop
    while(true){
        cout << "Enter your guess : ";
        cin >> guess;
        chance++;

        if(guess < secretnumber){
            cout << "Low! Try Again." << endl;
        }

        else if(guess > secretnumber){
            cout << "High! Try Again." << endl;
        }

        else{
            cout << endl;
            cout << "Congratulation! You Got it." << endl;
            cout << "The no. was: " << secretnumber << endl;
            cout << "It Took You: " << chance << " chances." << endl;
            break;   //Exits the loop

        }

    }
    return 0;
}