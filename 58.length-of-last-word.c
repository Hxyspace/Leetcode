/*
 * @lc app=leetcode id=58 lang=c
 *
 * [58] Length of Last Word
 */

// @lc code=start


int lengthOfLastWord(char * s){
    int count = 0;
    for(int i = 0; s[i] != '\0'; i++)
    {
        while(s[i] == ' ')          /* 去掉连续的空格 */
        {
            i++;
            if(s[i] != ' ' && s[i] != '\0')     /* 当s[i] 为字母时，重置count */
                count = 0;
        }
        if(s[i] != '\0')
            count++;
        else
            return count;
        
    }
    return count;
}

/* 
参考：
int lengthOfLastWord(char * s) {
        int n = strlen(s);
        int len = 0;
        
        for(int i = n-1; i>=0; i--)
        {
            if(s[i] != ' ')
                len++;
            else if(len > 0)
                return len;
        }
        
        return len;
}
 */

// @lc code=end

