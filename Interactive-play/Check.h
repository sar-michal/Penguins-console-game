#include <stdbool.h>
#include <stdio.h>
#ifndef __CHECK_H
#define __CHECK_H

bool check_number_penguins_and_board_dimensions(int number_penguins, int dim_x, int dim_y);
/*
Checks if the number of penguins and board dimensions are correct (within criteria)

int number_penguins - the number of penguins
int dim_x, dim_y - the dimensions of the board

returns either 1 (when correct) or 0 (when incorrect)
*/
bool check_board(char **board, int dim_x, int dim_y);
/*
Checks if the generated board is viable for the game i.e.
if there are enough spots with 1 fish or if the penguins
can still move after placement

char** board - pointer to the board
int dim_x, dim_y - board dimensions previously input by player

returns either 1 (when viable) or 0 (when not viable)
*/
bool check_any_penguins_left_to_place(int number_penguins, int *penguins_placed);
/*
checks if there are any penguins left to place by

int number_penguins - the number of penguins previously input by player
int *penguins_placed - pointer to the current number of penguins placed

returns either 1 (if there are) or 0 (when there aren't)
*/
bool check_placement_coordinates(char** board, int dim_x, int dim_y, int x, int y);
/*
Checks if the given coordinates lead to a viable penguin placement spot
i.e. such a tile should have only 1 fish and not be obstructed by other penguins

char** board - pointer to the board
int dim_x, dim_y - board dimensions previously input by player
int x, y - the coordinates previously input by player

returns either 1 (if the chosen spot is viable) or 0 (when the chosen spot is not viable)
*/
bool check_any_valid_moves_left(char** board, int dim_x, int dim_y);
/*
checks if any penguins of any player can move
returns 1 as soon as it finds a possible move

int dim_x, dim_y - board dimensions previously input by player
char** board - pointer to the board

returns either 1 (when at least 1 penguin can move) or 0 (When no penguins can move)
*/
bool check_current_player_has_moves(char** board, int dim_x, int dim_y, int current_player);
/*
checks if any penguins of the current player can move
returns 1 as soon as it finds a possible move

char** board - pointer to the board
int dim_x, dim_y - board dimensions previously input by player
int current_player - the value of the current player

returns either 1 (when at least 1 penguin can move) or 0 (When no penguins can move)
*/
bool check_if_penguin_can_move(char** board, int dim_x, int dim_y, int pen_x, int pen_y, int current_player);
/*
checks if the selected penguin can make a valid move
i.e. it's not obstructed by other penguins or removed floe

char** board - pointer to the board
int dim_x, dim_y - board dimensions previously input by player
int pen_x, pen_y - coordinates of the penguin

returns either 1 (when it can move) or 0 (when it can't)
*/

bool check_if_move_is_valid(char** board, int dim_x, int dim_y, int pen_x, int pen_y, int x, int y);
/*
checks if the previosuly selected penguin can move to the desired coordinates

char** board - pointer to the board
int dim_x, dim_y - board dimensions previously input by player
int x, y - the coordinates of the move

returns either 1 (when it can move to the coordinates) or 0 (when it can't)
*/
bool check_gamemode(int gamemode);
/*
checks if the provided gamemode value is correct

int gamemode - the chosen game mode

returns either 1 (when correct) or 0 (when incorrect)
*/
#endif
