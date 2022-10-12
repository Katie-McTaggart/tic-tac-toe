#include <iostream>
#include <stdlib.h>

using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7','8', '9'}};

void printBoard(){
    int j;
    int i;
    
    // Obtain the size of the tik tac toe board
    int rows = sizeof board / sizeof board[0];
    int cols = sizeof board[0] / sizeof(char);

    // Prints each row
    for(j = 0; j < rows; j++){
        cout << " "; 
        
        // Prints each item in a row
        for(i = 0; i < cols; i++){
            // Add a '|' between every row except the last one
            if(i == cols-1){
                cout << board[j][i] << endl;
            }
            else{
                cout << board[j][i] << " | " ;
            }
        }
    }
}



int main(){
    int boxSelection;
    char player1;
    char player2;

    cout << "Would you like to be \'X\' or \'O\')? ";
    cin >> player1;

    if(player1 == 'X'){
        player2 = 'O';
    }
    else if(player1 == 'O'){
        player2 = 'X';
    }
    else{
        cout << "Please input only \'X' or \'O'" << endl;
    }


    //createBoard();
    //cout << "Given the layout above, select the number of which box you would like to place your 'X' into: ";
    //cin >> boxSelection;
    
    
    printBoard();

    return 0;
}