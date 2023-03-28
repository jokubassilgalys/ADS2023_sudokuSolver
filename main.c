#include <stdio.h>
#include "sudokuSolver.h"

int solveGrid(int grid[SIZE][SIZE])
{
    int row, col;
    if(findEmpty(grid, &row, &col) == 0) return 1;

    //printf("0 @ [%d, %d]\n", row, col);

    for(int number = 1; number <= SIZE; ++number){
        if(isValid(grid, row, col, number) == 1){
            //printf("number:%d @ [%d, %d]\n", number, row, col);
            grid[row][col] = number;

            if(solveGrid(grid) == 1) return 1;
            //printf("del %d @ [%d, %d]\n", grid[row][col], row, col);
            grid[row][col] = 0;
        }
    }
    return 0;

}

int main()
{
    int grid[SIZE][SIZE];

    fillGrid(grid);

    printf("Pradinis:\n");
    printGrid(grid);

    printf("\nAtsakymas:\n");
    if(solveGrid(grid) == 1){
        printGrid(grid);
    }
    else{
        printf("Nera sprendimo");
    }

    return 0;
}