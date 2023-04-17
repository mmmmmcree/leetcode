# define INFINITY 2147483647

int cmp (const void * a, const void * b){
   return *(int*)a > *(int*)b;
}

int findRadius(int* houses, int housesSize, int* heaters, int heatersSize){
    qsort(houses, housesSize, sizeof(int), cmp);
    qsort(heaters, heatersSize, sizeof(int), cmp);
    int r = 0;
    for(int i = 0, k = 0; i < housesSize; i++){
        int min = INFINITY;
        for(int j = k; j < heatersSize; j++){
            int current_r = fabs(heaters[j] - houses[i]);
            if(current_r <= min){min = current_r;}
            else{
                k = j - 1;
                break;
            }
        }
        if(min > r){r = min;}
    }
    return r;
}