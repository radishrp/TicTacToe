#include <stdio.h>
#include <stdlib.h>

int main()
{
    typedef struct tictactoeboard_description {
        char square[3][3];

        }tictactoeboard;

    int init_board(tictactoeboard *board) {
        int i = 0;
        int j = 0;

        for (i=0;i<3;i++) {
            for (j=0;j<3;j++) {
                board->square[i][j]= '_';
            };
        };
        };
        return 1;
}
