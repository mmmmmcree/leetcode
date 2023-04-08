# include<stdio.h>
# include<stdlib.h>
/*
执行用时：4 ms, 在所有 C 提交中击败了91.02%的用户
内存消耗：6.6 MB, 在所有 C 提交中击败了67.77%的用户
*/
int maxProfit(int* prices, int pricesSize){
    int max_profit = 0;
    size_t i = 1;
    while (i < pricesSize)
    {
        for (i; i < pricesSize && prices[i - 1] >= prices[i]; i++); 
        for (i; i < pricesSize && prices[i - 1] < prices[i]; i++)
        {
            max_profit += prices[i] - prices[i - 1];
        }
    }
    return max_profit;
}

void main(){
    int prices[5] = {7,6,4,3,1};
    int max_profit = maxProfit(prices, 5);
    printf("%d", max_profit);
}