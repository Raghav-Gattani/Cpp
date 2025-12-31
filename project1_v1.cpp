#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){

    srand(time(0));


    int secretnumber = rand() % 100 + 1;
    int guess;
    int chance = 0;


    cout << "================================" << endl;
    cout << "   NUMBER GUESSING GAME v1.0" << endl;
    cout << "================================" << endl;
    cout << "I'm thinking of a number between 1 and 100" << endl;
    cout << endl;

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
            break;

        }

    }
    return 0;
}