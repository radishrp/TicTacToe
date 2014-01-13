#include <stdio.h>
#include <stdlib.h>


//int init_board(tictactoeboard *board) {
 //       int i = 0;
  //      int j = 0;
//
  //      for (i=0;i<3;i++) {
    //        for (j=0;j<3;j++) {
      //          board->square[i][j]= '_';
        //    };}}

typedef struct tictactoeboard_description {
        char square[3][3];
        }tictactoeboard;






int main()
{

char inputdata[]=" xo oo xo";
    display_tictactoe_boardarray(inputdata);
};


void display_tictactoe_boardarray(char *inputdata) {
    char tictactoe_boardarray[] = "[ ][ ][ ] [ ][ ][ ] [ ][ ][ ]";

    int i , j , k ; k=0 ;
    for(i=0;i<3;i++){
        for(j=1;j<=7;j+=3){
            tictactoe_boardarray[(i*10)+j] = inputdata[k++];
            };
            };
    printf("%s", tictactoe_boardarray);
    };
