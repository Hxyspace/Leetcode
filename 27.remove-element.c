/*
 * @lc app=leetcode id=27 lang=c
 *
 * [27] Remove Element
 */

// @lc code=start


int removeElement(int* nums, int numsSize, int val){
    int i, j;
    for(i = 0, j = 0; j < numsSize; j++)
    {
        if(nums[j] != val)
            nums[i++] = nums[j];
    }
    return i;
}


// @lc code=end

