/*
 * @lc app=leetcode id=53 lang=c
 *
 * [53] Maximum Subarray
 */

// @lc code=start


int maxSubArray(int* nums, int numsSize){
    if(numsSize == 0)
        return 0;
    int cur=0;
	int res=nums[0];
	for(int i=0;i<numsSize;i++){

		cur+=nums[i];
		if(cur<nums[i])         //如果前面的子数组和为负数， 则从nums[i]开始重新计算
        {       
			cur=nums[i];
		}
		res=cur > res ? cur : res;      //res为最大的子数组和

	}
	return res;
}

// @lc code=end

