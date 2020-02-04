/*
 * @lc app=leetcode id=14 lang=c
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (32.99%)
 * Total Accepted:    412.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
char* longestCommonPrefix(char** strs, int strsSize) {
    int x,y = 0,i,j,k = 0;
    if(strsSize == 0)   /* 如果字符串数量为0 返回空字符串 */
        return "";
    for(x = 1;x < strsSize;x++)     /* 遍历除了首字符串外是所有字符串 */
    {
        for(i = 0;strs[0][i];i++)   /* 遍历第一个字符串的每一个字符 */
        {
            if(strs[x][i] != strs[0][i]) /* 如果发现字符不相同，此时前缀最大，用 \0 截断字符串，再与下一个字符串比较 */
            {
                strs[0][i] = '\0';
                break;
            }
        }
    }
    return *strs;
    
}

