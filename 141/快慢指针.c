# include<stdio.h>
# include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int hasCycle(struct ListNode *head) {
    struct ListNode *slow = (struct ListNode*)malloc(sizeof(struct ListNode));
    slow->next = head;
    struct ListNode *fast = head;
    while(fast != slow){
        if(fast == NULL){
            return 0;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    return 1;
}