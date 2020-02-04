/*
 * @lc app=leetcode id=20 lang=c
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (35.88%)
 * Total Accepted:    523.9K
 * Total Submissions: 1.5M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */
 
#define stackSize 50
#define addSize 10

 typedef struct
 {
     char *top;
     char *base;
     int size;
 }stack;

 bool init(stack *s)
 {
    s->base = (char *)malloc(stackSize * sizeof(char));
    if(s->base == NULL)
        return false;
    s->top = s->base;
    s->size = 0;
    return true;
 }

 int push(stack *s,char e)
{
    if(s->top - s->base == s->size)
    {
        s->base = (char *)realloc(s->base,s->size + addSize * sizeof(char));
        s->top = s->base + s->size;
    }
    *s->top++ = e;
    s->size++;
    return 0;
}

bool pop(stack *s,char *e)
{
    if(s->size == 0)
    return false;
    s->size--;

    *e = *--s->top; 
    return true;
}

bool comparison(char x,char y)
{
    if((x == '(' && y == ')') || 
        (x == '[' && y == ']') ||
        (x == '{' && y == '}'))
        return true;
    return false;
}

bool isValid(char* s) {
    stack st;
    char e;
    init(&st);
    for(int i = 0;s[i];i++)
    {
        if(s[i] == '(' || s[i] =='[' || s[i] == '{')
            push(&st,s[i]);
        else
        {
            if(!pop(&st,&e))
                return false;
            if(!comparison(e,s[i]))
                return false;
        }
    }
    if(st.size == 0)
        return true;
    return false;
}

