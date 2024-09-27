#ifndef __INPUTOUTPUT_H
#define __INPUTOUTPUT_H

int ask_number_penguins_and_board_dimensions(int *number_penguins, int *dim_x, int *dim_y);
/*
Asks player number of penguins and board's dimensions

int *dim_x: pointer to rows
int *dim_y: pointer to columns
int *number_penguins: pointer to variable number_penguins
returns number of penguins
*/

void show_board(char** board,int dim_x, int dim_y);
/*
Displays the current board
char** board: array which contains the current board's value
int dim_x: rows dimension
int dim_y: columns dimension
*/

void ask_for_coordinates(int *x, int *y);
/*
Asks player for the coordinates to move the penguin
Stores the horizontal and vertical dimensions of the chosen
field
int *x: pointer to horizontal coordinate
int *y: pointer to vertical coordinate
*/

void show_score(int score1, int score2);
/*
Displays the scorer of each player
int score1:player's 1 scorer
int score2: player's 2 scorer
*/

int ask_which_penguin_to_move(int *pen_x, int *pen_y);
/*
Asks current player the coordinates of the penguin that want to move
Stores the horizonatal and vertical coordinates of the chosen penguin
int *pen_x: pointer to horizontal coordinate
int *pen_y: pointer to vertical coordinate
*/

void announce_winner(int score1, int score2);
/*
Inform the game ended, and depending of the scorers prints the winner
or if there is a draw
int score1: player's 1 scorer
int score2: player's 2 scorer
*/
int ask_gamemode();
/*
asks the player for the game mode

returns the selected game mode
*/
#endif
