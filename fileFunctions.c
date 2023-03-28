#include <stdio.h>
#include "sudokuSolver.h"

void getFileName(char prompt[], char *fileName)
{
    printf("%s", prompt);
    if (scanf("%s", fileName) != 1){ 
        getFileName("Neteisinga ivestis, iveskite pavadinima is naujo: ", fileName);
    }
}

void printGrid(int grid[SIZE][SIZE])
{
    int colCount = 3;
    int rowCount = 0;

    printf("+------+------+------+\n");
    for(int i = 0; i < 9; ++i){
        if(rowCount == 3){
            printf("|------+------+------|\n"); 
            rowCount = 0;
        }
        ++rowCount;

        for(int j = 0; j < 9; ++j){
            if(colCount == 3){
                printf("|");
                colCount = 0;
            }
            ++colCount;

            printf("%d ", grid[i][j]);  
        }
        printf("|\n");
    }
    printf("+------+------+------+\n");
}

void fillGrid(int grid[SIZE][SIZE])
{
    FILE* inputFile;
    char fileName[255];
    getFileName("Iveskite failo pavadinima: ", fileName);

    for (;;){
        if ((inputFile = fopen(fileName, "r")) == NULL){
            getFileName("Nepavyko atidaryti failo, iveskite pavadinima is naujo: ", fileName);
        }
        else break;
    }
    fflush(stdin);

    int temp;
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            fscanf (inputFile, "%d", &temp);
            grid[i][j] = temp;
        }
    }
    fclose (inputFile); 
}
