#define SIZE 9
#ifndef HEADER_FILE
#define HEADER_FILE
    void getFileName(char prompt[], char *fileName);
    void printGrid(int grid[SIZE][SIZE]);
    void fillGrid(int grid[SIZE][SIZE]);
    int findEmpty(int grid[SIZE][SIZE], int *row, int *col);
    int isValidInRow(int grid[SIZE][SIZE], int row, int number);
    int isValidInCol(int grid[SIZE][SIZE], int col, int number);
    int isValidInSquare(int grid[SIZE][SIZE], int row, int col, int number);
    int isValid(int grid[SIZE][SIZE], int row, int col, int number);
#endif