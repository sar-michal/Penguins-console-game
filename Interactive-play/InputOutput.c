# include <stdio.h>
# include "InputOutput.h"

int dim_x, dim_y; //board's dimensions
int x, y; // variables for penguin coordinates
int current_player; //chosen player
int penguin; //chosen penguin

int ask_number_penguins_and_board_dimensions(int *number_penguins, int *dim_x, int *dim_y)
{
    printf("Input number of penguins between 1 and 5 \n");
    scanf("%d", &*number_penguins);
    printf("Input coordinates for x and y dimensions between 4 and 20\n");
    scanf("%d", &*dim_y);
    scanf("%d", &*dim_x);
}

void show_board(char** board, int dim_x, int dim_y)
{
    printf("\n  X ");
    for(int j = 0; j< dim_y; j++)
    {
        if(j<10)
            printf("%d  ", j);
        else printf("%d ", j);
    }
    printf("\nY   ");
    for(int j = 0; j< dim_y; j++)
    {
        printf("-  ");
    }
    for (int i = 0; i < dim_x; i++)
    {
        if(i<10)
            printf("\n%d | ", i);
        else printf("\n%d| ", i);
        for(int j = 0; j< dim_y; j++)
        {
            if(j!=dim_y-1)
                printf("%c  ", board[i][j]);
            else printf("%c ", board[i][j]);
        }
        printf("|");
    }
    printf("\n    ");
    for(int j = 0; j< dim_y; j++)
    {
        printf("-  ");
    }
    printf("\n\n");
}

void ask_for_coordinates(int *x, int *y)
{
    printf("Provide the x and y coordinates:\n");
    scanf("%d", &*y);
    scanf("%d", &*x);
}

void show_score(int score1, int score2)
{
    printf("\t--Score--\nPlayerA: %d\nPlayerB: %d\n", score1, score2);
}

int ask_which_penguin_to_move(int *pen_x, int *pen_y)
{
    printf("Provide the x and y coordinates of the penguin you want to move:\n");
    scanf("%d", &*pen_y);
    scanf("%d", &*pen_x);
}

void announce_winner(int score1, int score2)
{
    printf("\t--The game has ended--\n");
    if (score1>score2)
        printf("Player A has won!\n");
    else if (score2>score1)
        printf("Player B has won!\n");
    else printf("The game resulted in a draw!\n");
}
int ask_gamemode()
{
    int gamemode;
    printf("Select game mode:\n1 - interactive\n2 - autonomous\n");
    scanf("%d", &gamemode);
    return gamemode;
}
