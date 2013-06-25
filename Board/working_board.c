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

// Following the DRY (Don't repeat yourself)
void printDot(int row, int col) 
{

	printf("%c", XYToBoardPiece(row, col));
}

void printSep()
{
	putchar(' ');
}

// This draws the possible positions on the boards
void printPossiblePositions(int curRow)
{
	for (int j = 0; j < 7; ++j) // cols
	{		
		if ( XYToBoardPiece(curRow+1, j+1) == '.' ) {
			if ( j == 0 ) {
				putchar(XYToBoardPiece(curRow+1, j+1));				
				putchar(' ');
				putchar(' ');
				putchar(' ');		
			}			
			else if (j == 6)
			{
				putchar(XYToBoardPiece(curRow+1, j+1));				
			}
			else 
			{			
				putchar(XYToBoardPiece(curRow+1, j+1));	
				putchar(' ');
				putchar(' ');
			}
		}
		if ( j != 6 && j != 0) {
			putchar(' ');
		}
	}
}

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
	for (int i = 0; i < 7; ++i)
	{
		char temp = 65+i;
		// Print the space to accommodate for the "player 1" (8) + 1 = 9 extra space 
		printf("%c", temp);
		printPossiblePositions(curRow);
		printf("%c", temp);
		printf("\n\n");
		++curRow;
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
	if (x == 1)
	{
		if (y == 1) {		
			return pos1;
		}
		if (y == 7) {
			return pos2;
		}
		if (y == 4) {
			return pos3;
		}		
	}
	if (x == 2)
	{
		if (y == 2) {
			return pos4;
		} 

		if (y == 4) {
			return pos5;
		}
		if (y == 6 ) {
			return pos6;	
		}
	}
	if (x == 3)
	{
		if (y == 3) {
			return pos7;
		} 
		if (y == 4) {
			return pos8;
		} 
		if (y == 5 ) {			
			return pos9;
		}
	}
	if (x == 4)
	{
		if ( y == 1 ) {
			return pos10;
		}
		if ( y == 2 ) {
			return pos11;
		}
		if ( y == 3) {
			return pos12;
		}
		if ( y == 5) {
			return pos13;
		}
		if ( y == 6 ) {
			return pos14;
		}
		if ( y == 7) {
			return pos15;
		}			
	}
	if (x == 5)
	{
		if ( y == 3){
			return pos16;
		} 
		if ( y == 4) {
			return pos17;
		}
		if ( y == 5 ) {
			return pos18;
		}
	}
	if (x == 6)
	{
		if ( y == 2) {
			return pos19;
		}
		if (y == 4) {
			return pos20;
		}
		if (y == 6) {
			return pos21;
		}		
	}
	if (x == 7)
	{
		if (y == 1) {
			return pos22;
		} 
		if ( y == 4 ) {
			return pos23;
		} 
		if (y == 7) {
			return pos24;
		}
	}
	return '\0';
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
