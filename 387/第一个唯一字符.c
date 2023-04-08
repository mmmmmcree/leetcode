# include<stdio.h>
# include<stdlib.h>
/*
执行用时：8 ms, 在所有 C 提交中击败了88.40%的用户
内存消耗：6.8 MB, 在所有 C 提交中击败了70.52%的用户
*/
int firstUniqChar(char * s){
    int i = 0, j = 1;
    int table[26] = {0};
    while(s[i] != '\0'){
        if(table[s[i] - 'a']){
            i++;
            j = i + 1;
            continue;
        }
        while(s[j] != '\0' && s[i] != s[j]){
            j++;
        }
        if(s[i] == s[j]){
            table[s[i] - 'a']++;
            i++;
            j = i + 1;
        }
        else{
            return i;
        }
    }
    return -1;
}