/*
 * @lc app=leetcode id=13 lang=c
 *
 * [13] Roman to Integer
 *
 * https://leetcode.com/problems/roman-to-integer/description/
 *
 * algorithms
 * Easy (51.55%)
 * Total Accepted:    367K
 * Total Submissions: 711.8K
 * Testcase Example:  '"III"'
 *
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D
 * and M.
 * 
 * 
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 
 * For example, two is written as II in Roman numeral, just two one's added
 * together. Twelve is written as, XII, which is simply X + II. The number
 * twenty seven is written as XXVII, which is XX + V + II.
 * 
 * Roman numerals are usually written largest to smallest from left to right.
 * However, the numeral for four is not IIII. Instead, the number four is
 * written as IV. Because the one is before the five we subtract it making
 * four. The same principle applies to the number nine, which is written as IX.
 * There are six instances where subtraction is used:
 * 
 * 
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * 
 * 
 * Given a roman numeral, convert it to an integer. Input is guaranteed to be
 * within the range from 1 to 3999.
 * 
 * Example 1:
 * 
 * 
 * Input: "III"
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: "IV"
 * Output: 4
 * 
 * Example 3:
 * 
 * 
 * Input: "IX"
 * Output: 9
 * 
 * Example 4:
 * 
 * 
 * Input: "LVIII"
 * Output: 58
 * Explanation: L = 50, V= 5, III = 3.
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "MCMXCIV"
 * Output: 1994
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 * 
 */

int su(char a)  /* 将罗马数字转换成阿拉伯数字 */
{
    int b;
        switch (a)
    {
        case 'I': b = 1;break;
        case 'V': b = 5;break;
        case 'X': b = 10;break;
        case 'L': b = 50;break;
        case 'C': b = 100;break;
        case 'D': b = 500;break;
        case 'M': b = 1000;break;
    }
    return b;
}

int romanToInt(char* s) {
    int i,n = strlen(s);
    int sum = 0,num = su(s[0]);
    for(i = 1;i < n;i++)
    {
        if(num >= su(s[i]) )  /* 当前数字与下一个数字比较 */
        sum += num;             /* 当前数比后一个数大，则加上当前数字，反之则相减 */
        else
        sum -= num;
        num = su(s[i]);
    }
    sum += num;  /* 最后一个数为增加 */
    return sum;
}

