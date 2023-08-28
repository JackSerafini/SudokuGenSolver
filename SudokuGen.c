#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

// My idea is to create a 9x9 grid and fill it with randon numbers, checking per each cell if the put value is acceptable.
// After that, deleting K values from the grid randomly, we should have the final product.
// Obv I need to check if the number which is about to be used it is already present inside the smaller 3x3 grid, in the row or in the column 
// Let's say that i is the index for rows and j is the index for columns, for consistency

int N = 9; // number of columns and rows
int mat[9][9];


int main(void){
    printf("Hello World\n");

    return 0;
}

// Function to check if the number is not used in the row
bool NotUsedInRow(int number, int row){
    bool check = true;
    for(int j=1; j<=N; j++){
        if(number == mat[row][j])
            check = false;
    }
    return check;
}

// Function to check if the number is not used in the column
bool NotUsedInColumn(int number, int column){
    bool check = true;
    for(int i=1; i<=N; i++){
        if(number == mat[i][column])
            check = false;
    }
    return check;
}

// Function to check if the number is not used in the 3x3 grid
// FOr now I've just added the diagonal grids, even though it sounds strange to me that I'd have to add all nine of them manually
bool NotUsedIn3x3Grid(int number, int row, int column){
    bool check = true;
    if(row >= 1 && row <= 3 && column >= 1 && column <= 3){
        for(int i=1; i<=3; i++){
            for(int j=1; j<=3; j++){
                if(number == mat[i][j])
                    check = false;
            }
        }
    }
    if(row >= 4 && row <= 6 && column >= 4 && column <= 6){
        for(int i=4; i<=6; i++){
            for(int j=4; j<=6; j++){
                if(number == mat[i][j])
                    check = false;
            }
        }
    }
    if(row >= 7 && row <= 9 && column >= 7 && column <= 9){
        for(int i=7; i<=9; i++){
            for(int j=7; j<=9; j++){
                if(number == mat[i][j])
                    check = false;
            }
        }
    }
    return check;
}

// Sum of all the checks
bool CheckTOT(int number, int row, int column){
    if(NotUsedInRow(number, row) == true && NotUsedInColumn(number, column) == true && NotUsedIn3x3Grid(number, row, column) == true)
        return true;
    else return false;
}

// Function to fill the grid
void FillSudoku(int mat){
    int number;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
        }
    }
    return;
}
