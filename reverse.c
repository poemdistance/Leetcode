#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int reverse(int x) {
    
    /*int最大正数2147483647, 所以这个值不能abs成int型
     *的正数,且其逆必定溢出int范围,直接返回0即可*/
    if( x == -2147483648)
        return 0;
    
    int neg = 1, i = 0;
    int pos = x;
    
    if( x < 0) {
        neg = -1;
        pos = abs( x );
    }

    /*取出各位上的数值*/
    int arr[10] = { 0 };
    while( pos > 0) {
        arr[i++] = pos % 10;
        pos /= 10;
    }
    
    /*数组重组成数字*/
    double res = 0, exp = 0;
    while( i > 0) {
        printf("%d ", (int)res);
        res += arr[--i] * pow( 10 , exp++);
    }
   
    /*超出整形范围返回0*/
    if( res > 2147483647 && neg == 1)
        return 0;
    if( res >= 2147483648 && neg == -1)
        return 0;
        
    return (int)res;
}

int main()
{
    int x = 1234567;
    int val = reverse(x);
    printf("%d\n", val);
}

/*给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
示例 1:
输入: 123
输出: 321

 示例 2:
输入: -123
输出: -321

示例 3:
输入: 120
输出: 21
注意:

假设我们的环境只能存储得下 32 位的有符号整数，
则其数值范围为 [−231,  231 − 1]。
请根据这个假设，如果反转后整数溢出那么就返回 0。
 * */
