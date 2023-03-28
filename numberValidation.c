#include <stdio.h>
#include "sudokuSolver.h"

int findEmpty(int grid[SIZE][SIZE], int *row, int *col)
{
    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
            if(grid[i][j] == 0){
                *row = i;
                *col = j;

                return 1;
            }
        }
    }
    return 0;
}

int isValidInRow(int grid[SIZE][SIZE], int row, int number)
{
    for (int i = 0; i < SIZE; ++i){
        if (grid[row][i] == number) return 0;
    }
    return 1;
}

int isValidInCol(int grid[SIZE][SIZE], int col, int number)
{
    for (int i = 0; i < SIZE; ++i){
        if (grid[i][col] == number) return 0;
    }
    return 1;
}

int isValidInSquare(int grid[SIZE][SIZE], int row, int col, int number)
{
    int squareStartX = row - (row % 3);
    int squareStartY = col - (col % 3);

    for (int x = 0; x < 3; x++){
        for (int y = 0; y < 3; y++){
            if (grid[squareStartX + x][squareStartY + y] == number) return 0;
        }
    }
    return 1;
}

int isValid(int grid[SIZE][SIZE], int row, int col, int number)
{
    if(isValidInRow(grid, row, number) &&
        isValidInCol(grid, col, number) &&
        isValidInSquare(grid, row, col, number)
    ) return 1;
    else return 0;
}
