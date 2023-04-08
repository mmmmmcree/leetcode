# include<stdio.h>
# include<stdlib.h>
/*
执行用时：0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗：5.2 MB, 在所有 C 提交中击败了94.41%的用户
*/

//  还可以转化为递推问题，递推问题可以用矩阵求解，矩阵可化为对角阵，再次简化运算
double C(int i, int n){
    double up = 1, down = 1;
    for(int j = n; j > n - i; j--){
        up *= j;
    }
    for(i; i > 0; i--){
        down *= i;
    }
    return up / down;
}

int climbStairs(int n){
    int total = 1, two_steps = n /2;
    for(int i = 1; i <= two_steps; i++){
        total += C(i, n - i);
    }
    return (int)total;
}

void main(){
    printf("%d", climbStairs(4));
}