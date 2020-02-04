/*
 * @lc app=leetcode id=66 lang=c
 *
 * [66] Plus One
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int i = digitsSize - 1;
    digits[i]++;
    while (digits[i] == 10 && i > 0)
    {
        digits[i] = 0;
        digits[--i]++;
    }
    if(digits[0] == 10)
    {
        digitsSize++;
        digits = (int *)realloc(digits, digitsSize * sizeof(int));
        digits[0] = 1;
        digits[digitsSize - 1] = 0;
    }
    *returnSize = digitsSize;
    return digits;
}

// @lc code=end

