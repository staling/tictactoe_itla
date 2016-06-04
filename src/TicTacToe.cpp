#include "TicTacToe.h"
#include <cstdlib>
using namespace std;

char board[3][3]; //Possible values are X, O and _ (for blank positions)
char player = 'X';

bool isAvailable(int row, int column)
{
	//TODO: Implement this code so that it tells the user whether or not he can play in the selected cell
	if(board[row -1][column - 1] == '_'){
		return true;
	}
	else{
		return false;
	}
	return true;
}

//Give initial values to the board matrix
void init()
{
	for(int i = 0 ; i < 3 ; i++)
	{
		for(int j = 0 ; j < 3 ; j++)
		{
			board[i][j] = '_';
		}
	}
}

void clearScreen()
{
	#ifdef _WIN32
	system("cls");
	#else
	system("clear");
	#endif
}

bool validate(int number)
{
	if(number >= 1 && number <= 3)
	{
		return true;
	}else
	{
		cout << "Please pick a value between 1 and 3" << endl;
		return  false;
	}
}

bool gameover()
{
	//TODO: Implement this method,verify if any player has won the match of it's being a tie.
	//Return true if the game is over. Print message informing the user about what just happened.

	char jugada = Cuadro[0][0];
     for(int i =0 ; i < 3; i++){
             for(int j = 0 ; j < 3 ; j++){
                     if(Cuadro[i][j] == '_'){
                          break; break;
                     }
                     if(jugada != Cuadro[i][j]){
                          break; break;

                     }
                     jugada = Cuadro[i][j];
                     if(j == 2){
                          printf("the best %c", jugada);
                          return true;
                     }
              }

     }



     jugada = Cuadro[0][0];
     for(int i =0 ; i < 3; i++){
             for(int j = 0 ; j < 3 ; j++){
                     if(Cuadro[j][i] == '_'){
                          break; break;
                     }
                     if(jugada != Cuadro[j][i]){
                          break; break;

                     }
                     jugada = Cuadro[j][i];
                     if(j == 2){
                          printf("the best %c", jugada);
                          return true;
                     }
              }

     }

     jugada = Cuadro[0][0];
     for(int i = 0 ; i < 3; i++){
           if(Cuadro[i][i] == '_'){
                 break;
             }
             if(jugada != Cuadro[i][i]){
                   break;

             }
             jugada = Cuadro[i][i];
             if(i == 2){
                    printf("the best %c", jugada);
                    return true;
             }

     }

     jugada = Cuadro[0][2];
     for(int i = 2 ; i >= 0; i--){
           if(Cuadro[2-i][i] == '_'){
                 break;
             }
             if(jugada != Cuadro[2-i][i]){
                   break;

             }
             jugada = Cuadro[2-i][i];
             if(i == 0){
                    printf("the best %c", jugada);
                    return true;
             }

     }

	cout << "You loose" << endl;
	return false;
}

bool isValidInput(istream& in){
	if(in.fail())
	{
		cout <<"Only numbers are accepted" << endl;
	    in.clear();
	    in.ignore(numeric_limits<streamsize>::max(), '\n'); //skip bad input
	    return false;
	}else
	{
		return true;
	}
}

void showBoard()
{
	while(!gameover())
	{
		clearScreen();
		int row = 0;
		int column = 0;

		cout << "It's " << player << "'s turn" << endl;
		//printing column numbers
		cout << "\t";
		for(int i = 0 ; i < 3 ; i++)
		{
			cout << i + 1 << "\t";
		}
		cout << endl;

		for(int i = 0 ; i < 3 ; i++)
		{
			cout << i + 1 << "\t";
			for(int j = 0 ; j < 3 ; j++)
			{
				cout << board[i][j] << "\t";
			}
			cout << endl;
		}
		do
		{
			cout << "In what row would you like to play? =>";
			cin >> row;
		}while(!isValidInput(cin) && !validate(row));
		do
		{
			cout << "In what column would you like to play? => ";
			cin >> column;
		}while(!isValidInput(cin) && !validate(column));

		if(isAvailable(row,column))
		{
			board[row - 1][column - 1] = player;
			player = player == 'X' ? 'O' : 'X';
		}else
		{
			cout << "The cell " << row << " , " << column << " is not available" << endl;
		}
	}
}
