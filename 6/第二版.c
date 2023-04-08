# include<stdio.h>
# include<stdlib.h>
# include<string.h>
/*
执行用时：4 ms, 在所有 C 提交中击败了88.58%的用户
内存消耗：13.3 MB, 在所有 C 提交中击败了26.36%的用户
*/
// 将字符串数组改为一条字符串
char * convert(char * s, int numRows){
    if (numRows == 1)
        return s;
   
    size_t len = strlen(s),
    row_1_skip = numRows * 2 - 2,
    loop = len / row_1_skip,
    cols = loop * (numRows - 1),
    left = len % row_1_skip;
    if (left > 0)
    {
        cols += 1;
        loop += 1;
        if (left > numRows)
        {
            cols += left - numRows;
        }
    }
    char *string = (char*)malloc(numRows * cols);
    memset(string, '0', numRows * cols);
    
    for (size_t cnt = 0, index = 0; cnt < loop; cnt++)
    {
        size_t i = 0, start_col = cnt * (numRows - 1);
        for (i; index < len && i < numRows; i++)
        {
            string[i * cols + start_col] = s[index++];
        }
        for (i; index < len && i < row_1_skip; i++)
        {
            int t = 2 * numRows -i - 2;
            string[t * cols + numRows - 1 - t + start_col] = s[index++];
        }
    }
    
    char *res = (char*)malloc(sizeof(char) * (len + 1));
    res[len] = '\0';
    for (size_t i = 0, index = 0; i < numRows * cols; i++)
    {
        if (string[i] != '0')
        {
            res[index++] = string[i];
        }
    }
    return res;
}

void main(){
    char *s = "PAYPALISHIRING";
    char * res = convert(s, 4);
    puts(res);
}