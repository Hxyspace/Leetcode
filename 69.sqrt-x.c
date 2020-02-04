/*
 * @lc app=leetcode id=69 lang=c
 *
 * [69] Sqrt(x)
 */

// @lc code=start

//暴力枚举
int mySqrt(int x){
    long i;
    for(i = 1; i * i <= x; i++);
    return (int)i - 1;
}

/* 二分法

int mySqrt(int x) {
        if(x==0) return 0;
        long start=1, end=x;
        while(start<=end)   {
            long middle = (start+end)/2;
            if(middle*middle==x) return middle;
            if(middle*middle<x) start=middle+1;
            else {end=middle-1;}
        }
        return start-1; //start points right next to the answer, hence, we return start-1
    }
*/
// @lc code=end