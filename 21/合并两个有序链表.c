# include<stdio.h>
# include<stdlib.h>
/*
执行用时：0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗：5.9 MB, 在所有 C 提交中击败了57.51%的用户
*/
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if(list1 == NULL){
        return list2;
    }
    else if(list2 == NULL){
        return list1;
    }
    struct ListNode *merged_list = NULL;
    struct ListNode *p = NULL;
    while(1){
        if(list1 == NULL){
            p->next = list2;
            return merged_list;
        }
        else if(list2 == NULL){
            p->next = list1;
            return merged_list;
        }
        else if(list1->val <= list2->val){
            if(merged_list == NULL){
                merged_list = list1;
                p = merged_list;
                list1 = list1->next;
            }
            else{
                p->next = list1;
                p = p->next;
                list1 = list1->next;
            }
        }
        else if(list2->val < list1->val){
            if(merged_list == NULL){
                merged_list = list2;
                p = merged_list;
                list2 = list2->next;
            }
            else{
                p->next = list2;
                p = p->next;
                list2 = list2->next;
            }
        }
    }
    return merged_list;
}