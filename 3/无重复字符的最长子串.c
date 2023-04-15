# include<stdio.h>
# include<stdlib.h>
# include<string.h>

int lengthOfLongestSubstring(char * s){
    int left = 0, right = 0, max = 0;
    for(right; right < strlen(s); right++){
        for(int j = left; j < right; j++){
            if(s[right] == s[j]){
                left = j + 1;
                break;
            }
        }
        if(right - left + 1 > max){max = right - left + 1;}
    }
    return max;
}