# include<stdio.h>
# include<stdlib.h>
# include<string.h>
// 我写的, 20ms, 不知道为啥这么慢
int lengthOfLongestSubstring(char * s){
    int left = 0, right = 0, max = 0;
    int freq[128] = {0};
    for(right; right < strlen(s); right++){
        if(freq[s[right]] && freq[s[right]] > left){
            left = freq[s[right]];
            freq[s[right]] = 0;
        }
        freq[s[right]] = right + 1;
        if(right - left + 1 > max){max = right - left + 1;}
    }
    return max;
}
// 示例代码, 0ms
int lengthOfLongestSubstring(char * s){
    int len = strlen(s);
    int ans = 0;
    int start = 0, end = 0;
    int freq[128] = {0};
    while (start < len && end < len) {
        if (freq[s[end]] == 0) {
            freq[s[end++]]++;
            ans = ans > end - start ? ans : end - start;
        } else {
            freq[s[start++]]--;
        }
    }
    return ans;
}