#include <stdio.h>
#include <string.h>
#include "maze.h"

int maze_load(Maze *maze, const char *filename)    //load maze, Maze *maze is a pointer to a Maze struct. Use maze->variable to access the variables inside that struct.
{
    char line[100];
    FILE *fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("Unable to open maze.txt");
        return 1;                                   //failure
    }

    maze->rows = 0;                                 // Go to the Maze struct that maze points to, find the variable rows, and set it to 0."
    
    while(fgets(line, sizeof(line), fp) != NULL)        //save the maze to grid that is inside struct 
    {
        line[strcspn(line, "\n")] = '\0';               //check for the null character position(strcspn) and replace it with '\0'
        strcpy(maze->grid[maze->rows], line);            //change the struct pointer to grid, address count, and string copy line into it

        for(int i = 0; i < line[i] != '\0'; i++)           //save positions of lily and the exit
        {
            if(line[i] == 'L')
            {
                maze->lily_row = maze->rows;
                maze->lily_col = i;
            }
            if(line[i] == 'E')
            {
                maze->exit_row = maze->rows;
                maze->exit_col = i;
            }
        }

        (maze->rows)++;                                 //increment rows
    }

    fclose(fp);
    return 0;                                       //success
}


void maze_print(const Maze *maze)                  //print maze, the actaul maze is in the struct grid
{
    for(int i = 0; i < (maze->rows); i++)
    {
        for(int j = 0; maze->grid[i][j] != '\0'; j++)        //print the rows 
        {
            printf("%c", maze->grid[i][j]);
        }
        printf("\n");
    }
}


int move_lily(Maze *maze, char direction)          //move the lily
{
    int new_row = maze->lily_row;
    int new_col = maze->lily_col;

    if(direction == 'W')
    {
        new_row--;
    }
    else if(direction == 'A')
    {
        new_col--;
    }
    else if(direction == 'S')
    {
        new_row++;
    }
    else if(direction == 'D')
    {
        new_col++;
    }
                                                        //reject the move if lily is is bumping into the wall or out of bounds
    if(new_row < 0 || new_row >= maze->rows || 
       new_col < 0 || new_col >= maze->cols || 
       maze->grid[new_row][new_col] == '#' )
    {
        printf("Invalid move\n");
        return 1;
    }
    maze->grid[maze->lily_row][maze->lily_col] = '.';       //remove old location of lily
    maze->lily_row = new_row;
    maze->lily_col = new_col;
    maze->grid[maze->lily_row][maze->lily_col] = 'L';       //update with new position of lily
    return 0;
}

int exit_check(const Maze *maze)
{
    if((maze->lily_row == maze->exit_row) && (maze->lily_col == maze->exit_col))
    {
        return 1;
    }
    return 0;
}