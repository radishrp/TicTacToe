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

//typedef struct tictactoeboard_description {
//        char square[3][3];
 //       }tictactoeboard; //structure of tictactoeboard maybe used in later edits
int checkwin(char *, char);
void winmessage(int, char);
int findwinningmove(char *,char);
int numberofmovesleft(char *);
char player;
int makemove(char*,int,char);
int recursiveloop(char*,char);







int main(){

char inputdata[]="X XOOX O ";
display_tictactoe_boardarray(inputdata);
        char test_position[10];
       char test_position2[10];
       strcpy(test_position, inputdata);
       int i=0;
       printf("%s",inputdata);
printf("%d",recursiveloop(inputdata,'X'));
                    }










int TicTacToeRun(char *inputdata){
    int i=0;
for(i=0;i<6;i++){
    humanmakemove(inputdata,'X');
    if((numberofmovesleft(inputdata))==0){
       return 0;}
    else{
            computermove(inputdata,'O');
    }

}

}




void humanmakemove(char *inputdata, char player){
    int num=0;
    numberofmovesleft(inputdata);
    printf("[0][1][2]\n[3][4][5]\n[6][7][8]\nYour turn. Where do you want to place?\nType in a valid number listed above.\nPlacement:");
    int placement;
    scanf("%d",&placement);
        if(placement==0||placement==1||placement==2||placement==3||placement==4||placement==5||placement==6||placement==7||placement==8)
            {
            makemove(inputdata,placement,player);

            }
        else{
            printf("Error. Pick a valid number.\n");
        }
                                                };

int numberofmovesleft(char *inputdata){
int i, j=0;

for(i=0;i<10;i++){
    if(inputdata[i]== ' '){
        j++;
                            };
                };
    printf("Turn %d.\n%d turns left.\n\n",10-j,j);
    return j;
                                        };

int makemove(char *inputdata,int placement, char player){
       int i = placement;
    if((inputdata[i])!= ' '){
            printf("Error. Choose valid placement.\n");
    humanmakemove(inputdata,player);
    }
    else{
            inputdata[i] = player;


    //switch(placement){
   // case 'a' : i=0; break;
   // case 'b' : i=1; break;
    //case 'c' : i=2; break;
   // case 'd' : i=3; break;
   // case 'e' : i=4; break;
   // case 'f' : i=5; break;
  //  case 'g' : i=6; break;
   // case 'h' : i=7; break;
   // case 'i' : i=8; break;
   // default: printf("error"); break;}

display_tictactoe_boardarray(inputdata);
int win_position_return_value = checkwin(inputdata,player);
winmessage(win_position_return_value,player);
        }
}

void computermove(char *inputdata,char player){
int depth = numberofmovesleft(inputdata);
findwinningmove(inputdata,player);
}

int findwinningmove(char *inputdata,char player){
    //int a,b,c,d,e,f,g,h,i,j;
 //   char deptharray[8][7][6][5][4][3][2][1];

 //   for(a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0;){}
 //   deptharray[a][b][c][d][e][f][g][h]
 //  if(inputdata[i]== ' '){
  //     strcpy(testposition, inputdata);
   //    testposition[i]=player;
   //    win_result=checkwin(testposition,player);

 }


int  recursiveloop(char *test_position,char player){
int i;
long int j=0;
char winchance=1000
char test_position2[10];
        for (i = 0; i < 9; i++) {
            if (test_position[i] == ' ') {
                strcpy(test_position2,test_position);
                test_position2[i] = player;
                int win_result_return_value = checkwin(test_position2, player);
                printf("The result of playing %c at position %d is: %d  \n",
                    player, i, win_result_return_value);
                display_tictactoe_boardarray(test_position);
                if((player == 'X') && (win_result_return_value > 1)){
                winchance - 1;
                }
                if((player == 'X') && (win_result_return_value > 1)){
                winchance + 1;
                }

                if(numberofmovesleft(test_position2)!=0){
                    if(player == 'X'){
                        player = 'O';
                        recursiveloop(test_position2,player);
                    }
                    else{
                        player ='X';
                        recursiveloop(test_position2,player);
                    }

                }
            }
   }}






void winmessage(int win_position_return_value, char player){
switch(win_position_return_value){
    case 10 : printf("Horizontal win on Row 1 by %c!\n",player); return 100; break;
    case 13 : printf("Horizontal win on Row 2 by %c!\n",player); return 100; break;
    case 16 : printf("Horizontal win on Row 3 by %c!\n",player); return 100; break;
    case 20 : printf("Vertical win on Column 1 by %c!\n",player); return 100; break;
    case 21 : printf("Vertical win on Column 2 by %c!\n",player); return 100; break;
    case 22 : printf("Vertical win on Column 3 by %c!\n",player); return 100; break;
    case 30 : printf("Diagonal win by %c!\n", player); return 100; break;
    default: printf("No win condition.\n"); return 100; break;

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
printf("\n");
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
};

     // for loop allows input into the board
