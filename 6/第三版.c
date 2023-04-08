# include<stdio.h>
# include<stdlib.h>
# include<string.h>
//  这是一坨大便
char * convert(char * s, int numRows){
    if (numRows == 1)
        return s;
   
    size_t 
    len = strlen(s),
    row_1_skip = numRows * 2 - 2,
    loop = len / row_1_skip,
    cols = loop * (numRows - 1),
    left = len % row_1_skip;
    if (left > 0)
    {
        cols += 1, loop += 1;
        if (left > numRows)
            cols += left - numRows;
    }
    int * array = (int*)malloc(sizeof(int) * len);
    int * brray = (int*)malloc(sizeof(int) * len);
    for (size_t cnt = 0, index = 0; cnt < loop; cnt++)
    {
        size_t i = 0, start_col = cnt * (numRows - 1);
        for (i; index < len && i < numRows; i++)
        {
            array[index++] = i * cols + start_col;
        }
        for (i; index < len && i < row_1_skip; i++)
        {
            int t = 2 * numRows -i - 2;
            array[index++] = t * cols + numRows - 1 - t + start_col;
        }
    }
    for (size_t i = 0; i < len; i++)
    {
        size_t cnt = 0;
        for (size_t j = 0; j < len; j++)
        {
            if (array[j] < array[i])
                cnt++;
        }
        brray[i] = cnt;
    }

    char *res = (char*)malloc(sizeof(char) * (len + 1));
    res[len] = '\0';
    for (size_t i = 0, index = 0; i < len; i++)
    {
        res[brray[i]] = s[i];
    }
    return res;
}

void main(){
    char *s = "PAYPALISHIRING";
    char * res = convert(s, 4);
    puts(res);
}