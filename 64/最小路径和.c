# include<stdio.h>
# include<stdlib.h>

int _min(int a, int b){
    return a > b? b: a;
}

int minPathSum(int** grid, int gridSize, int* gridColSize){
    int i = 0, j = 0;
    for(i; i < gridSize; i++){
        for(j = 0; j < gridColSize[i]; j++){
            if(i == 0 && j == 0);
            else if(i == 0){
                grid[i][j] += grid[i][j - 1];
            }
            else if(j == 0){
                grid[i][j] += grid[i - 1][j];
            }
            else{
                grid[i][j] += _min(grid[i][j - 1], grid[i - 1][j]);
            }
        }
    }
    return grid[i-1][j-1];
}