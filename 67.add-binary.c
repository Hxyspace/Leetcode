/*
 * @lc app=leetcode id=67 lang=c
 *
 * [67] Add Binary
 */

// @lc code=start


char * addBinary(char * a, char * b){
    char *bin, *temp;       /* bin为相加后的字符串，temp为长的那个字符串 */
    int n, alen = strlen(a), blen = strlen(b);          /* n 为bin的长度，minlen为短字符串的长度 */
    int flag = 0;   //标记是否进位
    if(alen > blen)
    {
        n = alen + 1;
        temp = a;
    }
    else
    {
        n = blen + 1;
        temp = b;
    }
    bin = (char *)malloc((n + 1) * sizeof(char));
    bin[n] = '\0';
    while(alen && blen)
    {
        bin[--n] = a[--alen] + b[--blen] - '0' + flag;
        if(bin[n] == '2')
        {
            flag = 1;
            bin[n] = '0';
        }
        else if(bin[n] == '3')
        {
            flag = 1;
            bin[n] = '1';
        }
        else
        {
            flag = 0;
        }
    }
    while(--n >= 1)
    {
        bin[n] = temp[n - 1] + flag;
        if(bin[n] == '2')
        {
            flag = 1;
            bin[n] = '0';
        }
        else if(bin[n] == '3')
        {
            flag = 1;
            bin[n] = '1';
        }
        else
        {
            flag = 0;
        }
    }
    if(flag)
    {
        bin[0] = '1';
        return bin;
    }
    return bin + 1;

}

/*      参考答案
char* addBinary(char* a, char* b) {
    int lena = strlen(a), lenb = strlen(b), carry = 0;
    int lenc = lena > lenb?lena:lenb;
    char * c = malloc(lenc+2);
    c[lenc+1] = '\0';
    while(lena || lenb ){
        if(lena) carry += (a[--lena]-'0');
        if(lenb) carry += (b[--lenb]-'0');
        c[lenc--] = (carry&1)+'0';
        carry >>= 1;
    }
    c[0] = carry+'0';
    return c+(carry^1);
    // for(int i = -1, j = 0;c[j] && !carry;c[++i] = c[++j]);
    // return c;
} 

*/
// @lc code=end

