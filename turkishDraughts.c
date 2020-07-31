#include <stdio.h>

#define BOARDSIZE 8

typedef enum {white_man, black_man, white_king, black_king, empty} piece;
typedef enum {white = 10, black = 20} player;

void init_board(piece board[][BOARDSIZE]);
int move(piece board[][BOARDSIZE], int from_x, int from_y, int to_x, int to_y, player p);
int check_end_of_game(piece board[][BOARDSIZE]);
void display_board(piece board[][BOARDSIZE]);
void game(piece board[][BOARDSIZE]);

int main(){
	
	piece board[BOARDSIZE][BOARDSIZE];

	game(board);

	return 0;
}

void init_board(piece board[][BOARDSIZE]){

	int i,j;	

	piece temp_board[BOARDSIZE][BOARDSIZE] = { {empty,empty,empty,empty,empty,empty,empty,empty},
					     {black_man,black_man,black_man,black_man,black_man,black_man,black_man,black_man},
						 {black_man,black_man,black_man,black_man,black_man,black_man,black_man,black_man},
						 {empty,empty,empty,empty,empty,empty,empty,empty},
						 {empty,empty,empty,empty,empty,empty,empty,empty},
						 {white_man,white_man,white_man,white_man,white_man,white_man,white_man,white_man},
						 {white_man,white_man,white_man,white_man,white_man,white_man,white_man,white_man},
						 {empty,empty,empty,empty,empty,empty,empty,empty} };

	for(i=0; i<BOARDSIZE; i++){

		for(j=0; j<BOARDSIZE; j++){

			board[i][j] = temp_board[i][j];
			
		}
	}				
}

int move(piece board[][BOARDSIZE], int from_x, int from_y, int to_x, int to_y, player p){

	if(p == white){

		if(board[from_x][from_y] == black_man || board[from_x][from_y] == black_king)   /* control right piece */
			return -1; 

		else if(board[to_x][to_y] != empty)     /* control valid move */
			return -2;

		else {
			board[to_x][to_y] = board[from_x][from_y];   // move is successfull
			board[from_x][from_y] = empty;
			return 1;   
		}		

	}
	if(p == black){

		if(board[from_x][from_y] == white_man || board[from_x][from_y] == white_king)
			return -1; 

		else if(board[to_x][to_y] != empty)
			return -2;
		
		else{
			board[to_x][to_y] = board[from_x][from_y];   // move is successfull
			board[from_x][from_y] = empty;
			return 1;
		}	
	}
}

int check_end_of_game(piece board[][BOARDSIZE]){

	int i,j;
	int count_white_man;
	int count_black_man;
	int count_white_king;
	int count_black_king;

	count_white_man = 0;
	count_black_man = 0;
	count_white_king = 0;
	count_black_king = 0;

	for(i=0; i<BOARDSIZE; i++){

		for(j=0; j<BOARDSIZE; j++){

			if(board[i][j] == white_man)
				count_white_man++;
			else if(board[i][j] == black_man)
				count_black_man++;
			else if(board[i][j] == white_king)
				count_white_king++;
			else if(board[i][j] == black_king)
				count_black_king++;
		}
	}

	if(count_white_man == 0 && count_white_king == 0)
		return black;   // black wins
	else if(count_black_man == 0 && count_black_king == 0)
		return white;   // white wins
	else
		return -1;     /* game continues */
	
}

void display_board(piece board[][BOARDSIZE]){

	int i,j;

	for(i=0; i<BOARDSIZE; i++){

		for(j=0; j<BOARDSIZE; j++){

			if(board[i][j] == empty)
				printf("-");
			else if(board[i][j] == black_man)
				printf("b");
			else if(board[i][j] == white_man)
				printf("w");
			else if(board[i][j] == black_king)
				printf("B");
			else if(board[i][j] == white_king)
				printf("W");
		}
		printf("\n");

	}

	printf("\n");

}

void game(piece board[][BOARDSIZE]){

	int winner=0;

	int turn = 0;  // 0 is white, 1 is black

	int to_x, to_y;
	int from_x, from_y;

	int whitePieceCount = BOARDSIZE*2;
	int blackPieceCount = BOARDSIZE*2;

	player p;


	init_board(board);
	display_board(board);


	do{

		printf("From where?\n");
		scanf("%d%d", &from_x, &from_y);

		if(from_x < 0 || from_y < 0 || from_x > BOARDSIZE || from_y > BOARDSIZE){
			printf("Invalid move!\n");
			return ; 
		}
		

		if(board[from_x][from_y] == white_man || board[from_x][from_y] == white_king )
			p = white;
		else if(board[from_x][from_y] == black_man || board[from_x][from_y] == black_king )
			p = black;    

		if(!((turn % 2 == 0 && p == white) || (turn % 2 == 1 && p == black))) { 
			printf("Move is on opponent!\n\n");
		}

		else {

			printf("To where?\n");
			scanf("%d%d", &to_x, &to_y);
				
			if(to_x<0 || to_y<0 || to_x > BOARDSIZE || to_y > BOARDSIZE){
				printf("Invalid move!\n");
				return ;
			}
		
		
			move(board, from_x, from_y, to_x, to_y, p);
			display_board(board);


			
				
			turn++;
		
		}

		winner = check_end_of_game(board);  // -1 for game continue, white for white wins, black for black wins

	} while( winner  == -1);
	
		if(winner == white)
			printf("Winner : White\n");
		if(winner == black)
			printf("Winner : Black\n");

}

