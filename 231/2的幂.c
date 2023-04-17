# include<stdio.h>
# include<stdlib.h>

# define bool int

bool isPowerOfTwo(int n){
    return (n > 0) && (!(n & (n - 1)));
}