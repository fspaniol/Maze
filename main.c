#include <stdio.h>
#include <stdlib.h>

#include "maze.h"

int main(int argc, char *argv[]) {
  Direction dir[13]={EAST, NORTH, EAST, SOUTH, EAST, NORTH, UP, WEST ,WEST, NORTH, NORTH, DOWN, SOUTH};
  Maze maze;
  readMazeFromFile(&maze, "maze3D.txt");
    printMaze(maze);
    printPossibleMoves(maze);
    printf("The goal is at: ");
    printPositionWithNewline(maze.goal);
    
    
    
    for (int i = 0; i<13; i++)
    {
        makeMove(&maze, dir[i]);
        printMaze(maze);
        if (isSolved(maze) == 1)
        {
            printf ("\n\n\nYOU DID IT\n\n\n");
            printf("The final cost is: %d \n", maze.cost);
            printPathWithNewline(maze.path);
        }
        else
        {
            printPossibleMoves(maze);
            printf("Current cost is: %d \n", maze.cost);
        }
    }

  return EXIT_SUCCESS;
}
