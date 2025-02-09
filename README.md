# Penguins Console Game

A group project made for the purpose of a university course. I took on the role of the leader of the 3 person group.

The interactive mode works as an in-person board game where each player takes turns.  
The autonomous mode was made for the purpose of gameplay between two programs.

## Table of Contents

- [Game Instructions](#game-instructions)
- [Building the Project](#building-the-project)
- [Running the Game](#running-the-game)
- [Autonomous Play File Format](#autonomous-play-file-format)

## Game Instructions

1. This is a simplified version of a board game “Hey, that’s my fish!".
2. The game is played in turns - in each turn each player moves one penguin. The aim is to collect the most fish.
3. The game board is arranged in a square grid with m rows and n columns. Each field of the grid can be empty or can have an ice floe with 1, 2, or 3 fish on it.
4. Each game is played on a new, possibly randomly generated, board. Each player has a certain (known) number of penguins.
5. There are two phases of the game:
   - **Placing the penguins**:
     - In a single turn, the player places one of his penguins on an unoccupied ice floe with exactly one fish on it.
     - When placing the penguin, the fish on the target ice floe is collected by the player and removed from the ice floe. This way the ice floe with a penguin does not have any fish.
     - The move is compulsory.
     - The placing phase ends when all the penguins are placed on the game board.
   - **Playing the game**:
     - In his turn, the player chooses one of his penguins and moves it in a straight line (only along the grid lines) to another unoccupied ice floe. The previous ice floe is removed from the board. The move over the field without ice floe or over another penguin is forbidden. When placing the penguin, the fish on the target ice floe is collected by the player and removed from the ice floe, immediately.
     - If possible, the move is compulsory.
     - The game ends when no penguin can make a move.
6. The player who collects the most fish wins.

## Building the Project

You can build the project manually using the following command:

```sh
gcc -o Interactive-play/main.exe Interactive-play/main.c
gcc -o Autonomous-play/main.exe Autonomous-play/main.c
```
## Running the game

### Interactive mode
To run the game in interactive mode, execute the following command:

```sh
./Interactive-play/main.exe
```
Then you will be met with prompts concerning the setup.
#### Example setup phase
```sh 
Select game mode:
1 - interactive
2 - autonomous
1
Input number of penguins between 1 and 5 
1
Input coordinates for x and y dimensions between 4 and 20
5 5

        --Placement Phase--

 Turn of player A

  X 0  1  2  3  4
Y   -  -  -  -  -
0 | 3  1  1  2  3 |
1 | 1  3  2  1  3 |
2 | 3  3  2  2  2 |
3 | 3  2  3  2  1 |
4 | 1  1  1  2  2 |
    -  -  -  -  -

Provide the x and y coordinates:
1 0

 Turn of player B

  X 0  1  2  3  4
Y   -  -  -  -  -
0 | 3  A  1  2  3 |
1 | 1  3  2  1  3 |
2 | 3  3  2  2  2 |
3 | 3  2  3  2  1 |
4 | 1  1  1  2  2 |
    -  -  -  -  -

Provide the x and y coordinates:
1 4

        --Movement Phase--


 Turn of player A

  X 0  1  2  3  4
Y   -  -  -  -  -
0 | 3  A  1  2  3 |
1 | 1  3  2  1  3 |
2 | 3  3  2  2  2 |
3 | 3  2  3  2  1 |
4 | 1  B  1  2  2 |
    -  -  -  -  -
```
Each player then takes their turn according to the rules of the game.

### Autonomous mode
To run the game in autonomous mode, execute the following command:
```sh
./Autonomous-play/main.exe phase=placement penguins=1 Autonomous-play/board.txt Autonomous-play/board.txt
./Autonomous-play/main.exe phase=movement Autonomous-play/board.txt Autonomous-play/board.txt
```
The number of penguins should be specified according to the game setup. The correscponding commands may be run in loop for each computer algorithm.

## Autonomous Play File Format

The text file format describing the state of the game:

- **Row 1 (board dimension)**: `m n`
- **Rows 2 to m+1**: `n` fields separated by single spaces, each field consists of 2 digits: the first digit represents the number of fish (0-3), the second digit represents the player’s number (1 to at most 9 players, or 0 if the tile is unoccupied). A combination of numbers `00` represents the grid field without the ice floe.
- **Row m+2 and consecutive**: 3 fields separated by single spaces: the first field is the player ID (string of any length, without spaces, without quotation marks), the second field is the player’s number (1 to 9), the third field shows the number of fish collected so far (the score).

### Example board
```sh
5 5
20 10 30 20 10 
20 10 10 20 10 
30 30 10 30 10 
30 20 30 30 20 
30 30 10 30 10 
```
After execution of
```sh
./Autonomous-play/main.exe phase=placement penguins=1 Autonomous-play/board.txt Autonomous-play/board.txt
```
the resulting board is:
```sh
5 5
20 10 30 20 10 
20 10 10 20 10 
30 30 01 30 10 
30 20 30 30 20 
30 30 10 30 10 
Team-E 1 1
```