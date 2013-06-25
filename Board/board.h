char XYToBoardPiece(int x, int y);

// possible positions on the boards, default value: '.'		
char pos1 = '.',
	 pos2 = '.',
	 pos3 = '.',
	 pos4 = '.',
	 pos5 = '.',
	 pos6 = '.',
	 pos7 = '.',
	 pos8 = '.',
	 pos9 = '.',
	 pos10 = '.',
	 pos11 = '.',
	 pos12 = '.',
	 pos13 = '.',
	 pos14 = '.',
	 pos15 = '.',
	 pos16 = '.',
	 pos17 = '.',
	 pos18 = '.',
	 pos19 = '.',
	 pos20 = '.',
	 pos21 = '.',
	 pos22 = '.',
	 pos23 = '.',
	 pos24 = '.';

// This draws the board
void drawBoard() 
{
	int curRow = 0;
	putchar('\n');
	// Print the top numbers
	putchar(' ');
	for (int i = 0; i < 7; ++i)
	{	
		printf("%d   ", i+1);
	}
	putchar('\n');
	// Print the Letters on the side and the dots
	for (int i = 1; i <= 7; ++i)
	{
		char temp = 64+i;
		// Print the space to accommodate for the "player 1" (8) + 1 = 9 extra space 
		printf("%c", temp);	
		for (int j = 1; j <= 7; ++j)
		{
			if (XYToBoardPiece(j,i) != '\r' )
			{
				if (j == 1)
				{
					putchar(XYToBoardPiece(j,i));
					putchar(' ');
					putchar(' ');
					putchar(' ');					
				} else if (j==7) {
					putchar(XYToBoardPiece(j,i));
				} else {
					putchar(XYToBoardPiece(j,i));
					putchar(' ');
					putchar(' ');
					putchar(' ');
				}
			}			
			else
			{
				if ( j == 7 ) {
					putchar(' ');
					continue;
				}
				putchar(' ');
				putchar(' ');
				putchar(' ');
				putchar(' ');	

			}
		}
		printf("%c", temp);
		printf("\n\n");
	}
	putchar(' ');
	// print the bottom numbers
	for (int i = 0; i < 7; ++i)
	{	
		printf("%d   ", i+1);
	}
	putchar('\n');
}


/*
	This take x and y and return a Piece on the board.
	 _ _ _ _ x   
	|      X (4,1) => X
	|  .(2,2) => .
	|      O (4, 3) => O
	y
*/
char XYToBoardPiece(int x, int y) 
{
	if (y == 1)
	{
		if (x == 1) {		
			return pos1;
		}
		if (x == 7) {
			return pos2;
		}
		if (x == 4) {
			return pos3;
		}		
	}
	if (y == 2)
	{
		if (x == 2) {
			return pos4;
		} 

		if (x == 4) {
			return pos5;
		}
		if (x == 6 ) {
			return pos6;	
		}
	}
	if (y == 3)
	{
		if (x == 3) {
			return pos7;
		} 
		if (x == 4) {
			return pos8;
		} 
		if (x == 5 ) {			
			return pos9;
		}
	}
	if (y == 4)
	{
		if ( x == 1 ) {
			return pos10;
		}
		if ( x == 2 ) {
			return pos11;
		}
		if ( x == 3) {
			return pos12;
		}
		if ( x == 5) {
			return pos13;
		}
		if ( x == 6 ) {
			return pos14;
		}
		if ( x == 7) {
			return pos15;
		}			
	}
	if (y == 5)
	{
		if ( x == 3){
			return pos16;
		} 
		if ( x == 4) {
			return pos17;
		}
		if ( x == 5 ) {
			return pos18;
		}
	}
	if (y == 6)
	{
		if ( x == 2) {
			return pos19;
		}
		if (x == 4) {
			return pos20;
		}
		if (x == 6) {
			return pos21;
		}		
	}
	if (y == 7)
	{
		if (x == 1) {
			return pos22;
		} 
		if (x == 4 ) {
			return pos23;
		} 
		if (x == 7) {
			return pos24;
		}
	}
	return '\r';
}

/*
	This takes x and y and return the pos as a string.
	I.E
	XYToBoardPos(1,1) = pos1
	XYToBoardPos(2,4) = pos5
	@return string the position
*/
char* XYToBoardPos(int x, int y) 
{
	if (y == 1)
	{
		if (x == 1) {		
			return "pos1";
		}
		if (x == 4) {
			return "pos2";
		}
		if (x == 7) {
			return "pos3";
		}		
	}
	if (y == 2)
	{
		if (x == 2) {
			return "pos4";
		} 

		if (x == 4) {
			return "pos5";
		}
		if (x == 6 ) {
			return "pos6";	
		}
	}
	if (y == 3)
	{
		if (x == 3) {
			return "pos7";
		} 
		if (x == 4) {
			return "pos8";
		} 
		if (x == 5 ) {			
			return "pos9";
		}
	}
	if (y == 4)
	{
		if ( x == 1 ) {
			return "pos10";
		}
		if ( x == 2 ) {
			return "pos11";
		}
		if ( x == 3) {
			return "pos12";
		}
		if ( x == 5) {
			return "pos13";
		}
		if ( x == 6 ) {
			return "pos14";
		}
		if ( x == 7) {
			return "pos15";
		}			
	}
	if (y == 5)
	{
		if ( x == 3){
			return "pos16";
		} 
		if ( x == 4) {
			return "pos17";
		}
		if ( x == 5 ) {
			return "pos18";
		}
	}
	if (y == 6)
	{
		if ( x == 2) {
			return "pos19";
		}
		if (x == 4) {
			return "pos20";
		}
		if (x == 6) {
			return "pos21";
		}		
	}
	if (y == 7)
	{
		if (x == 1) {
			return "pos22";
		} 
		if ( x == 4 ) {
			return "pos23";
		} 
		if (x == 7) {
			return "pos24";
		}
	}
}

/*
	This method takes a char from A - G and then return a 1 - 7
*/
int YAxisToInt(char y)
{
	if (y == 'a')
	{
		return 1;
	}
	else if ( y == 'b' )
	{
		return 2;
	}
	else if ( y == 'c' )
	{
		return 3;
	}
	else if ( y == 'd' )
	{
		return 4;
	}
	else if ( y == 'e' )
	{
		return 5;
	}
	else if ( y == 'f' )
	{
		return 6;
	}
	else if ( y == 'g' )
	{
		return 7;
	}
	return 0;
}



/*
	This takes (x,y) and then sets the pos(n) to the playerSymbol.
*/
void PlaceSymbolOnBoard(int x, int y, char playerBoardSymbol /*identifier */)
{
	if (y == 1)
	{
		if (x == 1) {		
			pos1 = playerBoardSymbol;
		}
		if (x == 7) {
			pos2 = playerBoardSymbol;
		}
		if (x == 4) {
			pos3 = playerBoardSymbol;
		}		
	}
	else if (y == 2)
	{
		if (x == 2) {
			pos4 = playerBoardSymbol;
		} 

		if (x == 4) {
			pos5 = playerBoardSymbol;
		}
		if (x == 6 ) {
			pos6 = playerBoardSymbol;	
		}
	}
	else if (y == 3)
	{
		if (x == 3) {
			pos7 = playerBoardSymbol;
		} 
		if (x == 4) {
			pos8 = playerBoardSymbol;
		} 
		if (x == 5 ) {			
			pos9 = playerBoardSymbol;
		}
	}
	else if (y == 4)
	{
		if ( x == 1 ) {
			pos10 = playerBoardSymbol;
		}
		if ( x == 2 ) {
			pos11 = playerBoardSymbol;
		}
		if ( x == 3) {
			pos12 = playerBoardSymbol;
		}
		if ( x == 5) {
			pos13 = playerBoardSymbol;
		}
		if ( x == 6 ) {
			pos14 = playerBoardSymbol;
		}
		if ( x == 7) {
			pos15 = playerBoardSymbol;
		}			
	}
	else if (y == 5)
	{
		if ( x == 3){
			pos16 = playerBoardSymbol;
		} 
		if ( x == 4) {
			pos17 = playerBoardSymbol;
		}
		if ( x == 5 ) {
			pos18 = playerBoardSymbol;
		}
	}
	else if (y == 6)
	{
		if (x == 2) {
			pos19 = playerBoardSymbol;
		}
		if (x == 4) {
			pos20 = playerBoardSymbol;
		}
		if (x == 6) {
			pos21 = playerBoardSymbol;
		}		
	}
	else if (y == 7)
	{
		if (x == 1) {
			pos22 = playerBoardSymbol;
		} 
		if ( x == 4 ) {
			pos23 = playerBoardSymbol;
		} 
		if (x == 7) {
			pos24 = playerBoardSymbol;
		}
	}
}

/*
	This moves pieces on the boards
*/
void movePieceOnBoard (int oldx,int oldy,int newx,int newy, char playerBoardPiece)
{
	if (XYToBoardPiece(oldx,oldy) == playerBoardPiece)
	{
		PlaceSymbolOnBoard(oldx, oldy, '.');
		PlaceSymbolOnBoard(newx, newy, playerBoardPiece);
	}
}

/*
	This removes a piece on the board
*/
void RemoveSymbolFromBoard(int x, int y)
{
	PlaceSymbolOnBoard(x, y, '.');
}
