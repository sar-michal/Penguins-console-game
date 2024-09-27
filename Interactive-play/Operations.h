#ifndef __OPERATIONS_H
#define __OPERATIONS_H

char ** generate_board(int dim_x, int dim_y, int penguins);
/*
Creates a 2d array and randomly fills it with values up to 3 according to guidelines based on the number of penguins and board dimensions

Int dim_x - number of rows previously input by player
Int dim_y - number of columns previously input by player
Int penguins - number of penguins previously input by player

Returns the created board
*/
void update_score(int sumPoints, int current_player, int *score1, int *score2);
/*
Updates the value of one player's scorer depending on wich one is selected
in 1, 2 or 3 points
int sumPoints: parameter which indicates how many points do we have to sum to the scorer
int *score1: pointer to player's 1 scorer
int *score2: pointer to player's 2 scorer
*/

void place_penguin(char** board, int x, int y, int current_player);
/*
If current player==1, changes value of the floe with x,y coordinates to "A".
If current player==2, changes value of the floe with x,y coordinates to "B"

char** board - pointer to the pointer to the board
int x,y - x,y coordinates of the penguin
current player - number of the current player
*/

void remove_fish_and_delete_floe(char** board, int pen_x, int pen_y);
/*
Floe value chnages to " "
char** board - pointer to the pointer to the board
pen_y,pen_x - y/x coordinates of the floe we want to delete
*/


void switch_player(int *current_player);
/*
changes the player who makes the move
int *current_player - pointer to the number of the current player
*/


void move_penguin(char** board, int x, int y, int current_player, int *fish);
/*
Moves chosen penguin from old x,y coordinates to new_x,new_y coordinates provided by the player and saves amount of the fish of the new floe.
char** board - pointer to the pointer to the board
int x, y - coordinates for movement
int current_player - the current player
*fish - pointer to the amount of the fish on the floe
*/
void write_generated_board_to_file(char **board, int dim_x, int dim_y);
/*
Writes the generated board to a text file

char** board - pointer to the board
dim_x,dim_y - row,column dimensions of the board
*/
#endif
