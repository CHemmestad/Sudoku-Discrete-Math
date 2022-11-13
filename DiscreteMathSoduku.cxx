#include <iostream>

using namespace std;

typedef int ARRAY [9][9][10];

void fillPuzzle ( ARRAY sudoku );

void setPuzzleEasy ( ARRAY sudoku );

void setPuzzleMedium ( ARRAY sudoku );

void setPuzzleHard ( ARRAY sudoku);

void clearBools ( ARRAY susdoku );

void checkNums ( ARRAY sudoku );

void newNums ( ARRAY sudoku );

void printPuzzle ( ARRAY sudoku );

bool isFinished ( ARRAY sudoku );

int main ( ) {
	ARRAY sudoku;
	
	fillPuzzle ( sudoku );
	setPuzzleEasy ( sudoku );
	//setPuzzleMedium ( sudoku );
	//setPuzzleHard ( sudoku );
	
	int x = 0;
	
	while ( !isFinished ( sudoku ) ) {
		cout << endl << endl << "** NEW NUMBERS ** - " << x++ << endl << endl;
		if ( x > 100 ) {
			break;
		}
		newNums ( sudoku );
		clearBools ( sudoku );
		checkNums ( sudoku );
		printPuzzle ( sudoku );
	}
	return 0;
}

void fillPuzzle ( ARRAY sudoku ) {
	for ( int x = 0 ; x < 9 ; x++ ) {
		for ( int y = 0 ; y < 9 ; y++ ) {
			for ( int z = 0 ; z < 10 ; z++ ) {
				sudoku[x][y][z] = 0;
			}
		}
	}
}

void setPuzzleHard ( ARRAY sudoku ) {
	sudoku[0][2][0] = 6; sudoku[0][3][0] = 3; sudoku[0][5][0] = 7;
	sudoku[1][2][0] = 4; sudoku[1][8][0] = 5; sudoku[2][0][0] = 1;
	sudoku[2][5][0] = 6; sudoku[2][7][0] = 8; sudoku[2][8][0] = 2;
	sudoku[3][0][0] = 2; sudoku[3][2][0] = 5; sudoku[3][4][0] = 3;
	sudoku[3][6][0] = 1; sudoku[3][8][0] = 6; sudoku[4][3][0] = 2;
	sudoku[4][6][0] = 3; sudoku[5][0][0] = 9; sudoku[5][4][0] = 7;
	sudoku[5][8][0] = 4; sudoku[6][1][0] = 5; sudoku[7][1][0] = 1;
	sudoku[8][2][0] = 8; sudoku[8][3][0] = 1; sudoku[8][5][0] = 9;
	sudoku[8][7][0] = 4;
}

void setPuzzleMedium ( ARRAY sudoku ) {
	sudoku[0][0][0] = 6; sudoku[0][3][0] = 3; sudoku[0][4][0] = 9;
	sudoku[0][6][0] = 4; sudoku[1][8][0] = 7; sudoku[2][8][0] = 5;
	sudoku[3][1][0] = 6; sudoku[3][5][0] = 9; sudoku[3][8][0] = 8;
	sudoku[4][1][0] = 5; sudoku[4][3][0] = 7; sudoku[4][5][0] = 2;
	sudoku[4][8][0] = 9; sudoku[5][1][0] = 4; sudoku[5][2][0] = 2;
	sudoku[5][3][0] = 5; sudoku[5][5][0] = 6; sudoku[6][0][0] = 5;
	sudoku[6][1][0] = 2; sudoku[6][5][0] = 7; sudoku[7][3][0] = 4;
	sudoku[7][8][0] = 2; sudoku[8][4][0] = 5; sudoku[8][6][0] = 9;
	sudoku[8][7][0] = 7;
}

void setPuzzleEasy ( ARRAY sudoku ) {
	sudoku[0][0][0] = 5; sudoku[0][1][0] = 3; sudoku[0][4][0] = 7;
	sudoku[1][0][0] = 6; sudoku[1][3][0] = 1; sudoku[1][4][0] = 9;
	sudoku[1][5][0] = 5; sudoku[2][1][0] = 9; sudoku[2][2][0] = 8;
	sudoku[2][7][0] = 6; sudoku[3][0][0] = 8; sudoku[3][4][0] = 6;
	sudoku[3][8][0] = 3; sudoku[4][0][0] = 4; sudoku[4][3][0] = 8;
	sudoku[4][5][0] = 3; sudoku[4][5][0] = 3; sudoku[5][0][0] = 7;
	sudoku[5][4][0] = 2; sudoku[5][8][0] = 6; sudoku[6][1][0] = 6;
	sudoku[6][6][0] = 2; sudoku[6][7][0] = 8; sudoku[7][3][0] = 4;
	sudoku[7][4][0] = 1; sudoku[7][5][0] = 9; sudoku[7][8][0] = 5;
	sudoku[8][4][0] = 8; sudoku[8][7][0] = 7; sudoku[8][8][0] = 9;
	sudoku[4][8][0] = 1;
}

void clearBools ( ARRAY sudoku ) {
	for ( int x = 0 ; x < 9 ; x++ ) {
		for ( int y = 0 ; y < 9 ; y++ ) {
			for ( int z = 1 ; z < 10 ; z++ ){
				sudoku [x][y][z] = 0;
			}
		}
	}
}

void checkNums ( ARRAY sudoku ) {
	int rightShift = 0;
	int downShift = 0;
	bool existence = false;
	for ( int num = 1 ; num < 10 ; num++ ) {
		for ( int x2 = 0 ; x2 < 9 ; x2++ ) {
			if ( x2 < 3 ) {
				downShift = 0;
			} else if ( (x2 > 2) && (x2 < 6) ) {
				downShift = 3;
			} else {
				downShift = 6;
			}
			for ( int y2 = 0 ; y2 < 9 ; y2++ ) {
				if ( y2 < 3 ) {
					rightShift = 0;
				} else if ( (y2 > 2) && (y2 < 6) ) {
					rightShift = 3;
				} else {
					rightShift = 6;
				}
				for ( int x3 = 0+downShift ; x3 < 3+downShift ; x3++ ) {
					for ( int y3 = 0+rightShift ; y3 < 3+rightShift ; y3++ ) {
						if ( sudoku [x3][y3][0] == num ) {
							existence = true;
						}
					}
				}
				for ( int x = 0 ; x < 9 ; x++ ) {
					if ( sudoku [x][y2][0] == num ) {
						existence = true;
					}
				}
				for ( int y = 0 ; y < 9 ; y++ ) {
					if ( sudoku [x2][y][0] == num ) {
						existence = true;
					}
				}
				if ( (existence == false) && (sudoku[x2][y2][0] == 0) ) {
					sudoku [x2][y2][num] = 1;
				} else {
					existence = false;
				}
			}
		}
	}
}

void newNums ( ARRAY sudoku ) {
	int count = 0;
	int lastNum = 0;
	for ( int x = 0 ; x < 9 ; x++ ) {
		for ( int y = 0 ; y < 9 ; y++ ) {
			for ( int z = 1 ; z < 10 ; z++ ) {
				if ( sudoku [x][y][z] == 1 ) {
					lastNum = z;
					count++;
				}
			}
			if ( count == 1 ) {
				sudoku [x][y][0] = lastNum;
				count = 0;
				lastNum = 0;
			} else {
				count = 0;
				lastNum = 0;
			}
		}
	}
}

bool isFinished ( ARRAY sudoku ) {
	bool isDone = true;
	for ( int x = 0 ; x < 9 ; x++ ) {
		for ( int y = 0 ; y < 9 ; y++ ) {
			if ( sudoku[x][y][0] == 0 ) {
				isDone = false;
			}
		}
	}
	return isDone;
}

void printPuzzle ( ARRAY sudoku ) {
	cout << endl;
	for ( int z = 0 ; z < 10 ; z++ ) {
		for ( int x = 0 ; x < 9 ; x++ ) {
			for ( int y = 0 ; y < 9 ; y++ ) {
				if ( y == 3 || y == 6 ) {
					cout << "|";
				}
				cout << sudoku[x][y][z] << " "; //Change zero to z and delete other comments to print logic process
			}
			cout << endl;
			if ( x == 2 || x == 5 ) {
				for ( int t = 0 ; t < 19 ; t++ ) {
					cout << "-";
				}
				cout << endl;
			}
		}
		cout << endl << z << endl << endl;
	}
}
