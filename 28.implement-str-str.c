/*
 * @lc app=leetcode id=28 lang=c
 *
 * [28] Implement strStr()
 */

// @lc code=start


int strStr(char * haystack, char * needle){
    int hSize = strlen(haystack);
    int nSize = strlen(needle);
    if(nSize == 0)
        return 0;
    int i, j, temp;
    for(i = 0; i < hSize; i++)
    {
        temp = i;
        for(j = 0;temp < hSize; j++, temp++)
        {
            if(haystack[temp] != needle[j])
                break;
            if(j == nSize - 1)
                return temp - nSize + 1;
        }
    }
    return -1;
}


// @lc code=end

