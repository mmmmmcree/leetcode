# include<stdio.h>
# include<stdlib.h>
# include<string.h>
/*
执行用时：32 ms, 在所有 C 提交中击败了46.41%的用户
内存消耗：15.8 MB, 在所有 C 提交中击败了25.96%的用户
*/
// 第一版，按照最原始的思路实现
char * convert(char * s, int numRows){
    if (numRows == 1)  // numRows为1，无需任何操作，直接返回
        return s;
   
    size_t len = strlen(s),
    row_1_skip = numRows * 2 - 2,  //到下一次轮回开始需要跳跃的列数
    loop = len / row_1_skip,  // 完整轮回总数
    cols = loop * (numRows - 1),   // 完整轮回的列总数
    left = len % row_1_skip;  // 经过所有完整轮回后剩余的个数
    if (left > 0)  // 如果有剩余
    {
        cols += 1;
        loop += 1;
        if (left > numRows)  // 如果剩余的次数多于numRows，说明比numsRows多出的部分要进入下几列
        {
            cols += left - numRows;  // 总列数随之扩展
        }
    }
    printf("%d %d\n", numRows, cols);
    char **mertix = (char**)malloc(sizeof(char*) * numRows);
    for (size_t i = 0; i < numRows; i++)
    {
        mertix[i] = (char*)malloc(sizeof(char) * cols);
        for (size_t j = 0; j < cols; j++)
            mertix[i][j] = ' ';
    }
    
    for (size_t cnt = 0, index = 0; cnt < loop; cnt++)
    {
        size_t i = 0, start_col = cnt * (numRows - 1);  // i为一次轮回中各位置的次序，start_col为每次轮回开始时的起始列
        for (i; index < len && i < numRows; i++)
        {
            mertix[i][start_col] = s[index++];  // 将字母按行递增的顺序排列
        }
        for (i; index < len && i < row_1_skip; i++)
        {
            int t = 2 * numRows -i - 2;
            mertix[t][numRows - 1 - t + start_col] = s[index++];  // 将字母按列递增、行递减的顺序排列
        }
    }
    
    char *res = (char*)malloc(sizeof(char) * (len + 1));
    res[len] = '\0';
    for (size_t i = 0, index = 0; i < numRows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            if (mertix[i][j] != ' ')
            {
                res[index++] = mertix[i][j];
            }
        }
    }
    return res;
}

void main(){
    char *s = "PAYPALISHIRING";
    char * res = convert(s, 4);
    puts(res);
}