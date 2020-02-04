/*
 * @lc app=leetcode id=83 lang=c
 *
 * [83] Remove Duplicates from Sorted List
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (44.15%)
 * Likes:    1103
 * Dislikes: 94
 * Total Accepted:    402.9K
 * Total Submissions: 912.5K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->1->2
 * Output: 1->2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->2->3->3
 * Output: 1->2->3
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode * node = head;
    if(node == NULL)
        return head;
    while(node->next != NULL)
    {
        if(node->val == node->next->val)
        {
            node->next = node->next->next;
        }
        else
        {
            node = node->next;
        }
    }
    return head;
    
}


// @lc code=end

