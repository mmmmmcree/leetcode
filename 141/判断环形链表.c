# include<stdio.h>
# include<stdlib.h>

# define bool int
# define False 0
# define Ture 1

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    struct ListNode **a = (struct ListNode**)malloc(sizeof(struct ListNode*));
    int i = 0;
    while(Ture){
        if(head == NULL){
            return False;
        }
        else{
            for(int j = 0; j < i; j++){
                if(a[j] == head){
                    return Ture;
                }
            }
            a = realloc(a, sizeof(struct ListNode*) * (i +1));
            a[i++] = head;
            head = head->next;
        }
    }
    return Ture;
}