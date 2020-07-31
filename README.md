# Turkish Draughts Board Game


## Description

This is a 8x8 board game which played with 16 black pieces and 16 white pieces. 

## Game rules

1) There is a 8x8 board.
2) Each player starts with 16 men (white and black) placed on all the squares of the second and third rows. All the squares are used.
3) Mens moves: They move one square horizontally or vertically forwards, never backwards 
4) Kings moves: They move and jump vertically and horizontally any number of squares 
5) A man captures by jumping to a vacant square in the moveable direction (rule 3) beyond a piece of the opponent.
6) A king captures by jumping to a vacant square beyond an adverse piece, any distance away.
7) Maximum capture compulsory: If there are two or more different chances to make capture, it is compulsory to make the move that captures the maximum amount of the opponents pieces.
8) Taking away the captured pieces: Captured pieces are taken away from the board.
9) If a player has no legal move he loses the game. This may come about either by being eliminated or being blocked completely – no moves left. 



### Executing program

* Type below in your terminal
```
gcc turkishDraughts.c -o game
```
* And then type
```
./game
```

## Authors

Zehra Merve Gül


## Version History

* 0.1
    * Initial Release
