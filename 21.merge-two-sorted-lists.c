/*
 * @lc app=leetcode id=21 lang=c
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (45.82%)
 * Total Accepted:    521K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* L = l1;
    if(l1 == NULL)
        return l2;
    while(l2 != NULL)
    {

        if(l1->val > l2->val)
        {
            struct ListNode *Ltemp = l1->next;
            int temp = l1->val;
            l1->val = l2->val;
            l2->val = temp;
            l1->next = l2;
            l2 = l2->next;
            
            l1 = l1->next;
            l1->next = Ltemp;
        }
        else
        {
            if(l1->next == NULL)
            {
                l1->next = l2;
                break;
            }
            l1 = l1->next;
        }
    }
    return L;
    
}

