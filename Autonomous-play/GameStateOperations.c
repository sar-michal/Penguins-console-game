#include "Struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int Input_player_data(struct read *Game_state, char *player_name, int *number_of_players, char phase)
{
    int i=0;
    int j=0;
    int current_player;
    if(Game_state->player_name[0][0]=='0')
    {
        while(player_name[i]!='\0')
        {
            Game_state->player_name[0][i]=player_name[i];
            i++;
        }
        Game_state->player_number[0]=1;
        Game_state->score[0]=0;
        *number_of_players=1;
        current_player=1;
        return current_player;
    }
    i=0;
    int present_on_list;
    while(player_name[i]!='\0' && j<*number_of_players)
    {
        if(Game_state->player_name[j][i]==player_name[i])
        {
            i++;
        }
        else
        {
            i=0;
            j++;
        }
    }
    if(player_name[i]=='\0')
    {
        present_on_list=1;
        current_player=j+1;
    }
    else
    {
        present_on_list=0;
    }
    i=0;
    if(present_on_list==0)
    {
        if(phase=='m')
        {
            printf(" *Movement phase but player name not present*\n");
            exit(2);
        }
        while(player_name[i]!='\0')
        {
            Game_state->player_name[*number_of_players][i]=player_name[i];
            i++;
        }
        Game_state->score[*number_of_players]=0;
        Game_state->player_number[*number_of_players]=*number_of_players+1;
        *number_of_players=*number_of_players+1;
        current_player=*number_of_players;
    }
    return current_player;
}
void Place_penguin(struct read *Game_state, int number_of_penguins, int current_player)
{
    int number_of_valid_tiles=0;
    int number_of_penguins_placed=0;
    int choice;
    srand(time(0));
    for (int i = 0; i < Game_state->dim_x; i++)
    {
        for(int j = 0; j< Game_state->dim_y; j++)
        {
            if(Game_state->board[i][j][0]=='1')
            {
                number_of_valid_tiles++;
            }
            if(Game_state->board[i][j][1]==current_player+48)
            {
                number_of_penguins_placed++;
            }
        }
    }
    if (number_of_penguins_placed==number_of_penguins)
    {
        exit(1);
    }
    if (number_of_valid_tiles==0)
    {
        printf(" *phase=placement but no valid tiles for placement*\n");
        exit(2);
    }
    choice = (rand() % number_of_valid_tiles)+1;
    number_of_valid_tiles=0;
    for (int i = 0; i < Game_state->dim_x; i++)
    {
        for(int j = 0; j< Game_state->dim_y; j++)
        {
            if(Game_state->board[i][j][0]=='1' && choice==++number_of_valid_tiles)
            {
                Game_state->board[i][j][1]=current_player+48;
                Game_state->board[i][j][0]='0';
            }
        }
    }
    Game_state->score[current_player-1]+=1;
}
void Make_move(struct read *Game_state, int current_player)
{
    int number_of_penguins=0;
    int number_of_valid_penguins=0;
    int choice1;
    int choice2;
    int choice3;
    for (int i = 0; i < Game_state->dim_x; i++)
    {
        for(int j = 0; j< Game_state->dim_y; j++)
        {
            if(Game_state->board[i][j][1]==current_player+48)
            {
                number_of_penguins++;
            }
        }
    }
    if (number_of_penguins==0)
    {
        printf(" *phase=movement but no current player penguins on board*\n");
        exit(2);
    }
    int* valid1 = (int*)calloc(number_of_penguins, sizeof(int));
    int k=0;
    for (int i = 0; i < Game_state->dim_x; i++)
    {
        for(int j = 0; j< Game_state->dim_y; j++)
        {
            if(Game_state->board[i][j][1]==current_player+48)
            {
                if(i!=0)
                    if(Game_state->board[i-1][j][0]=='3' || Game_state->board[i-1][j][0]=='2' || Game_state->board[i-1][j][0]=='1')
                    {
                        valid1[k] = 1;
                        k++;
                        continue;
                    }
                if(i!=Game_state->dim_x-1)
                    if(Game_state->board[i+1][j][0]=='3' || Game_state->board[i+1][j][0]=='2' || Game_state->board[i+1][j][0]=='1')
                    {
                        valid1[k] = 1;
                        k++;
                        continue;
                    }
                if(j!=0)
                    if(Game_state->board[i][j-1][0]=='3' || Game_state->board[i][j-1][0]=='2' || Game_state->board[i][j-1][0]=='1')
                    {
                        valid1[k] = 1;
                        k++;
                        continue;
                    }
                if(j!=Game_state->dim_y-1)
                    if(Game_state->board[i][j+1][0]=='3' || Game_state->board[i][j+1][0]=='2' || Game_state->board[i][j+1][0]=='1')
                    {
                        valid1[k] = 1;
                        k++;
                        continue;
                    }
                k++;
            }
        }
    }
    k=0;
    while(k<number_of_penguins)
    {
        if(valid1[k]==1)
        {
            break;
        }
        k++;
    }
    if (k==number_of_penguins)
    {
        exit(1);
    }

    srand(time(0));
    do
    {
        choice1 = (rand() % number_of_penguins);
    }
    while (valid1[choice1]==0);
    number_of_penguins=0;
    int valid2[4]= {0,0,0,0};
    for (int i = 0; i < Game_state->dim_x; i++)
    {
        for(int j = 0; j< Game_state->dim_y; j++)
        {
            if(Game_state->board[i][j][1]==current_player+48)
            {
                if(i!=0)
                    if(Game_state->board[i-1][j][0]=='3' || Game_state->board[i-1][j][0]=='2' || Game_state->board[i-1][j][0]=='1')
                    {
                        if(number_of_penguins==choice1)
                        {
                            valid2[0]=1;
                        }
                    }
                if(i!=Game_state->dim_x-1)
                    if(Game_state->board[i+1][j][0]=='3' || Game_state->board[i+1][j][0]=='2' || Game_state->board[i+1][j][0]=='1')
                    {
                        if(number_of_penguins==choice1)
                        {
                            valid2[1]=1;;
                        }
                    }
                if(j!=0)
                    if(Game_state->board[i][j-1][0]=='3' || Game_state->board[i][j-1][0]=='2' || Game_state->board[i][j-1][0]=='1')
                    {
                        if(number_of_penguins==choice1)
                        {
                            valid2[2]=1;;
                        }
                    }
                if(j!=Game_state->dim_y-1)
                    if(Game_state->board[i][j+1][0]=='3' || Game_state->board[i][j+1][0]=='2' || Game_state->board[i][j+1][0]=='1')
                    {
                        if(number_of_penguins==choice1)
                        {
                            valid2[3]=1;;
                        }
                    }
                number_of_penguins++;
            }
        }
    }
    srand(time(0));
    do
    {
        choice2 =(rand() % 4);
    }
    while(valid2[choice2]==0);
    number_of_penguins=0;
    k=1;
    for (int i = 0; i < Game_state->dim_x; i++)
    {
        for(int j = 0; j< Game_state->dim_y; j++)
        {
            if(Game_state->board[i][j][1]==current_player+48)
            {
                if(i!=0)
                    if(Game_state->board[i-1][j][0]=='3' || Game_state->board[i-1][j][0]=='2' || Game_state->board[i-1][j][0]=='1')
                    {
                        if(number_of_penguins==choice1)
                        {
                            if(choice2==0)
                            {
                                while(Game_state->board[i-k][j][0]=='3' || Game_state->board[i-k][j][0]=='2' || Game_state->board[i-k][j][0]=='1')
                                {
                                    k++;
                                    if (i-k<0)
                                        break;
                                }
                                k=k-1;
                                choice3=(rand() % k)+1;

                                Game_state->board[i-choice3][j][1]=current_player+48;
                                Game_state->board[i][j][1]='0';
                                Game_state->board[i][j][0]='0';
                                Game_state->score[current_player-1]+=Game_state->board[i-choice3][j][0]-48;
                                Game_state->board[i-choice3][j][0]='0';
                                return;
                            }
                        }
                    }
                if(i!=Game_state->dim_x-1)
                    if(Game_state->board[i+1][j][0]=='3' || Game_state->board[i+1][j][0]=='2' || Game_state->board[i+1][j][0]=='1')
                    {
                        if(number_of_penguins==choice1)
                        {
                            if(choice2==1)
                            {
                                while(Game_state->board[i+k][j][0]=='3' || Game_state->board[i+k][j][0]=='2' || Game_state->board[i+k][j][0]=='1')
                                {
                                    k++;
                                    if (i+k>Game_state->dim_x-1)
                                        break;
                                }
                                k=k-1;
                                choice3=(rand() % k)+1;

                                Game_state->board[i+choice3][j][1]=current_player+48;
                                Game_state->board[i][j][1]='0';
                                Game_state->board[i][j][0]='0';
                                Game_state->score[current_player-1]+=Game_state->board[i+choice3][j][0]-48;
                                Game_state->board[i+choice3][j][0]='0';
                                return;
                            }
                        }
                    }
                if(j!=0)
                    if(Game_state->board[i][j-1][0]=='3' || Game_state->board[i][j-1][0]=='2' || Game_state->board[i][j-1][0]=='1')
                    {
                        if(number_of_penguins==choice1)
                        {
                            if(choice2==2)
                            {
                                while(Game_state->board[i][j-k][0]=='3' || Game_state->board[i][j-k][0]=='2' || Game_state->board[i][j-k][0]=='1')
                                {
                                    k++;
                                    if (j-k<0)
                                        break;
                                }
                                k=k-1;
                                choice3=(rand() % k)+1;

                                Game_state->board[i][j-choice3][1]=current_player+48;
                                Game_state->board[i][j][1]='0';
                                Game_state->board[i][j][0]='0';
                                Game_state->score[current_player-1]+=Game_state->board[i][j-choice3][0]-48;
                                Game_state->board[i][j-choice3][0]='0';
                                return;
                            }
                        }
                    }
                if(j!=Game_state->dim_y-1)
                    if(Game_state->board[i][j+1][0]=='3' || Game_state->board[i][j+1][0]=='2' || Game_state->board[i][j+1][0]=='1')
                    {
                        if(number_of_penguins==choice1)
                        {
                            if(choice2==3)
                            {
                                while(Game_state->board[i][j+k][0]=='3' || Game_state->board[i][j+k][0]=='2' || Game_state->board[i][j+k][0]=='1')
                                {
                                    k++;
                                    if (j+k>Game_state->dim_y-1)
                                        break;
                                }
                                k=k-1;
                                choice3=(rand() % k)+1;

                                Game_state->board[i][j+choice3][1]=current_player+48;
                                Game_state->board[i][j][1]='0';
                                Game_state->board[i][j][0]='0';
                                Game_state->score[current_player-1]+=Game_state->board[i][j+choice3][0]-48;
                                Game_state->board[i][j+choice3][0]='0';
                                return;
                            }
                        }
                    }
                number_of_penguins++;
            }
        }
    }
}
