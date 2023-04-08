# include<stdio.h>
# include<stdlib.h>
# include<ctype.h>
# include<string.h>

# define bool int

bool isPalindrome(char * s){
    int i = 0, j = strlen(s) - 1;
    while(i < j){
        while(s[i] != '\0' && !isalnum(s[i])){
            i++;
        }
        while(!isalnum(s[j])){
            j--;
            if(j < 0){
                return 1;
            }
        }
        if(tolower(s[i]) != tolower(s[j])){
            return 0;
        }
        else{
            i++, j--;
        }
    }
    return 1;
}

void main(){
    char s[81] = "A man, a plan, a canal: Panama";
    printf("%d", isPalindrome(s));
}