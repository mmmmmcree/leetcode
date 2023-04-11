# include<stdio.h>
# include<stdlib.h>
# include<ctype.h>

int lengthOfLastWord(char * s){
    int length = 0;
    int flag = 1;
    for(int i = 0; s[i] != '\0'; i++){
        if(isalpha(s[i])){
            if(flag == 1){
                flag = 0;
                length = 0;
            }
            length++;
        }
        else if(flag == 0 && !isalpha(s[i])){
            flag = 1;
        }
    }
    return length;
}