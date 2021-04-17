
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "givenA2.h"
#include <stdlib.h> 



void createInitialBoard(char board[N][N]){
  int i;
  int j;
   for(i=0;i<3;i++){
    if(i==1||i==2){
       printf("\n----------\n");
    }
    for(j=0;j<3;j++){
      board[i][j]='?';
      printf(" %c ",board[i][j]);
      if(j==0||j==1){
        printf("|");
      }
    }
    
  }
  
   printf("\n");
}
int isBoardFull (char board [N][N]){
  int i ;
  int j=0;
  for(i = 0;i<N;i++){
    for(j =0;j<N;j++){
      if(board[i][j]=='?'){
        return 0;
      }
    }
  }
  return 1;
}

int isInputValid (int entered, int minimum, int maximum){
  if(entered >= minimum && entered <= maximum){
    return 1;
  }
  return 0;
}
void readUserMove (int * userRow, int *userCol, int * stepsWon){
  do{
printf("Your move Enter a number between 1 and 3");
  printf("\n\nEnter row number: ");
    scanf("%d",userRow);
  printf("\nEnter columun number: ");
  scanf("%d",userCol);
  }
  while(isInputValid(*userRow, 1, 3)!=1&&isInputValid(*userCol, 1, 3)!=1);

  
 *stepsWon = *stepsWon+1;
}

void printCurrentBoard (char board [N][N]){
    int i;
    int j;
   for(i=0;i<3;i++){
    if(i==1||i==2){
    
       printf("\n----------\n");
    }
    for(j=0;j<3;j++){
      printf(" %c ",board[i][j]);
      if(j==0||j==1){
        printf("|");
      }
    }
    
  }
  printf("\n");
    
}


int gameWon (char board [N][N], char symbol){
    if((symbol==board[0][0]) && (symbol==board[0][1]) && (symbol==board[0][2])){
      return 1;
    }else if((symbol==board[1][0]) && (symbol==board[1][1]) && (symbol==board[1][2])){
      return 1;
    }else if((symbol==board[2][0]) && (symbol==board[2][1]) && (symbol==board[2][2])){
      return 1;
    }else if((symbol==board[0][0]) && (symbol==board[1][0]) && (symbol==board[2][0])){
      return 1;
    }else if((symbol==board[0][1]) && (symbol==board[1][1]) && (symbol==board[2][1])){
      return 1;
    }else if((symbol==board[0][2]) && (symbol==board[1][2]) && (symbol==board[2][2])){
      return 1;
    }else if((symbol==board[0][0]) && (symbol==board[1][1]) && (symbol==board[2][2])){
        return 1;
    }else if((symbol==board[2][0]) && (symbol==board[1][1]) && (symbol==board[0][2])){
      return 1;
    }

    return 0;
}

void computerPlaysRandom(int * cRow , int * cCol){
    
   *cRow = (rand() % 3) + 0;
  *cCol = (rand() % 3) + 0;

}

int computerPlaysToWin(char board[N][N], int *cRow , int *cCol ){
  //if 2 spots are filled with O and the winning spots is occupied with a ? then that winning spot is a O
  if(board[0][0]=='O'&& board[0][1]=='O'&& board[0][2]=='?'){
    board[0][2]='O';
    printf("hi");
          return 1;
          
  }else if((board[0][1]=='O'&& board[0][2]=='O'&& board[0][0]=='?')){
      board[0][0] ='O';
       printf("hi");
          return 1;
  }else if(board[1][0]=='O'&& board[1][1]=='O'&& board[1][2]=='?'){
      board[1][2] ='O';
       printf("hi");
          return 1;
  }else if((board[1][1]=='O'&& board[1][2]=='O'&& board[1][0]=='?')){
      board[1][0] ='O';
       printf("hi");
          return 1;
  }else if((board[2][0]=='O'&& board[2][1]=='O'&& board[2][2]=='?')){
      board[2][2] ='O';
       printf("hi");
          return 1;
  }else if((board[2][1]=='O'&& board[2][2]=='O'&& board[2][0]=='?')){
      board[2][0] ='O';
       printf("hi");
          return 1;
  }else if((board[0][0]=='O'&& board[1][0]=='O'&& board[2][0]=='?')){
      board[2][0] ='O';
       printf("hi");
          return 1;
  }else if((board[1][0]=='O'&& board[2][0]=='O'&& board[0][0]=='?')){
      board[0][0] ='O';
       printf("hi");
          return 1;
  }else if((board[0][1]=='O'&& board[1][1]=='O'&& board[2][1]=='?')){
      board[2][1] ='O';
       printf("hi");
          return 1;
  }else if((board[1][1]=='O'&& board[2][1]=='O'&& board[0][1]=='?')){
board[0][1] ='O';
       printf("hi");
          return 1;
  } else if((board[0][2]=='O'&& board[1][2]=='O'&& board[2][2]=='?')){
      board[2][2] ='O';
       printf("hi");
          return 1;
  }else if((board[1][2]=='O'&& board[2][2]=='O'&& board[0][2]=='?')){
      board[0][2] ='O';
       printf("hi");
          return 1;
  }else if((board[0][0]=='O'&& board[1][1]=='O'&& board[2][2]=='?')){
      board[2][2] ='O';
       printf("hi");
          return 1;
  }else if((board[1][1]=='O'&& board[2][2]=='O'&& board[0][0]=='?')){
      board[0][0] ='O';
       printf("hi");
          return 1;
  }else if((board[2][0]=='O'&& board[1][1]=='O'&& board[0][2]=='?')){
      board[0][2] ='O';
       printf("hi");
          return 1;
  }else if((board[1][1]=='O'&& board[0][2]=='O'&& board[2][0]=='?')){
      board[2][0] ='O';
       printf("hi");

          return 1;
          //not together
  }else if(board[0][0]=='O'&&board[0][2]=='O'&&board[0][1]=='?'){
       board[0][1] ='O';
       printf("hit");
          return 1;
  }else if(board[1][0]=='O'&&board[1][2]=='O'&&board[1][1]=='?'){
         board[1][1] ='O';
       printf("hit");
          return 1;
  }else if(board[2][0]=='O'&&board[2][2]=='O'&&board[2][1]=='?'){
         board[2][1] ='O';
       printf("hit");
          return 1;
  }else if(board[0][0]=='O'&&board[2][0]=='O'&&board[1][0]=='?'){
         board[1][0] ='O';
       printf("hit");
          return 1;
  }else if(board[0][1]=='O'&&board[2][1]=='O'&&board[1][1]=='?'){
       board[1][1] ='O';
       printf("hit");
          return 1;
  }else if(board[0][2]=='O'&&board[2][2]=='O'&&board[1][2]=='?'){
       board[1][2] ='O';
       printf("hit");
          return 1;
  }else if(board[0][0]=='O'&&board[2][2]=='O'&&board[1][1]=='?'){
       board[1][1] ='O';
       printf("hit");
          return 1;
  }else if(board[2][0]=='O'&&board[0][2]=='O'&&board[1][1]=='?'){
       board[1][1] ='O';
       printf("hit");
          return 1;
  }
  
  
  return 0;
}

int computerPlaysToBlock(char board[N][N], int *cRow , int *cCol ){
  //if 2 spots are filled with O and the winning spots is occupied with a ? then that winning spot is a O
  if(board[0][0]=='X'&& board[0][1]=='X'&& board[0][2]=='?'){
    board[0][2]='O';

          return 1;
          
  }else if((board[0][1]=='X'&& board[0][2]=='X'&& board[0][0]=='?')){
      board[0][0] ='O';
    
          return 1;
  }else if(board[1][0]=='X'&& board[1][1]=='X'&& board[1][2]=='?'){
      board[1][2] ='O';
      
          return 1;
  }else if((board[1][1]=='X'&& board[1][2]=='X'&& board[1][0]=='?')){
      board[1][0] ='O';
      
          return 1;
  }else if((board[2][0]=='X'&& board[2][1]=='X'&& board[2][2]=='?')){
      board[2][2] ='O';
      
          return 1;
  }else if((board[2][1]=='X'&& board[2][2]=='X'&& board[2][0]=='?')){
      board[2][0] ='O';

          return 1;
  }else if((board[0][0]=='X'&& board[1][0]=='X'&& board[2][0]=='?')){
      board[2][0] ='O';
      
          return 1;
  }else if((board[1][0]=='X'&& board[2][0]=='X'&& board[0][0]=='?')){
      board[0][0] ='O';
      
          return 1;
  }else if((board[0][1]=='X'&& board[1][1]=='X'&& board[2][1]=='?')){
      board[2][1] ='O';

          return 1;
  }else if((board[1][1]=='X'&& board[2][1]=='X'&& board[0][1]=='?')){
board[0][1] ='O';
   
          return 1;
  } else if((board[0][2]=='X'&& board[1][2]=='X'&& board[2][2]=='?')){
      board[2][2] ='O';
   
          return 1;
  }else if((board[1][2]=='X'&& board[2][2]=='X'&& board[0][2]=='?')){
      board[0][2] ='O';
     
          return 1;
  }else if((board[0][0]=='X'&& board[1][1]=='X'&& board[2][2]=='?')){
      board[2][2] ='O';
 
          return 1;
  }else if((board[1][1]=='X'&& board[2][2]=='X'&& board[0][0]=='?')){
      board[0][0] ='O';
 
          return 1;
  }else if((board[2][0]=='X'&& board[1][1]=='X'&& board[0][2]=='?')){
      board[0][2] ='O';
    
          return 1;
  }else if((board[1][1]=='X'&& board[0][2]=='X'&& board[0][0]=='?')){
      board[2][0] ='O';
    

          return 1;
          //Not together
  }else if(board[0][0]=='X'&&board[0][2]=='X'&&board[0][1]=='?'){
       board[0][1] ='O';
  
          return 1;
  }else if(board[1][0]=='X'&&board[1][2]=='X'&&board[1][1]=='?'){
         board[1][1] ='O';
      
          return 1;
          
  }else if(board[2][0]=='X'&&board[2][2]=='X'&&board[2][1]=='?'){
         board[2][1] ='O';

          return 1;
  }else if(board[0][0]=='X'&&board[2][0]=='X'&&board[1][0]=='?'){
         board[1][0] ='O';
     
          return 1;
  }else if(board[0][1]=='X'&&board[2][1]=='X'&&board[1][1]=='?'){
       board[1][1] ='O';
     
          return 1;
  }else if(board[0][2]=='X'&&board[2][2]=='X'&&board[1][2]=='?'){
       board[1][2] ='O';
 
          return 1;
  }else if(board[0][0]=='X'&&board[2][2]=='X'&&board[1][1]=='?'){
       board[1][1] ='O';
    
          return 1;
  }else if(board[2][0]=='X'&&board[0][2]=='X'&&board[1][1]=='?'){
       board[1][1] ='O';
    
          return 1;
  }
  return 0;
}

void all_sums(char board[N][N], int sumRow[N], int sumCol[N], int *cRow, int *cCol){

}
void printAllSums(int sumRows[N], int sumCols[N]){

}

int memberOf(int value, int someArray[N]){
    if(someArray[N]==value){
        return 1;
    }else {
      return 0;
    }
}

int  getComputerMove(char board[N][N], int * computerRow, int * computerCol, int userRow, int userCol){
    
    int winningSpot = 0;
    
    winningSpot = computerPlaysToWin(board, computerRow, computerCol);
   // printf("%d\n",winningSpot);
    
    /*
     if the computer does not find a winning spot, then it either play randomly or blocks
     */
    
    if (!winningSpot)
    {
        // comment the next line if you are attempting the 2% functionality
       // computerPlaysRandom(computerRow, computerCol);
        
      
        int blocked = 0;
         
         blocked = computerPlaysToBlock(board, computerRow, computerCol);
         if (blocked == 0) {
            computerPlaysRandom(computerRow, computerCol);
         }
         
         return blocked;
         
    }
    
    return winningSpot;
}
