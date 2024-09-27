#include "Check.h"

bool check_number_penguins_and_board_dimensions(int number_penguins, int dim_x, int dim_y)
{
    if (number_penguins < 1 || number_penguins > 5 || dim_x < 4 || dim_y < 4 || dim_x > 20 || dim_y > 20)
    {
        printf(" *Incorrect values*\n\n");
        return 0;
    }
    return 1;
}

bool check_board(char **board, int dim_x, int dim_y)
{
    for (int i = 0; i < dim_x; i++)
    {
        for(int j = 0; j< dim_y; j++)
        {
            if(board[i][j]=='1')
                return 1;
        }
    }
}

bool check_any_penguins_left_to_place(int number_penguins, int *penguins_placed)
{
    if(*penguins_placed>=2*number_penguins)
        return 0;
    else
    {
        *penguins_placed+= 1;
        return 1;
    }
}

bool check_placement_coordinates(char** board, int dim_x, int dim_y, int x, int y)
{
    if(x>=dim_x || y>=dim_y || x<0 || y<0 || board[x][y]!='1')
    {
        printf(" *Selected coordinates are invalid for placement*\n\n");
        return 0;
    }
    return 1;
}

bool check_any_valid_moves_left(char** board, int dim_x, int dim_y)
{
    for (int i = 0; i < dim_x; i++)
    {
        for(int j = 0; j< dim_y; j++)
        {
            if(board[i][j]=='A' || board[i][j]=='B')
            {
                if(i!=0)
                    if(board[i-1][j]=='3' || board[i-1][j]=='2' || board[i-1][j]=='1')
                        return 1;
                if(i!=dim_x-1)
                    if(board[i+1][j]=='3' || board[i+1][j]=='2' || board[i+1][j]=='1')
                        return 1;
                if(j!=0)
                    if(board[i][j-1]=='3' || board[i][j-1]=='2' || board[i][j-1]=='1')
                        return 1;
                if(j!=dim_y-1)
                    if(board[i][j+1]=='3' || board[i][j+1]=='2' || board[i][j+1]=='1')
                        return 1;
            }

        }
    }
    return 0;
}

bool check_current_player_has_moves(char** board, int dim_x, int dim_y, int current_player)
{
    char letter;
    if(current_player==1)
        letter = 'A';
    else letter = 'B';
    for (int i = 0; i < dim_x; i++)
    {
        for(int j = 0; j< dim_y; j++)
        {
            if(board[i][j]==letter)
            {
                if(i!=0)
                    if(board[i-1][j]=='3' || board[i-1][j]=='2' || board[i-1][j]=='1')
                        return 1;
                if(i!=dim_x-1)
                    if(board[i+1][j]=='3' || board[i+1][j]=='2' || board[i+1][j]=='1')
                        return 1;
                if(j!=0)
                    if(board[i][j-1]=='3' || board[i][j-1]=='2' || board[i][j-1]=='1')
                        return 1;
                if(j!=dim_y-1)
                    if(board[i][j+1]=='3' || board[i][j+1]=='2' || board[i][j+1]=='1')
                        return 1;
            }

        }
    }
    return 0;
}

bool check_if_penguin_can_move(char** board, int dim_x, int dim_y, int pen_x, int pen_y, int current_player)
{
    char letter;
    if(current_player==1)
        letter = 'A';
    else letter = 'B';
    if(pen_x>dim_x-1 || pen_y > dim_y-1 || pen_x<0 || pen_y<0)
    {
        printf(" *Selected coordinates are out of bounds*\n\n");
        return 0;
    }
    if(board[pen_x][pen_y]==letter)
    {
        if(pen_x!=0)
            if(board[pen_x-1][pen_y]=='3' || board[pen_x-1][pen_y]=='2' || board[pen_x-1][pen_y]=='1')
                return 1;
        if(pen_x!=dim_x-1)
            if(board[pen_x+1][pen_y]=='3' || board[pen_x+1][pen_y]=='2' || board[pen_x+1][pen_y]=='1')
                return 1;
        if(pen_y!=0)
            if(board[pen_x][pen_y-1]=='3' || board[pen_x][pen_y-1]=='2' || board[pen_x][pen_y-1]=='1')
                return 1;
        if(pen_y!=dim_y-1)
            if(board[pen_x][pen_y+1]=='3' || board[pen_x][pen_y+1]=='2' || board[pen_x][pen_y+1]=='1')
                return 1;
    }
    else
    {
        printf(" *Selected coordinates don't contain the current player's penguin*\n\n");
        return 0;
    }
    printf(" *Selected penguin can't move*\n\n");
    return 0;
}

bool check_if_move_is_valid(char** board, int dim_x, int dim_y, int pen_x, int pen_y, int x, int y)
{
    int OK = 1;
    int i, j;
    if(pen_x==x && pen_y==y)
    {
        OK = 0;
    }
    else if(x>dim_x-1 || y > dim_y-1 || x <0 || y<0)
    {
        OK = 0;
    }
    else if(pen_x==x)
    {
        if(y > pen_y)
        {
            j = pen_y+1;
            do
            {
                if(board[pen_x][j] != '1'&& board[pen_x][j] != '2'&& board[pen_x][j] != '3')
                {
                    OK = 0;
                }
                j++;
            }
            while(j<=y && OK == 1);

        }
        else
        {
            j = pen_y-1;
            do
            {
                if(board[pen_x][j] != '1'&& board[pen_x][j] != '2'&& board[pen_x][j] != '3')
                {
                    OK = 0;
                }
                j--;
            }
            while(j>=y && OK == 1);
        }

    }
    else if(pen_y==y)
    {
        if(x > pen_x)
        {
            i = pen_x+1;
            do
            {
                if(board[i][pen_y] != '1' && board[i][pen_y] != '2' && board[i][pen_y] != '3')
                {
                    OK = 0;
                }
                i++;
            }
            while(i<=x && OK == 1);
        }
        else
        {
            i = pen_x-1;
            do
            {
                if(board[i][pen_y] != '1' && board[i][pen_y] != '2' && board[i][pen_y] != '3')
                {
                    OK = 0;
                }
                i--;
            }
            while(i>=x && OK == 1);
        }

    }
    else
    {
        OK =0;
    }
    if(OK==0)
    {
        printf(" *Invalid movement coordinates*\n\n");
        return 0;
    }
    else
    {
        return 1;
    }

}
bool check_gamemode(int gamemode)
{
    if (gamemode==1 || gamemode==2)
    {
        return 1;
    }
    printf(" *Incorrect input - please provide either 1 or 2*\n\n");
    return 0;
}
