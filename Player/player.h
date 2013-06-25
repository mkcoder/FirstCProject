#include <stdbool.h>

// these are function definition
bool checkIfNoUserOwnPosition(char*, char*);
bool checkIfMoveIsPossible(int, int);


/*
* This is the player class and holds the information for each player.
*/
struct Player {

	// What is the name of the player
	char* playerName;

	// This stores the moves of each player, comma seperated
	char playerMoves[255]; // pos21,pos22,pos23....n

	// This keeps track of each players score
	int playerScore;

	// Player moves left
	signed int playerMovesLeft;

	// this stores the symbol of each player, for example X or O or Y what ever
	char playerPieceSymbol;

};




/*
	This isthe constructor for the class, and is executed everything

*/
void playerMove(int x, int y, struct Player player) 
{
	if ( checkIfMoveIsPossible(x, y) ) // Purposed move is possible
	{
		char currentBoardPiece = XYToBoardPiece(x,y);
		printf("Current piece on x=%d and y=%d is %c\n Current %s moves: %s", x,y,currentBoardPiece, 
			player.playerName,player.playerMoves);
	} else {
		printf("Sorry x=%d and y=%d is not possible, please go again!\n", x,y);
	}
}


/*
	This ckecks if the purposed x and y direction is possible, IE is (x,y) on the playable grid
*/
bool checkIfMoveIsPossible(int purposedRow, int purposedCol) 
{
	if (purposedRow == 1)
	{
		if (purposedCol == 1 || purposedCol == 4 || purposedCol == 7) 
		{
			return true;
		}
	}
	else if (purposedRow == 2)
	{
		if ( purposedCol == 2 || purposedCol == 4 || purposedCol == 6 ) 
		{
			return true;
		}
	}
	else if (purposedRow == 3)
	{
		if ( purposedCol == 3 || purposedCol == 4 || purposedCol == 5 ) 
		{
			return true;
		}
	}
	else if (purposedRow == 4)
	{
		if ( purposedCol == 1 || purposedCol == 2 || purposedCol == 3 || purposedCol == 5 || purposedCol == 6 || purposedCol == 7) {
			return true;
		}
	}
	else if (purposedRow == 5)
	{
		if ( purposedCol == 3 || purposedCol == 4 || purposedCol == 5 ) {
			return true;
		}
	}
	else if (purposedRow == 6)
	{
		if ( purposedCol == 2 || purposedCol == 4 || purposedCol == 6 ) {
			return true;
		}
	}
	else if (purposedRow == 7)
	{
		if (purposedCol == 1 || purposedCol == 4 || purposedCol == 7) {
			return true;
		}
	}
	return false;
}


/*
	Draws the moves left of the players
*/
void drawPlayerTurns(struct Player player) {	
	printf("%s: ", player.playerName);
	for (int i = 0; i < player.playerMovesLeft; ++i)
	{
		putchar(player.playerPieceSymbol);
	}

	putchar('\n');
}

/*
	This methods checks if the given user only has three pieces on the board left
*/
bool checkIfUserHasOnly3PiecesLeft(char playerPieceSymbol)
{
	int playerPieceCount = 0;
	for (int i = 1; i < 8; ++i)
	{
		for (int j = 1; j < 8; ++j)
		{
			if ( XYToBoardPiece(j, i) == playerPieceSymbol ) {
				playerPieceCount++;
			}
		}
	}

	if (playerPieceCount == 3)
	{
		return true;
	}
	return false;
}

/*
	This is a brute force way of solving the solution to it. Please see handout 1.1 Example 2 Page 9 Diagram 102 Algorithm of analysis of structure, 2 paragraph
*/
bool checkIfUserWon(struct Player player)
{
	if (pos1 == player.playerPieceSymbol &&  pos2 == player.playerPieceSymbol &&
			pos3 == player.playerPieceSymbol) {
		return true;
	} 
	else if (pos4 == player.playerPieceSymbol &&  pos5 == player.playerPieceSymbol &&
			pos6 == player.playerPieceSymbol) {
		return true;
	}
	else if (pos7 == player.playerPieceSymbol &&  pos8 == player.playerPieceSymbol &&
			pos9 == player.playerPieceSymbol) {
		return true;
	}
	else if (pos10 == player.playerPieceSymbol &&  pos11 == player.playerPieceSymbol &&
			pos12 == player.playerPieceSymbol) {
		return true;
	}
	else if (pos10 == player.playerPieceSymbol &&  pos11 == player.playerPieceSymbol &&
			pos12 == player.playerPieceSymbol) {
		return true;
	} 
	else if (pos13 == player.playerPieceSymbol &&  pos14 == player.playerPieceSymbol &&
			pos15 == player.playerPieceSymbol) {
		return true;
	}
	else if (pos16 == player.playerPieceSymbol &&  pos17 == player.playerPieceSymbol &&
			pos18 == player.playerPieceSymbol) {
		return true;
	}
	else if (pos19 == player.playerPieceSymbol &&  pos20 == player.playerPieceSymbol &&
			pos21 == player.playerPieceSymbol) {
		return true;
	}
	else if (pos22 == player.playerPieceSymbol &&  pos23 == player.playerPieceSymbol &&
			pos24 == player.playerPieceSymbol) {
		return true;
	}
	else if (pos1 == player.playerPieceSymbol &&  pos10 == player.playerPieceSymbol &&
			pos22 == player.playerPieceSymbol) {
		return true;
	}
	else if (pos11 == player.playerPieceSymbol &&  pos12 == player.playerPieceSymbol &&
			pos13 == player.playerPieceSymbol) {
		return true;
	}
	else if (pos12 == player.playerPieceSymbol &&  pos13 == player.playerPieceSymbol &&
			pos14 == player.playerPieceSymbol) {
		return true;
	}
	else if (pos3 == player.playerPieceSymbol &&  pos15 == player.playerPieceSymbol &&
			pos24 == player.playerPieceSymbol) {
		return true;
	}
	else if (pos4 == player.playerPieceSymbol &&  pos11 == player.playerPieceSymbol &&
			pos19 == player.playerPieceSymbol) {
		return true;
	}
	else if (pos7 == player.playerPieceSymbol &&  pos12 == player.playerPieceSymbol &&
			pos16 == player.playerPieceSymbol) {
		return true;
	}
	else if (pos2 == player.playerPieceSymbol &&  pos5 == player.playerPieceSymbol &&
			pos8 == player.playerPieceSymbol) {
		return true;
	}
	else if (pos8 == player.playerPieceSymbol &&  pos17 == player.playerPieceSymbol &&
			pos20 == player.playerPieceSymbol) {
		return true;
	}
	else if (pos17 == player.playerPieceSymbol &&  pos20 == player.playerPieceSymbol &&
			pos23 == player.playerPieceSymbol) {
		return true;
	}
	else if (pos9 == player.playerPieceSymbol &&  pos13 == player.playerPieceSymbol &&
			pos18 == player.playerPieceSymbol) {
		return true;
	}
	else if (pos6 == player.playerPieceSymbol &&  pos14 == player.playerPieceSymbol &&
			pos21 == player.playerPieceSymbol) {
		return true;
	}
	return false;
}