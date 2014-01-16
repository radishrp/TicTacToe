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
void computermove(char *);







int main(){
    int win_result_return_value;

char inputdata[]="         ";
display_tictactoe_boardarray(inputdata);
TicTacToeRun(inputdata);

                    }










int TicTacToeRun(char *inputdata){
    int i=0;
    int win_result_return_value;
for(i=0;i<9;i++){
        if(i%2==0){
                humanmakemove(inputdata,'X');
                    printf("%s",inputdata);
                if(win_result_return_value != 0){
                    break;
                }
        }
        else{
            computermove(inputdata);
        printf("%s",inputdata);
        if(win_result_return_value >0){
            break;
        }

};
};
label:
    winmessage(win_result_return_value,player);
}





void humanmakemove(char *inputdata, char player){
    int num=0;
    numberofmovesleft(inputdata);
    printf("[0][1][2]\n[3][4][5]\n[6][7][8]\nYour turn. Where do you want to place?\nType in a valid number listed above.\nPlacement:");
    scanf("%d",&num);
            if((num==0||num==1||num==2||num==3||num==4||num==5||num==6||num==7||num==8))
            {
                if(inputdata[num]= ' '){
            makemove(inputdata,num,player);
            };

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
            inputdata[i] = player;
            printf("Last move:\n");
display_tictactoe_boardarray(inputdata);
int win_position_return_value = checkwin(inputdata,player);
winmessage(win_position_return_value,player);
        ;
};

void computermove(char *inputdata){
    findwinningmove(inputdata,'O');
    findwinningmove(inputdata,'X');
    findnextbestmove(inputdata);
}

int findwinningmove(char *inputdata,char player){
int i, win_result_return_value;
char test_position[10];
for (i = 0; i < 9; i++) {
            if (inputdata[i] == ' ') {
                strcpy(test_position,inputdata);
                test_position[i] = player;
                int win_result_return_value = checkwin(test_position, player);
                if(win_result_return_value != 0){
                    makemove(inputdata,i,'O');
                    break;
                }

 };
};};

int findnextbestmove(char *inputdata){
    int i;
    if(inputdata[4]==' '){
        makemove(inputdata,4,'O');
    }
    else{
        for (i = 0; i < 9; i++) {
            if (inputdata[i] == 'X') {
                if ((i<9) && (inputdata[i+1]) == ' '){
                    makemove(inputdata,(i+1),'O');

                }
                if ((i>0) && (inputdata[i+1]) == ' '){
                    makemove(inputdata,(i-1),'O');
                    break;
                }
                else {
                        continue;
                }
    }
};

}}






void winmessage(int win_position_return_value, char player){
switch(win_position_return_value){
    case 10 : printf("Horizontal win on Row 1 by %c!\n",player); return 0;
    case 13 : printf("Horizontal win on Row 2 by %c!\n",player); return 0;
    case 16 : printf("Horizontal win on Row 3 by %c!\n",player); return 0;
    case 20 : printf("Vertical win on Column 1 by %c!\n",player); return 0;
    case 21 : printf("Vertical win on Column 2 by %c!\n",player); return 0;
    case 22 : printf("Vertical win on Column 3 by %c!\n",player); return 0;
    case 30 : printf("Diagonal win by %c!\n", player); return 0;
    default: printf("No win condition.\n"); return 0;

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
