# include<stdio.h>
# include<stdlib.h>
/*
执行用时：8 ms, 在所有 C 提交中击败了96.55%的用户
内存消耗：7.5 MB, 在所有 C 提交中击败了53.11%的用户
*/
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head = NULL, *p = NULL;
    int curse = 0;
    while(!(l1 == NULL || l2 == NULL)){
        int sum = l1->val + l2->val + curse;
        if(sum >= 10){
            curse = 1, sum %= 10;
        }
        else{
            curse = 0;
        }
        if(head == NULL){
            head = (struct ListNode*)malloc(sizeof(struct ListNode));
            head->val = sum, head->next = NULL;
            p = head;
        }
        else{
            struct ListNode* q = (struct ListNode*)malloc(sizeof(struct ListNode));
            q->val = sum, q->next = NULL;
            p->next = q, p = p->next;
        }
        l1 = l1->next, l2 = l2->next;
    }
    if(l1 == NULL && l2 == NULL){
        if(curse == 1){
            struct ListNode* q = (struct ListNode*)malloc(sizeof(struct ListNode));
            q->val = 1, q->next = NULL;
            p->next = q;
        }
        return head;
    }
    else if(l1 == NULL){
        int sum = l2->val + curse;
        while(sum == 10){
            struct ListNode* q = (struct ListNode*)malloc(sizeof(struct ListNode));
            q->val = 0, q->next = NULL;
            p->next = q, p = p->next;
            l2 = l2->next;
            if(l2 == NULL){
                struct ListNode* q = (struct ListNode*)malloc(sizeof(struct ListNode));
                q->val = 1, q->next = NULL;
                p->next = q;
                return head;
            }
            else{
                sum = l2->val + curse;
            }
        }
        l2->val = sum;
        p->next = l2;
    }
    else if(l2 == NULL){
        int sum = l1->val + curse;
        while(sum == 10){
            struct ListNode* q = (struct ListNode*)malloc(sizeof(struct ListNode));
            q->val = 0, q->next = NULL;
            p->next = q, p = p->next;
            l1 = l1->next;
            if(l1 == NULL){
                struct ListNode* q = (struct ListNode*)malloc(sizeof(struct ListNode));
                q->val = 1, q->next = NULL;
                p->next = q;
                return head;
            }
            else{
                sum = l1->val + curse;
            }
        }
        l1->val = sum;
        p->next = l1;
    }
    return head;
}