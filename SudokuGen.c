#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// My idea is to create a 9x9 grid and fill it with randon numbers, checking per each cell if the put value is acceptable.
// After that, deleting K values from the grid randomly, we should have the final product.
// Obv I need to check if the number which is about to be used it is already present inside the smaller 3x3 grid, in the row or in the column 
// Let's say that i is the index for rows and j is the index for columns, for consistency

// 1st: Create the grid
// 2nd: Create all the checks for the numbers that need to be put into the grid (done?)
// 3rd: Insert all the numbers
// 4th: Remove K numbers from the grid


// Definition of the number of rows and columns of the matrix
#define ROWS 9 
#define COLUMNS 9

int mat[ROWS][COLUMNS];
int N = 9;


// Function to check if the number is not used in the row
int NotUsedInRow(int number, int row){
    for(int j=1; j<=COLUMNS; j++){
        if(number == mat[row][j])
            return 0;
    }
    return 1;
}

// Function to check if the number is not used in the column
int NotUsedInColumn(int number, int column){
    for(int i=1; i<=ROWS; i++){
        if(number == mat[i][column])
            return 0;
    }
    return 1;
}

// Function to check if the number is not used in the 3x3 grids
int NotUsedIn3x3Grid(int number, int row, int column){
    // Top-Left Grid
    if(row >= 1 && row <= 3 && column >= 1 && column <= 3){
        for(int i=1; i<=3; i++){
            for(int j=1; j<=3; j++){
                if(number == mat[i][j])
                    return 0;
            }
        }
    }
    // Top-Centre Grid
    if(row >= 1 && row <= 3 && column >= 4 && column <= 6){
        for(int i=1; i<=3; i++){
            for(int j=4; j<=6; j++){
                if(number == mat[i][j])
                    return 0;
            }
        }
    }
    // Top-Right Grid
    if(row >= 1 && row <= 3 && column >= 7 && column <= 9){
        for(int i=1; i<=3; i++){
            for(int j=7; j<=9; j++){
                if(number == mat[i][j])
                    return 0;
            }
        }
    }
    // Centre-Left Grid
    if(row >= 4 && row <= 6 && column >= 1 && column <= 3){
        for(int i=4; i<=6; i++){
            for(int j=1; j<=3; j++){
                if(number == mat[i][j])
                    return 0;
            }
        }
    }
    // Centre Grid
    if(row >= 4 && row <= 6 && column >= 4 && column <= 6){
        for(int i=4; i<=6; i++){
            for(int j=4; j<=6; j++){
                if(number == mat[i][j])
                    return 0;
            }
        }
    }
    // Centre-Right Grid
    if(row >= 4 && row <= 6 && column >= 7 && column <= 9){
        for(int i=4; i<=6; i++){
            for(int j=7; j<=9; j++){
                if(number == mat[i][j])
                    return 0;
            }
        }
    }
    // Bottom-Left Grid
    if(row >= 7 && row <= 9 && column >= 1 && column <= 3){
        for(int i=7; i<=9; i++){
            for(int j=1; j<=3; j++){
                if(number == mat[i][j])
                    return 0;
            }
        }
    }
    //Bottom-Centre Grid
    if(row >= 7 && row <= 9 && column >= 4 && column <= 6){
        for(int i=7; i<=9; i++){
            for(int j=4; j<=6; j++){
                if(number == mat[i][j])
                    return 0;
            }
        }
    }
    // Bottom-Right Grid
    if(row >= 7 && row <= 9 && column >= 7 && column <= 9){
        for(int i=7; i<=9; i++){
            for(int j=7; j<=9; j++){
                if(number == mat[i][j])
                    return 0;
            }
        }
    }
    return 1;
}

// Sum of all the checks
int CheckTOT(int number, int row, int column){
    if(NotUsedInRow(number, row) == 1 && NotUsedInColumn(number, column) == 1 && NotUsedIn3x3Grid(number, row, column) == 1)
        return 1;
    else return 0;
}

// Function to fill the grid
void FillSudoku(){
    srand(time(NULL));
    int number;
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLUMNS; j++){
            int flag = 0;
            while(flag == 0){
                int randNumber = (rand() % 9) + 1;
                if(CheckTOT(randNumber, i, j) == 1) 
                    flag = 1;
            mat[i][j] = randNumber;
            }
        }
    }
    return;
}


int main(void){
    printf("Hello World\n");
    FillSudoku();

    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLUMNS;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}
