#include <iostream>
#include <stdlib.h>
#include <cmath>

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

        // Create horizontal lines between each row
        if(j < rows-1){
            cout << "-";
            for(int k = 0; k < cols; k++){
                cout << "---";
            }
            cout << "-" << endl;
        }
    }
}

void checkForWin(){
    int j;
    int i;
    bool win = false;
    
    // Obtain the rows and columns of the tik tac toe board
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
    char player1;
    char player2;


    int move;
    int player = 1;
    int i = 1;

    char mark;

    /*cout << "Would you like to be \'X\' or \'O\')? ";
    cin >> player1;

    if(player1 == 'X'){
        player2 = 'O';
    }
    else if(player1 == 'O'){
        player2 = 'X';
    }
    else{
        cout << "Please input only \'X' or \'O'" << endl;
    }*/
    
    // Obtain the size of the tik tac toe board1
    int rows = sizeof board / sizeof board[0];
    int cols = sizeof board[0] / sizeof(char);
    
    cout << "Given the layout below, select the number of which box you would like to place your mark into." << endl;
    
    do{
    printBoard();
        
    player=(player%2)?1:2;

    cout << "Player " << player << ", enter your move: ";
    
    cin >> move;

    // Determine index values for given input
    int col_index = (move - 1)%rows;
    int row_index = floor((move - 1)/rows);

    
    
    if( (board[row_index][col_index] != 'X')  && (board[row_index][col_index] != 'O')){
    
    // If it is Player 1's turn indicate the move with Player 1's mark (i.e. X or O)
    mark=(player==1) ? player1 : player2;
    board[row_index][col_index] = mark;


//    i = checkForWin(); 

    //Switch whose turn it is
    player++;


    

    }

    else
    {
        cout << "Invalid move. Already a used location or invalid digit" << endl; 
        
        cin.ignore(); 
        cin.get(); 
    }


        
   }
   while(i == -1);
   



    /*
    cin >> move;


    
    cout << "Make your move ";
    cin >> move;

    checkForWin();
    
    printBoard();
    */


    return 0;
}