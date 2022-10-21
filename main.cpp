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

int checkForWin(){
    int j;
    int i;
    int win = -1;
    int count;
    int totalPlays;
    
    // Obtain the rows and columns of the tik tac toe board
    int rows = sizeof board / sizeof board[0];
    int cols = sizeof board[0] / sizeof(char);

    // Checks all rows for wins
    for(j = 0; j < rows; ++j){
        
        // Checks if all values in a row are equal to each other 
        count = 0;
        for(i = 0; i < cols-1; i++){   

            //If they are return a win condition
            if((board[j][i]) == (board[j][i+1])){
                
                count++;

                if(count == cols-1){
                    win = 1;
                    return win;
                }
            }
            else{
                count = 0;
            }
        }
    }

    // Checks all cols for wins
    for(i = 0; i < cols; i++){
        count = 0;
        // Checks if all values in a column are equal to each other 
        for(j = 0; j < rows-1; j++){  
            //If they are return a win condition   
            if((board[j][i]) == (board[j+1][i])){
                
                count++;

                if(count == rows-1){
                    win = 1;
                    return win;
                }
            }
            else{
                count = 0;
            }
        }
    }
        
    // Check main diagonal
    count = 0;
    // Checks if all values are equal to each other 
    for(j = 0; j < rows-1; j++){  
        if((board[j][j]) == (board[j+1][j+1])){
            
            count++;

            if(count == rows-1){
                win = 1;
                return win;
            }
        }
        else{
            break;
        }
    }

    // Check other diagonal
    count = 0;
    for(j=0; j < rows-1; j++){

        if(board[j][cols-j-1] == board[j+1][cols-j-2]){
            count++;

            if(count == rows-1){
                win = 1;
                return win;
            }
        }
        else{
            count = 0;
        }
    }

   
    return -1;
}



int main(){
    char player1;
    char player2;


    int move;
    int player = 1;
    int x = -1;
    int turn = 0;

    char mark;

    cout << "Player 1: Would you like to be \'X\' or \'O\')? ";
    cin >> player1;

    if(!((player1 == 'X') || (player1 == '0'))){
        cout << "Please input only \'X' or \'O'" << endl;
        cin.ignore(); 
        cin >> player1;

        if(!((player1 == 'X') || (player1 == '0'))){
            cout << "Invalid input. Player 1 has been assigned to play X." << endl;
            player1 = 'X';
        }
        
    }
    
    if(player1 == 'O'){
        player1 = 'O';
        player2 = 'X';
    }
    else if (player1 == 'X'){
        player1 = 'X';
        player2 = 'O';
    }
    
    // Obtain the size of the tik tac toe board
    int rows = sizeof board / sizeof board[0];
    int cols = sizeof board[0] / sizeof(char);
    
    cout << "Given the layout below, select the number of which box you would like to place your mark into." << endl;
    
    //Create turns until someone wins or the game is tied
    do{
    printBoard();

    //If it is an odd number turn (i.e. the 3rd, 7th or 389th turn) it is Player 1's turn, other it is Player 2's turn    
    player=(player%2)?1:2;

    cout << "\nPlayer " << player << ", enter your move: ";
    cin >> move;

    // Determine index values for given input
    int col_index = (move - 1)%rows;
    int row_index = floor((move - 1)/rows);
 
    if( (board[row_index][col_index] != 'X')  && (board[row_index][col_index] != 'O')){
    
    // If it is Player 1's turn indicate the move with Player 1's mark (i.e. X or O)
    mark=(player==1) ? player1 : player2;
    board[row_index][col_index] = mark;


    x = checkForWin(); 

    //Switch whose turn it is
    player++; 
    turn++;

    //Check for a tie! (If it is the last turn and someone hasn't won yet)
    if((x!= 1) && (turn == rows*cols)){
        x = 0;
    }
    }

    else{
        cout << "Invalid move. Already a used location or invalid digit. Please try again: " << endl; 
        
        cin.ignore(); 
        cin.get(); 


    }       
   }
   while(x == -1);
   


   //Someone haw won
   if(x == 1){
    
    printBoard();
    cout << "\nGame over! Player " << --player << " wins!" << endl;
   }

    //The game was tied
   if(x == 0){
    printBoard();
    cout << "\nCongratulations! You tied!" << endl;

   }



    return 0;
}