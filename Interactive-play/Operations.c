#include <stdio.h>
#include "Operations.h"
#include <stdlib.h>
#include <time.h>

char ** generate_board(int dim_x, int dim_y, int penguins)
{
    int fish;
    int n_floes_1_fish=0;
    srand(time(0));
    char **board= (char**) malloc(dim_x*sizeof(char*));
    do
    {
        for(int i=0; i<dim_x; i++)
        {
            board[i]= (char*) malloc(dim_y*sizeof(char));
        }
        for(int j=0; j<dim_x; j++)
        {
            for(int k=0; k<dim_y; k++)
            {
                fish = rand() % 3;
                if(fish==0)
                {
                    board[j][k] = '1';
                    n_floes_1_fish++;
                }
                else if(fish==1)
                {
                    board[j][k] = '2';
                }
                else
                {
                    board[j][k] = '3';
                }
            }
        }
    }
    while(n_floes_1_fish<penguins);
    return board;
}

void place_penguin(char** board, int x, int y, int current_player)
{
    if(current_player==1)
        board[x][y]= 'A';
    else board[x][y]= 'B';
}

void update_score(int sumPoints, int current_player, int *score1, int *score2)
{
    if(current_player==1)
    {
        if(sumPoints==1)
        {
            *score1= *score1+1;
        }
        else if(sumPoints==2)
        {
            *score1=*score1+2;
        }
        else
        {
            *score1=*score1+3;
        }
    }
    else
    {
        if(sumPoints==1)
        {
            *score2=*score2+1;
        }
        else if(sumPoints==2)
        {
            *score2=*score2+2;
        }
        else
        {
            *score2=*score2+3;
        }
    }
}

void remove_fish_and_delete_floe(char** board, int pen_x, int pen_y)
{
    board[pen_x][pen_y] = ' ';
}

void switch_player(int *current_player)
{
    if (*current_player==1)
    {
        *current_player=2;
        printf("\n Turn of player B\n");
    }
    else
    {
        *current_player=1;
        printf("\n Turn of player A\n");
    };
}

void move_penguin(char** board, int x, int y, int current_player, int *fish)
{
    *fish = board[x][y]-48;
    if (current_player==1)
        board[x][y] = 'A';
    else board[x][y] = 'B';
}

void write_generated_board_to_file(char **board, int dim_x, int dim_y)
{
    FILE* file;
    file = fopen("board.txt","w");
    fprintf(file,"%d %d",dim_x,dim_y);
    fputs("\n",file);
    for (int i = 0; i < dim_x; i++)
    {
        for ( int j = 0; j < dim_y; j++)
        {
            fprintf(file, "%c0 ",board[i][j]);
        }
        fputs("\n",file);

    }
}

