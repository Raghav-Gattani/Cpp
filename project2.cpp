#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char GetUserChoice();
char GetComputerChoice();
void ShowChoices(char choice);
void ChooseWinner(char player, char computer);


int main(){

    char player;
    char computer;

    player = GetUserChoice();
    cout << "Your Choice: ";
    ShowChoices(player);

    computer = GetComputerChoice();
    cout << "Computer Choice: ";
    ShowChoices(computer);

    ChooseWinner(player, computer);
    

    return 0;
}

char GetUserChoice(){

    char player;
    cout << "||ROCK-PAPER-SCISSOR GAME||" << endl;

    do{
        cout << "Enter the PLayer's Choice " << endl;
        cout << "****************************" << endl;
        cout << "'r' for ROCK" << endl;
        cout << "'p' for PAPER" << endl;
        cout << "'s' for SCISSOR" << endl;
        cin >> player;

    }while(player != 'r' && player != 'p' && player != 's');

    return player;
}
char GetComputerChoice(){

    srand(time(0));
    int num = rand() % 3 + 1;

    switch(num){
        case 1: return 'r';
        case 2: return 'p';
        case 3: return 's';
    }

    return 0;
}
void ShowChoices(char choice){
    switch(choice){
        case 'r': cout << "ROCK" << endl;
        break;
        case 'p': cout << "PAPER" << endl;
        break;
        case 's': cout << "SCISSOR" << endl;
        break;
    }

    
}
void ChooseWinner(char player, char computer){

    switch(player){
        case 'r': if(computer = 'r'){
                    cout << "It's a TIE" << endl;
                  }
                  else if (computer = 'p'){
                    cout << "You LOOSE!" << endl; 
                  }
                  else {
                    cout << "You WON!" << endl;
                  }
                  break;
        case 'p': if(computer = 'r'){
                    cout << "You WON!" << endl;
                  }
                  else if (computer = 'p'){
                    cout << "It's a TIE" << endl; 
                  }
                  else {
                    cout << "You LOOSE!" << endl;
                  }
                  break;
        case 's': if(computer = 'r'){
                    cout << "You LOOSE!" << endl;
                  }
                  else if (computer = 'p'){
                    cout << "You WON!" << endl; 
                  }
                  else {
                    cout << "It's a TIE" << endl;
                  }
                  break;
    }


}
