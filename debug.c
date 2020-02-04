#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* L = l1;
    while(l1 != NULL && l2 != NULL)
    {
        if(l1->val > l2->val)
        {
            struct ListNode *Ltemp = l1->next;
            int temp = l1->val;
            l1->val = l2->val;
            l2->val = temp;
            l1->next = l2;
            l2 = l2->next;
            if(Ltemp == NULL)
                l1->next->next = l2;
            l1->next->next = Ltemp;
            l1 = Ltemp;
        }
        else
        {
            l1 = l1->next;
        }
    }
    return L;
    
}

int main()
{
    struct ListNode* l1,*l2,*l3,*l4;
    l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l3 = l1;
    l3->val = 1;
    l3->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    l3 = l3->next;
    l3->val = 2;
    l3->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    l3 = l3->next;
    l3->val = 4;
    l3->next = NULL;

    l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l4 = l2;
    l4->val = 1;
    l4->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    l4 = l4->next;
    l4->val = 3;
    l4->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    l4 = l4->next;
    l4->val = 4;
    l4->next = NULL;

    mergeTwoLists(l1,l2);

    return 0;
}