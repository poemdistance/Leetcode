/*这是要钉上耻辱柱的代码,太丑了*/

#include <stdio.h>
#include <stdlib.h> //for abs()
#include <string.h>

char* longestPalindrome(char* s) {

    int len = strlen(s);

    if( len == 1)
        return s;

    if( len == 2) {
        if(s[0] == s[1])
            return s;
        s[1] = '\0';
        return s;
    }

    int left = 0, right = len - 1;
    int end, start; 
    int  maxlen = 0;
    int l, r, i, j;

    /*剩余长度不足maxlen时不再查找*/
    while( left <  len - maxlen )
    {
        i = left;
        j = right;

        while(1) {
            /*从右向左扫描到与左边元素相同为止*/
            while( s[i] != s[j--] );

            /*未找到相同元素*/
            if( i > j ) {
                left++;
                break;
            }
            else {  //找到了相同的元素
                l = left;
                r = j + 1;
                j++;

                /*验证内部是否符合回文特征*/
                while( s[++i] == s[--j] && i < j);

                /*符合回文特征*/
                if( i >= j ) {
                    if( r - l + 1 > maxlen ) {
                        maxlen = r - l + 1;
                        end = r; start = l; //回文字符串始末位置
                    }

                    /*比对下一元素*/
                    left++;
                    break;
                }
                else {  //不符合回文特征,继续向右扫面直到发现相同元素
                    i = left;
                    j = r - 1;
                }
            }  //else
        }   //while(1)
    } //while(left < len - maxlen)

    if(maxlen == 0) {
        s[1] = '\0';
        return s;
    }

    s[end+1] = '\0';
    return &s[start];
}

int main()
{
    char str[] = "aaaabaaaa";
    //char str[] = "";
    char *p = longestPalindrome(str);
    printf("%s\n", p);
    return 0;
}
