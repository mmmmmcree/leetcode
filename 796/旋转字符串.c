# include<stdio.h>
# include<stdlib.h>
# include<string.h>

# define bool int

bool rotateString(char * s, char * goal){
    int i = strlen(s), j = strlen(goal);
    if(i != j){
        return 0;
    }
    char *double_goal = (char*)malloc(sizeof(char) * (j * 2 + 1));
    sprintf(double_goal, "%s%s", goal, goal);
    return strstr(double_goal, s);
}