# include<stdio.h>
# include<stdlib.h>
/*
执行用时：4 ms, 在所有 C 提交中击败了52.15%的用户
内存消耗：5.5 MB, 在所有 C 提交中击败了95.02%的用户
*/
char * longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize == 1)
        return *strs;  // 出错点1：只传入一个字符串
    size_t index = 0;
    while (1)
    {
        size_t i = 0;
        for (i ; i < strsSize - 1 && *(strs[i] + index)!= '\0' && *(strs[i] + index) == *(strs[i + 1] + index); i++);
        // 出错点2：*(strs[i] + index)!= '\0'，解决字符串全部相等，出现'\0' == '\0'导致index递增的情况
        if (i == strsSize - 1)
            ++index;
        else
            break;
    }
    char *longest = (char*)malloc(sizeof(char) * (index + 1));
    for (size_t i = 0; i < index; i++)
    {
        longest[i] = *(strs[0] + i);
    }
    longest[index] = '\0';
    return longest;
}

void main(){
    char *longest;
    char *strs[5] = {"flower","flower"};
    int strsSize = 2;
    longest = longestCommonPrefix(strs, strsSize);
    puts(longest);
    
}