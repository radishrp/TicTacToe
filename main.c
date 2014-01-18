#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Function Definitions
int checkwin(char *, char);
void winmessage(int, char);
int findwinningmove(char *,char);
int numberofmovesleft(char *);
char player;
int makemove(char*,int,char);
int computermove(char *);
int aichoice;

int main(){
    int win_result_return_value;
    char newgame ='G';
char inputdata[]="         ";   //This is the board data.
display_tictactoe_boardarray(inputdata);
    int m=1;
    aichoice = 10;
    TicTacToeRun(inputdata);
    while(m=1)
    {                   //Asks user if he or she wants to play again.
        if(newgame=='Y')
        {
            strcpy(inputdata,"         ");
            TicTacToeRun(inputdata);
        }
        if(newgame=='N')
        {
            exit(0);
        }
        else
        {
            printf("Error. Play again? Y/N?\n");
            scanf(" %C",&newgame);
        };
    };
};

//TicTacToeRun() is the function that runs the game.
//It keeps track of whose turn it is.
//It also breaks out of the function if either player wins.
//At the end of the 9 turns, if no player has won, the "tie" message will appear.
int TicTacToeRun(char *inputdata)
{
    int win_position_return_value=0;
    int j=0;
    for(;j<9;j++)
    {
        if(j%2==0)
        {
            humanmakemove(inputdata,'X');
            win_position_return_value = checkwin(inputdata,'X');
            winmessage(win_position_return_value,'X');
            if(win_position_return_value !=0)
            {
               break;
            }
        }
        else
        {
            computermove(inputdata);
            win_position_return_value = checkwin(inputdata,'O');
            winmessage(win_position_return_value,'O');
            if(win_position_return_value !=0)
            {
               break;
            };
        };
    };
    if(win_position_return_value==0)
    {
            printf("It's a tie!\n");
    };
}

//This is the function that runs when it is the player's turn.
//The board is first drawn with the numbers corresponding to the board data, then the move is made according to the input.
void humanmakemove(char *inputdata, char player)
{
    int num=0;
    numberofmovesleft(inputdata);
    printf("[0][1][2]\n[3][4][5]\n[6][7][8]\nYour turn. Where do you want to place?\nType in a valid number listed above.\nPlacement:");
    scanf("%d",&num);
    makemove(inputdata,num,'X');
};

//Counts the number of moves left and counts the number of turns left.
//Now that I think about it, it's really unnecessary, as I could just add it tictactoe function.
int numberofmovesleft(char *inputdata)
{
    int i, j=0;
    for(i=0;i<10;i++)
    {
        if(inputdata[i]== ' ')
        {
            j++;
        };
    };
    printf("Turn %d.\n%d turns left.\n\n",10-j,j);
    return j;
}

//The function that makes the move. Also unnecessary. Can be placed in computermove() and humanmakemove() easily.
//Move the empty check to humanmakemove and the actual one line placement function to each.
int makemove(char *inputdata,int placement, char player)
{
    if (inputdata[placement]==' ')
    {
        inputdata[placement] = player;
        printf("Last move:\n");
        display_tictactoe_boardarray(inputdata);
    }
    else
    {
        printf("ERROR TRY AGAIN!!\n\n");
        humanmakemove(inputdata,'X');
    };
}

//Computer's function to move.
//First it picks a winning move if possible
//Then it finds the user's winning move and prevents it.
//Then it follows the "next best move" approach.
//Note that all AI moves are made in the function. The other functions only find the moves.
//The aichoice variable is used here to keep the AI from making more than 1 move at a time.
int computermove(char *inputdata)
{
    aichoice=findwinningmove(inputdata,'O');
    if(aichoice!=10)
    {
        makemove(inputdata,aichoice,'O');
        aichoice=1;
        return 0;
    }
    if(aichoice==10)
    {
        findwinningmove(inputdata,'X');
        if(aichoice!=10)
        {
            makemove(inputdata,aichoice,'O');
            aichoice=1;
            return 0;
        }
    }
    if(aichoice==10)
    {
    findnextbestmove(inputdata);
    };
}

//The code for finding the winning move.
int findwinningmove(char *inputdata,char player)
{
    int i, win_result_return_value;
    char test_position[10];
    for (i = 0; i < 9; i++)
    {
        if (inputdata[i] == ' ')
        {
            strcpy(test_position,inputdata);
            test_position[i] = player;
            int win_result_return_value = checkwin(test_position, player);
            if(win_result_return_value != 0)
            {
                aichoice = i;
                return aichoice;
                break;
            }
            else
            {
                continue;
            };

        };
    };
    aichoice=10;
    return aichoice;
};

//Find the "next best move".
//The code places in the middle first, then next to the opponent's move if they placed in the corner.
//Then it places in the corners.
int findnextbestmove(char *inputdata)
{
    int i, aichoice2=1;
    if(inputdata[4]==' ')
    {
//places at middle if empty
        makemove(inputdata,4,'O');
        return 0;
    }
    else
    {
        for (i = 0; i < 9; i+=2)
        {
//checks corners for 'X', then places beside it.
            if (inputdata[i] == 'X')
            {
                if ((i<7) && (i!=4) && (inputdata[i+1]) == ' ')
                {
                    makemove(inputdata,(i+1),'O');
                    aichoice2=0;
                    break;
                }
                if ((i>0) && (i!=4) && (inputdata[i-1]) == ' ')
                {
                    makemove(inputdata,(i-1),'O');
                    aichoice2=0;
                    break;
                }
                else
                {
                    continue;
                }
            }
        };
        if(aichoice2==1)
        {
//places in corner
            for(i=0;i<9;i+=2)
            {
                if(inputdata[i]==' ')
                {
                    makemove(inputdata,i,'O');
                    break;
                }
            }
        }
    }
}

//Displays the type of win achieved.
void winmessage(int win_position_return_value, char player)
{
    switch(win_position_return_value)
    {
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

//makes the "graphic render"
void display_tictactoe_boardarray(char *inputdata)
{
    char tictactoe_boardarray[] = "[ ][ ][ ] [ ][ ][ ] [ ][ ][ ]";
    int i , j , k ; k=0 ;
    for(i=0;i<3;i++)
    {
        for(j=1;j<=7;j+=3)
        {
            tictactoe_boardarray[(i*10)+j] = inputdata[k++];
        };

    };
printf("\n");
    for(i=0;i<30;i++)
    {
        printf("%c",tictactoe_boardarray[i]);
        if(i==9||i==19||i==29)
        {
            printf("\n");
        };
    };
};

//Checks whether a player has won or not.
int checkwin(char *inputdata,char player)
{
    int i;
    for(i=0;i<7;i+=3)
    {
        if(inputdata[i]== player && inputdata[i+1]== player && inputdata[i+2]== player)
        {
            return (10+i);
        };
    }; //horizontal win condition
    for(i=0;i<3;i++)
    {
        if(inputdata[i]== player && inputdata[i+3]== player && inputdata[i+6]== player)
        {
            return (20+i);
        }
    }; //vertical win condition
    if((inputdata[0]== player && inputdata[4]== player && inputdata[8]== player) || (inputdata[2]== player && inputdata[4]== player && inputdata[6]== player))
    {
        return 30; // diagonal win condition
    };
    return 0;
};
