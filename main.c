#include <stdio.h>
#include "maze.h"
#include "queue.h"
#include "stack.h"

int main()
{
    Maze game;                          //game gets a copy of the variables in struct, Maze

    maze_load(&game, "maze.txt");       //changes the values of game so it loads the maze.txt

    while(1)
    {
    maze_print(&game);
    printf("Make a move, 'W' up, 'A' left, 'S' down, 'D'down:");
    scanf("%c", game.direction);
    move_lily(&game, game.direction);
        if(check_exit(&game))
        {
            printf("Lily is at the exit! You win!\n");
            break;
        }
    }
    return 0;
}
