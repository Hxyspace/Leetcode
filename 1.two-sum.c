/*
 * @lc app=leetcode id=1 lang=c
 *
 * [1] Two Sum
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i,j;
    int *a = (int *)malloc(2*sizeof(int));
    for(i = 0; i < numsSize;i++)
    for(j = i+1; j < numsSize ;j++)
    {
        // if(i == j)
        // continue;
        if(nums[i] + nums[j] == target)
        {
            a[0] = i;
            a[1] = j;
        }
    }
    *returnSize = 2;
    return a;
    
}


// @lc code=end

