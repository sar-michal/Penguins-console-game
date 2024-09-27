#ifndef __GAMESTATEOPERATIONS_H
#define __GAMESTATEOPERATIONS_H
int Input_player_data(struct read *Game_state, char *player_name, int *number_of_players, char phase);
/*
Checks if Game data needs player information (player name, score, player number). If yes - provides it and updates the number of players
Checks if Game data aligns with the phase of the game
Calculates the number of the current player

struct read *Game_state - all data acquired from the file
char *player_name - Program's internal player name
int *number_of_players - the number of players
char phase - current phase of the game

returns the number of the current player
*/

void Place_penguin(struct read *Game_state, int number_of_penguins, int current_player);
/*
Responsible for placing penguins when phase=placement

struct read *Game_state - all Game state data
int number_of_penguins - the number of penguins
int current_player - number of the current player
*/

void Make_move(struct read *Game_state, int current_player);
/*
Responsible for penguin movement when phase=movement

struct read *Game_state - all Game state data
int current_player - number of the current player
*/

#endif
