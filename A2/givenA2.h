#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3
void createInitialBoard(char[N][N]);
void readUserMove(int *, int *, int *);
void printCurrentBoard(char[N][N]);
void computerPlaysRandom(int * , int *);
int computerPlaysToWin(char [N][N], int * , int * );
int getComputerMove(char board[N][N], int *, int *, int, int);
int gameWon(char [N][N], char);
int isInputValid(int, int, int);
void all_sums(char board[N][N], int [N], int [N], int *, int *);
void printAllSums(int sumRows[N], int sumCols[N]);
int maxValue(int [N], int *);
int memberOf(int value, int someArray[N]);
int isBoardFull(char board[N][N]);
int computerPlaysToBlock(char [N][N], int * , int * );