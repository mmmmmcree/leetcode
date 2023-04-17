int mySqrt(int y){
    if(y == 0){return 0;}
    int left = 1, right = y / 2;
    double mid;
    while(left < right){
        mid = (left + right) / 2 + 1;
        if(mid * mid > y){
            right = mid - 1;
        }
        else{left = mid;}
    }
    return left;
}