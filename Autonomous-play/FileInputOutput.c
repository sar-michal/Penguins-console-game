#include <stdio.h>
#include <stdlib.h>
#include "Struct.h"
#include "FileInputOutput.h"
#include <string.h>

struct read Read_from_file(char* file_name)
{
    printf("reading\n");
    char character;
    int i=0;
    int j=0;
    struct read Game_state;
    FILE* inputboard = fopen(file_name, "r");

    if(inputboard == NULL)
    {
        printf("FILE NOT FOUND");
        exit(3);
    }

    fscanf(inputboard,"%d",&Game_state.dim_x);
    fscanf(inputboard,"%d",&Game_state.dim_y);
    //printf("%d %d\n", Game_state.dim_x, Game_state.dim_y);
    do
    {
        character = fgetc(inputboard);
    }
    while(character==' ');

    Game_state.board= (char***) malloc(Game_state.dim_x*sizeof(char**));
    for(int k=0; k<Game_state.dim_x; k++)
    {
        Game_state.board[k]= (char**) malloc(Game_state.dim_y*sizeof(char*));
        for(int r = 0; r<Game_state.dim_y; r++)
        {
            Game_state.board[k][r] = (char*) malloc(2*sizeof(char));
        }
    }
    Game_state.player_name=(char**) malloc(9*sizeof(char*));
    for(int f = 0; f < 9; f++)
    {
        Game_state.player_name[f]=(char*)malloc(25*sizeof(char));
    }
    Game_state.player_number=(int*)malloc(9*sizeof(int));
    Game_state.score=(int*)malloc(9*sizeof(int));

    while(i<Game_state.dim_x)
    {
        character = fgetc(inputboard);
        while(character!='\n' && character != EOF)
        {
            Game_state.board[i][j][0] = character;
            Game_state.board[i][j][1] = fgetc(inputboard);
            //printf("%c%c ", Game_state.board[i][j][0], Game_state.board[i][j][1]);
            do
            {
                character = fgetc(inputboard);
            }
            while(character==' ');
            j++;
        }
        j=0;
        //printf("\n");
        i++;
    }
    i=0;
    char buffer[200];
    if (character == EOF || !fgets(buffer, 200, inputboard))
    {
        Game_state.player_name[0][0]='0';
        return (Game_state);
    }
    while(!feof(inputboard))
    {
        sscanf(buffer, "%s %d %d", Game_state.player_name[i], &Game_state.player_number[i], &Game_state.score[i]);
        //printf("%s %d %d\n", Game_state.player_name[i], Game_state.player_number[i], Game_state.score[i]);
        i++;
        fgets(buffer, 200, inputboard);
    }
    char check[25];
    sscanf(buffer, "%s ", &check);
    if(i==0 || strcmp(check, Game_state.player_name[i-1])!=0)
    {
        sscanf(buffer, "%s %d %d", Game_state.player_name[i], &Game_state.player_number[i], &Game_state.score[i]);
        //printf("%s %d %d\n", Game_state.player_name[i], Game_state.player_number[i], Game_state.score[i]);
    }
    printf("Done\n");
    return (Game_state);
}

int check_input_mistakes(int number_of_players, int number_of_penguins, char phase, struct read Game_state)
{
    /*phase: p for placement, m for movement*/
    int *pen = (int*)calloc(number_of_players, sizeof(int));

    for (int i = 0; i<Game_state.dim_x; i++)
    {
        for(int j = 0; j<Game_state.dim_y; j++)
        {
            if(Game_state.board[i][j][1]!='0')
            {
                if(Game_state.board[i][j][1]-48 > number_of_players || Game_state.board[i][j][1]<48)
                {
                    printf("Detected an incorrect player number on board");
                    return(2);
                }
                pen[Game_state.board[i][j][1]-48]+=1;
            }
            if(Game_state.board [i][j][0]>51)
            {
                printf("Detected more than three fish in a tile");
                return(2);
            }
        }
    }
    if(phase=='p')
    {
        for(int k = 0; k<number_of_players; k++)
        {
            if(pen[k]>number_of_penguins)
            {
                printf("A player exceeds the maximum number of penguins for phase=placement");
                return(2);
            }
            if(Game_state.score[k] > number_of_penguins)
            {
                printf("A player exceeds the maximum number of points for phase=placement");
                return(2);
            }
            if(Game_state.score[k]<0)
            {
                printf("There is a negative score");
                return 2;
            }
            if(Game_state.player_number[k]<0 || Game_state.player_number[k]>number_of_players)
            {
                printf("Detected an incorrect player number in the player list");
                return 2;
            }
        }
    }
    free(pen);
}
void WriteToFile(struct read Write, int player_amount, int current_player, char phase, char* file_name)
{
    FILE* file;
    file = fopen(file_name,"w");
    fprintf(file,"%d %d",Write.dim_x,Write.dim_y);
    fputs("\n",file);
    for(int r = 0; r < Write.dim_x; r++)
    {
        for(int c = 0; c < Write.dim_y; c++)
        {
            fprintf(file,"%c%c ", Write.board[r][c][0],Write.board[r][c][1]);
        }
        fprintf(file,"\n");
    }
    for (int i = 0; i < player_amount; i++)
    {
        fprintf(file,"%s %d %d\n", Write.player_name[i], Write.player_number[i], Write.score[i]);
    }
}
