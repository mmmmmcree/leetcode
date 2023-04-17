// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    double left = 1, right = n, mid;
    while(left < right){
        mid = (left + right) / 2;
        if(!isBadVersion(mid)){left = mid + 1;}
        else{right = mid;}
    }
    return (int)left;
}