#include <stdio.h>
#include <stdlib.h>
#include "Struct.h"
#ifndef __FILEINPUTOUTPUT_H
#define __FILEINPUTOUTPUT_H


struct read Read_from_file(char* file_name);
/*
Reads a .txt file, stores the boards value, the size,
the player's id, his number, and his score
Returns a struct containing:
int dim_x: x board's dimension
int dim_y: y board's dimension
int score:  current player's score
char* player_name:    current player's id
int* player_number:  current player's number
char*** board: current board
*/

int check_input_mistakes(int players, int penguins, char phase, struct read Game_state);
/*
Check for possible mistakes in the input .txt file
int players: number of players
int penguins: penguins per player
char phase: 'p' for placement, 'm' for movement
struct read Game_state: struct with board's dimensions and values,
player_id, score and player's number
*/

void WriteToFile(struct read Write, int player_amount, int current_player, char phase, char* file_name);
/*
Writes to file board dimensions, the board with amount of fish/players positioning data, players nicknames,their numbers and scores
struct write Write:
    Write.board = char*** board;
    Write.dim_x = x dimension of the board;
    Write.dim_y = y dimension of the board;
    Write.player_id = player_id;
    Write.score = score;
    Write.number_player = numberofpl;
char*** board - pointer to the 2d array of the board
int dim_x,dim_y - dimensions of the board
char** player_id - pointer to the array of players id's
int* score - pointer to the array of scores of players
int* players_numbers - pointer to the array of players numbers
int player_amount - amount of players in the game
*/
#endif
