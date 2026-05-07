#include <iostream>
#include <ctime>
using namespace std;

void drawboard( char *spaces);
void Playermove(char *spaces, char player);
void Computermove(char *spaces, char computer);
bool CheckWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main(){

    char spaces[] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawboard(spaces);

    while(running){
    Playermove(spaces, player);
    drawboard(spaces);
    if(CheckWinner(spaces, player, computer)){
        running = false;
        break;
    }
    else if(checkTie(spaces)){
        running = false;
        break;
    }

    Computermove(spaces, computer);
    drawboard(spaces);
    if(CheckWinner(spaces, player, computer)){
        running = false;
        break;
    }
    else if(checkTie(spaces)){
        running = false;
        break;
    }
    }

    cout << "Thanks For Playing" << endl;
    return 0;
}

void drawboard(char *spaces){
    cout << endl;

    cout << "     |     |     " << '\n';
    cout << "   " << spaces[0] <<" |   " << spaces[1] << " |   " << spaces[2] << "  " << '\n';
    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';
    cout << "   " << spaces[3] <<" |   " << spaces[4] << " |   " << spaces[5] << "  " << '\n';
    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';
    cout << "   " << spaces[6] <<" |   " << spaces[7] << " |   " << spaces[8] << "  " << '\n';
    cout << "     |     |     " << '\n';

    cout << endl;
}
void Playermove(char *spaces, char player){

    int number;
    do{
        cout << "Enter a Number Between (0-8): ";
        cin >> number;
          number--;

        if(spaces[number] == ' '){
        spaces[number] = player;
        break;
    }

    }while(number < 0 || number > 8);

    

}
void Computermove(char *spaces, char computer){

    int number;
    srand(time(0));

    while(true){
        number = rand() % 9;
        if(spaces[number] == ' '){
            spaces[number] = computer;
            break;
        }
    }
    

}
bool CheckWinner(char *spaces, char player, char computer){

    if(spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2]){
        spaces[0] == player ? cout << "You Win\n" : cout << "You Loose\n";
    }
    else if(spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5]){
        spaces[3] == player ? cout << "You Win\n" : cout << "You Loose\n";
    }
    else if(spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8]){
        spaces[6] == player ? cout << "You Win\n" : cout << "You Loose\n";
    }
    else if(spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6]){
        spaces[0] == player ? cout << "You Win\n" : cout << "You Loose\n";
    }
    else if(spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7]){
        spaces[1] == player ? cout << "You Win\n" : cout << "You Loose\n";
    }
    else if(spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8]){
        spaces[2] == player ? cout << "You Win\n" : cout << "You Loose\n";
    }
    else if(spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8]){
        spaces[0] == player ? cout << "You Win\n" : cout << "You Loose\n";
    }
    else if(spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6]){
        spaces[2] == player ? cout << "You Win\n" : cout << "You Loose\n";
    }
    else{
        return false;
    }
    
    return true;
}
bool checkTie(char *spaces){

    for( int i = 0; i < 9; i++){
        if(spaces[i] == ' '){
            return false;
        }
    }

    cout << "IT's a TIE" << endl;
    return true;
}
