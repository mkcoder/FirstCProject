/*
* TODO:	
* 1. Fix up the move piece logical setup,
* 2. Redo the logical moves
*/

int YAxisToInt(char y);

#include <stdio.h>
#include <stdlib.h>
#include "Board/board.h"
#include "Player/player.h"

bool checkForErrorWhenUserMovingPiece(int x,int y,int oldX,int oldY,char currentPlayerSymbol,char otherPlayerSymbol)
{
	char oldPiece = XYToBoardPiece(oldX, oldY);
	char newPiece = XYToBoardPiece(x,y);
	int error = 0;	
	if (!checkIfMoveIsPossible(oldX, oldY))
	{
		error++;
		printf("Theres is an error in the second input\n");
	}

	if (!checkIfMoveIsPossible(x,y))
	{
		error++;
		printf("There is an error in the first input\n");
	}

	if (oldPiece == otherPlayerSymbol)
	{
		error++;
		printf("The first move is trying to move the other player\n");
	}
	
	if (oldPiece == '.')
	{
		error++;
		printf("The first input is trying to move a '.'\n");
	}

	if (newPiece == otherPlayerSymbol)
	{
		error++;
		printf("The second input is trying to move a piece on top of its self\n");
	}
	
	if (newPiece == currentPlayerSymbol)
	{
		error++;
		printf("The second input is trying to move its piece on top the other player\n");
	}

	if (error == 0)
	{
		return false;
	}

	return true;
}

bool checkForErrorWhenUserRemovingPiece(int x,int y,char currentPlayerSymbol)
{

	int error = 0;
	char piece = XYToBoardPiece(x,y);
	
	if (!checkIfMoveIsPossible(x,y))
	{
		error++;
		printf("Sorry that move is not possible\n");
	}

	if (piece == '.')
	{
		error++;
		printf("You are trying to remove '.' from the board\n");
	}

	if (piece == currentPlayerSymbol)
	{
		error++;
		printf("You are trying to remove your self from the board\n");
	}


	if (error == 0)
	{
		return false;	
	}
	return true;
}

bool checkForErrorWhenUserPlacingPiece(int x,int y,char currentPlayerSymbol, char otherPlayerSymbol)
{
	int error = 0;
	char piece = XYToBoardPiece(x,y);

	if (!checkIfMoveIsPossible(x,y))
	{
		error++;
		printf("Sorry that move is not possible\n");
	}
	if (piece == currentPlayerSymbol)
	{
		error++;
		printf("You are trying to place a piece on top of your self\n");
	}
	if (piece == otherPlayerSymbol)
	{
		error++;
		printf("You are trying to place a piece on top of the other player\n");
	}

	if (error == 0)
	{
		return false;
	}
	return true;
}
void flush()
{
	int ch;
	// need for UNIX system.
	while((ch == getchar()) && ch != EOF);
	// needed for Windows System.
	fflush(stdin);
}

int main(int argc, char* argv) {
	
	// Setup player values
	struct Player player1;
	player1.playerMovesLeft = 9;
	player1.playerName = "Player 1";
	player1.playerPieceSymbol = 'X';
	
	struct Player player2;
	player2.playerMovesLeft = 9;
	player2.playerName = "Player 2";
	player2.playerPieceSymbol = 'O';

	// Setup loop values
	int winner = 0, // no
		counter = 0; // count the moves done
	while (winner != 1) {		
		// INIT ALL VARIABLES
		int x;
		int y;
		char charY;

		// Draw Boards and player turns
		drawBoard();
		drawPlayerTurns(player1);
		drawPlayerTurns(player2);

		/************************************************************
		*					Player 1's Turn 						*
		*															*
		************************************************************/
		// Turns
		if (counter % 2 == 0) // Then it is player1's turn
		{	

			if (player1.playerMovesLeft == 0)
			{
				printf("\n\n\bAll piece have been placed on the board you can now move them\n\n");
			}
			/**********************************************************
			*					Phase one: placing pieces				*
			*															*
			***********************************************************/
			if ( player1.playerMovesLeft > 0 ) 
			{

				// Getting player moves
				printf("Where would %c like to move: ", player1.playerPieceSymbol);
				scanf("%c%d", &charY, &x);

				y = YAxisToInt(charY);
				
				while ( checkForErrorWhenUserPlacingPiece(x,y,player1.playerPieceSymbol,player2.playerPieceSymbol) )
				{			
					drawBoard();		
					flush(stdin);

					printf("Where would %c like to move: ", player1.playerPieceSymbol);
					scanf("%c%d", &charY, &x);
					y = YAxisToInt(charY);

				}/**/
				// This places the symbol on the board
				PlaceSymbolOnBoard(x,y,player1.playerPieceSymbol);
			} 
			/***********************************************************
			*					Phase two: moving pieces			   *
			*														   *
			***********************************************************/
			else 
			{
				int oldX; x;
				char oldY; char newY;

				// get user input
				// Getting player moves
				printf("Where would %c like to move: ", player1.playerPieceSymbol);
				scanf("%c%d %c%d", &oldY, &oldX, &newY, &x);
				
				// convert the user input
				int oldY2 = YAxisToInt(oldY);
				int y = YAxisToInt(newY);		
				// check userinput
				int errorCounter = 0;
				/**/while ( checkForErrorWhenUserMovingPiece(x,y,oldX,oldY2,
					player1.playerPieceSymbol, player2.playerPieceSymbol))
				{		

					drawBoard();
					flush(stdin);

					printf("Sorry, you can't move there please try again!: ");
					scanf("%c%d %c%d", &oldY, &oldX, &newY, &x);
				
					// convert the user input
					oldY2 = YAxisToInt(oldY);
					y = YAxisToInt(newY);	

				}/**/	


				// delete piece
				RemoveSymbolFromBoard(oldX, oldY2);
				// move piece
				PlaceSymbolOnBoard(x, y, player1.playerPieceSymbol);
			}

			// continue on playing
			counter++;
			player1.playerMovesLeft--;

			/************************************************************
			*					Checks for winner						*
			*															*
			*************************************************************/
			if ( checkIfUserWon(player1) )
			{
				drawBoard();
				flush(stdin);
				// Get user input
				// Getting player moves
				printf("What piece would %s like to remove from play: ", player1.playerName);
				scanf("%c%d", &charY, &x);
				y = YAxisToInt(charY);					
				int errorCounter = 0;
				// while loop until the move is correct				
				/**/while (checkForErrorWhenUserRemovingPiece(x,y,player1.playerPieceSymbol))
				{
					drawBoard();
					flush(stdin);		

					printf("What piece would %s like to remove from play: ", player1.playerName);
					scanf("%c%d", &charY, &x);
					y = YAxisToInt(charY);

					
				}/**/
				// remove the piece
				RemoveSymbolFromBoard(x,y);
				// check if the new location, is a winning piece
			/************************************************************
			*					Phase three: "flying"    				*
			*															*
		    *************************************************************/
				if ( checkIfUserHasOnly3PiecesLeft(player2.playerPieceSymbol)) {
					printf("Congrats! %s You Won\n", player1.playerName);
					winner = 1;
				}
			} // End of the check if user won if statement
		}
			/**********************************************************
			*					Player 2's Turn 						*
			*															*
			***********************************************************/
		else 
		{ // player2's turn
			if (player2.playerMovesLeft == 0)
			{
				printf("\n\n\bAll piece have been placed on the board you can now move them\n");
			}


			/**********************************************************
			*					Phase one: placing pieces				*
			*															*
			***********************************************************/

			// check and get user input
			if ( player2.playerMovesLeft > 0 ) 
			{

				
				// Getting player moves
				printf("Where would %c like to move: ", player2.playerPieceSymbol);
				scanf("%c%d", &charY, &x);
				y = YAxisToInt(charY);
				while ( checkForErrorWhenUserPlacingPiece(x,y,player2.playerPieceSymbol,player1.playerPieceSymbol) )
				{
					drawBoard();
					flush(stdin);
					printf("You made a mistake try again\n");					
					printf("Where would %c like to move: ", player2.playerPieceSymbol);
					scanf("%c%d", &charY, &x);
					y = YAxisToInt(charY);

				}/**/

				// This places the symbol on the board
				PlaceSymbolOnBoard(x,y,player2.playerPieceSymbol);

			} 
			/************************************************************
			*					Phase two: moving pieces				*
			*															*
			*************************************************************/			
			else 
			{ 
				int oldX; x;
				char oldY; char newY;

				// get user input
				// Getting player moves
				printf("Where would %c like to move: ", player2.playerPieceSymbol);
				scanf("%c%d %c%d", &oldY, &oldX, &newY, &x);
				
				// convert the user input
				int oldY2 = YAxisToInt(oldY);
				int y = YAxisToInt(newY);
				// check userinput			
				/**/while ( checkForErrorWhenUserMovingPiece(x,y,oldX,oldY2,
						player2.playerPieceSymbol, player1.playerPieceSymbol) )
				{	
					drawBoard();
					flush(stdin);

					printf("Where would %c like to move: ", player2.playerPieceSymbol);
					scanf("%c%d %c%d", &oldY, &oldX, &newY, &x);
					
					// convert the user input
					oldY2 = YAxisToInt(oldY);
					y = YAxisToInt(newY);
					
				}/**/
				// delete piece
				RemoveSymbolFromBoard(oldX, oldY2);
				// move piece
				PlaceSymbolOnBoard(x, y, player2.playerPieceSymbol);
			}
			// keeps the game moving
			counter++;
			player2.playerMovesLeft--;

			/**********************************************************
			*					Check for winner         				*
			*															*
			***********************************************************/
			if ( checkIfUserWon(player2) )
			{
				drawBoard();
				flush(stdin);

				// Get user input
				printf("What piece would you like to remove from play: ");
				scanf("%c%d", &charY, &x);
				y = YAxisToInt(charY);
				// check user input 
				// -> while user input is false keep getting user input
				while (checkForErrorWhenUserRemovingPiece(x,y,player2.playerPieceSymbol))
				{
					drawBoard();
					flush(stdin);

					printf("What piece would %s like to remove from play: ", player2.playerName);
					scanf("%c%d", &charY, &x);
					y = YAxisToInt(charY);

				}
				// Remove piece from board
				RemoveSymbolFromBoard(x,y);
				// Getting player moves

			/**********************************************************
			*					Phase three: "flying"    				*
			*															*
			***********************************************************/
				/**/if ( checkIfUserHasOnly3PiecesLeft(player1.playerPieceSymbol) ) {
					printf("Congrats! %s You Won\n", player2.playerName);
					winner = 1;
				}/**/
			}
		} // end of the if/else
		flush(stdin);
	} // End of the while loop
}