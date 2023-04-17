# include<stdio.h>
# include<stdlib.h>
# include<string.h>

int* findAnagrams(char * s, char * p, int* returnSize){
    int len_s = strlen(s), len_p = strlen(p) ,left = 0, right = 0, b[128];
    memset(b, -1, sizeof(int) * 128);
    int *res = (int*)malloc(sizeof(int) * len_s);
    *returnSize = 0;
    for(int i = 0; i < len_p; i++){
        if(b[p[i]] == -1){b[p[i]] = 0;}
        b[p[i]]++;
    }
    for(right; right < len_s; right++){
        if(b[s[right]] < 0){
            left = right + 1;
            for(int i = 0; i < len_p; i++){if(b[p[i]] > 0){b[p[i]] = 0;}}
            for(int i = 0; i < len_p; i++){b[p[i]]++;}
        }
        else if(b[s[right]] == 0){
            b[s[left++]]++;
            right--;
        }
        else{b[s[right]]--;}
        if(right - left + 1 == len_p){
            res[(*returnSize)++] = left;
            b[s[left++]]++;
        }
    }
    return res;
}