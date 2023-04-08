# include<stdio.h>
# include<stdlib.h>
# include<math.h>

int maxProfit(int* prices, int pricesSize) {
    int ans = 0;
    for (int i = 1; i < pricesSize; i++) {
        ans += fmax(0, prices[i] - prices[i - 1]);
    }
    return ans;
}

void main(){
    int prices[5] = {7,6,4,3,1};
    int max_profit = maxProfit(prices, 5);
    printf("%d", max_profit);
}