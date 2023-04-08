# include<stdio.h>
# include<stdlib.h>
/*
执行用时：0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗：5.6 MB, 在所有 C 提交中击败了78.23%的用户
*/
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *p = head, *q = head;
    for (size_t i = 0; i < n; i++)
    {
        if (p->next == NULL)
        {
            head = head->next;
            return head;
        }
        p = p->next;
    }
    while (p->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p = q->next;
    q->next = q->next->next;
    free(p);
    return head;
}