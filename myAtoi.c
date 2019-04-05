#include <stdio.h>
#include <math.h>
#include <string.h>

int myAtoi(char* str) {

    char *p = str;
    char *end;
    int sign = 1;

    /*过滤空格*/
    while( *p++ == ' ' );
    p--;

    /*排除非法字符串*/
    if( ! ( ( *p >= '0' &&  *p <= '9') ||
                *p == '+' || *p == '-') )
        return 0;
    
    /*符号判断*/
    if( *p == '-' ) {
        sign = -1;
        p++;
    }
    else if( *p == '+' ) {
        sign = 1;
        p++;
    }

    /*移动指针到最后一个非数字字符*/
    end = p;
    while( *end >= '0' && *end <= '9' )
        end++;
    *end = '\0';

    /*去除无意义的0起始数字*/
    while( *p++ == '0');
    p--;
    printf("str=%s len=%d\n", p, strlen(p));
    
    /*直接排除长度超过int型的*/
    int len = strlen(p);
    if( len > 10 && sign == 1)
        return 2147483647;
    else if( len > 10 && sign == -1)
        return -2147483648;

    int res = 0, flag = 1;
    int table[10] = { 2, 1, 4, 7, 4, 8, 3, 6, 4, 7 };

    for( int i = 0; i < len; i++ ) {

        /*长度为10时,如果任意一位大于table中对应的,说明超过了
         *int型容纳范围,直接返回*/
        if( flag && len == 10 && p[i] - '0' > table[i]) {
            if( sign == 1) {
                return 2147483647;
            } else if( sign == -1) {
                return -2147483648;
            }
        } /*如果前面的数字都有小于table里的,则数值绝对比最大值小,后面不再比较flag置0*/
        else if( flag && len == 10 && p[i] - '0' < table[i])
            flag = 0;
            
            
        res += (p[i] - '0') * pow( 10, len - i - 1 );
    }

    res *= sign;
    return res;
}
int
main(int argc, char **argv)
{
    char str[] = "2147483646";
    char str1[] = " dh42";
    char str2[] = "   1sd-42";

     int val1 = myAtoi(str);
     int val2 = myAtoi(str1);
     int val3 = myAtoi(str2);

     printf("%d\n", val1);
     printf("%d\n", val2);
     printf("%d\n", val3);
     return 0;
}

/* 请你来实现一个 atoi 函数，使其能将字符串转换成整数。

首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。

当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号；假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。

该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。

注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。

在任何情况下，若函数不能进行有效的转换时，请返回 0。

说明：

假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231,  231 − 1]。如果数值超过这个范围，qing返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。

示例 1:

输入: "42"
输出: 42
示例 2:

输入: "   -42"
输出: -42
解释: 第一个非空白字符为 '-', 它是一个负号。
     我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
示例 3:

输入: "4193 with words"
输出: 4193
解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。
示例 4:

输入: "words and 987"
输出: 0
解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
     因此无法执行有效的转换。
示例 5:

输入: "-91283472332"
输出: -2147483648
解释: 数字 "-91283472332" 超过 32 位有符号整数范围。 
     因此返回 INT_MIN (−231) 
 * */
