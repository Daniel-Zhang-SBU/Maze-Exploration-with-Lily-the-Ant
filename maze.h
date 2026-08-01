#ifndef MAZE_H
#define MAZE_H
#define MAX_ROWS 50                 //max size for the maze
#define MAX_COLS 50
                                    //typedef lets you write the struct name so you dont need to rewrite "struct <name>", only "<name>"
                                    //In this case name is "Maze"
typedef struct                      //struct is a group of variables you can call on later on, so it doesnt look too messy
{
char grid[MAX_ROWS][MAX_COLS];      //50 by 50 maze at most 
int lily_row;                       //lily's position in the maze
int lily_col;     
int score;                          //The score you got 
int rows;                           //Size of maze
int cols;
char direction;
int exit_row;
int exit_col;
} Maze;                             //Maze is the type, When you use this in a .c, write anextra game at the end
                                    //Like this: "Maze game". 


int maze_load(Maze *maze, const char *filename);    //load maze

void maze_print(const Maze *maze);                  //print maze

int move_lily(Maze *maze, char direction);          //move the lily
/*
Notice how "Maze" is cyan colored? That is the code using the struct variables. 
*/
int exit_check(const Maze *maze);


#endif                              

