#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
int checkwin(char *, char);
void winmessage(int, char);






int main(){

char inputdata[]="XXX OO XO";
display_tictactoe_boardarray(inputdata);
char player = 'X';
int win_position_return_value = checkwin(inputdata,player);
winmessage(win_position_return_value,player);




};

void winmessage(int win_position_return_value, char player){
switch(win_position_return_value){
    case 10 : printf("Horizontal win on Row 1 by %c!",player); break;
    case 13 : printf("Horizontal win on Row 2 by %c!",player); break;
    case 16 : printf("Horizontal win on Row 3 by %c!",player); break;
    case 20 : printf("Vertical win on Column 1 by %c!",player); break;
    case 23 : printf("Vertical win on Column 2 by %c!",player); break;
    case 26 : printf("Vertical win on Column 3 by %c!",player); break;
    case 30 : printf("Diagonal win by %c!", player); break;
    default: printf("Error."); break;

};
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


};

int checkwin(char *inputdata,char player){
    int i;
    for(i=0;i<7;i+=3){
        if(inputdata[i]== player && inputdata[i+1]== player && inputdata[i+2]== player){
            return (10+i);};
                         }; //horizontal win condition
    for(i=0;i<3;i++){
        if(inputdata[i]== player && inputdata[i+3]== player && inputdata[i+6]== player){
            return (20+i);}
                        }; //vertical win condition
    if((inputdata[0]== player && inputdata[4]== player && inputdata[8]== player) || (inputdata[2]== player && inputdata[4]== player && inputdata[6]== player)){
        return 30; // diagonal win condition
                                                                                                                                    };

return 0;
}

     // for loop allows input into the board
