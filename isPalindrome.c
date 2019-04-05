#include <stdio.h>

int isPalindrome(int x) {
    
    if( x < 0 )
        return 0;
    
    int arr[10];
    int i = 0, j;
    while( x > 0 ) {
        arr[i++] = x % 10;
        x /= 10;
    }

    for(i--, j = 0; j < i; j++, i--) {
        if( arr[i] != arr[j])
            return 0;
    } 
    
    return 1;
}

int main()
{
    printf("%d\n", isPalindrome(2222442222));
    return 0;
}

/*
 * 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:

输入: 121
输出: true
示例 2:

输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:

输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
进阶:

你能不将整数转为字符串来解决这个问题吗？*/
