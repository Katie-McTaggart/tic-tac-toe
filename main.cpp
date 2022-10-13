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

        if(j < rows-1){
            cout << "----------" << endl;
        }
    }
}

void checkForWin(){
    int j;
    int i;
    bool win = false;
    
    // Obtain the size of the tik tac toe board
    int rows = sizeof board / sizeof board[0];
    int cols = sizeof board[0] / sizeof(char);

    // Checks all rows for wins
    for(j = 0; j < rows; j++){
        // Checks if all values in a row are equal to each other 
        for(i = 0; i < cols-1; i++){        
            if(board[j][i] != board[j][i+1]){
                win = false;
                break;
            }
            else{
                win = true;
            }
        }
    }

    // Checks all cols for wins
    for(i = 0; i < cols; i++){
        // Checks if all values in a row are equal to each other 
        for(j = 0; j < rows-1; j++){        
            if(board[j][i] != board[j][i+1]){
                win = false;
                break;
            }
            else{
                win = true;
            }
        }
    }
        
    // Check main diagonal
    for(j=0; j < rows-1; j++){
        if(board[j][j] != board[j+1][j+1]){
            win = false;
            break;
        }
        else{
            win = true;
        }

    }

    // Check other diagonal
    for(j=0; j < rows-1; j++){
        if(board[j][rows-1-j] != board[j+1][rows-j]){
            win = false;
            break;
        }
        else{
            win = true;
        }

    }

}



int main(){
    int boxSelection;
    char player1;
    char player2;
    int move;

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


    cout << "Make your move ";
    cin >> move;

    checkForWin();


    //createBoard();
    //cout << "Given the layout above, select the number of which box you would like to place your 'X' into: ";
    //cin >> boxSelection;
    
    
    printBoard();

    return 0;
}