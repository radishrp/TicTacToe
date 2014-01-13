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
        }tictactoeboard; //structure of tictactoeboard maybe used in later edits






int main()
{

char inputdata[]="xxx oo xo";
    display_tictactoe_boardarray(inputdata);
return 1;
};



void checkwin(char *inputdata, char player) {
    int i;
    for(i=0;i<7;i+=3){
        if(inputdata[i]== player && inputdata[i+1]==player && inputdata[i+2]==player){
            return 1;};
                         }; //horizontal win condition
    for(i=0;i<3;i++){
        if(inputdata[i]==player && inputdata[i+3]==player && inputdata[i+6]==player){
            return 1;}
                        }; //vertical win condition
    if((inputdata[0]==player && inputdata[4]==player && inputdata[8]==player) || (inputdata[2]==player && inputdata[4]==player && inputdata[6]==player)){
        return 1; // diagonal win condition
                                                                                                                                    };
    return 0;
                                                                                                                                    };


void display_tictactoe_boardarray(char *inputdata) {
    char tictactoe_boardarray[] = "[ ][ ][ ] [ ][ ][ ] [ ][ ][ ]"; //makes the "graphic render"

    int i , j , k ; k=0 ;
    for(i=0;i<3;i++){
        for(j=1;j<=7;j+=3){
            tictactoe_boardarray[(i*10)+j] = inputdata[k++];

            };

    };

    for(i=0;i<30;i++){
        printf("%c",tictactoe_boardarray[i]);
        if(i==9||i==19||i==29){
            printf("\n");

        };
    };
}



     // for loop allows input into the board
