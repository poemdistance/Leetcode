/*最长回文字符串暴力求解
 *不过时间超过限制了,作废*/

#include <stdio.h>
#include <string.h>

char* longestPalindrome(char* s) {

    int i, j, k, m, max;
    int len = strlen(s);
    char *p = s;
    int flag = 0;
    int start = 0, end = 0;

    if(len <= 1)
        return s;

    max = 0;
    for( i = 0; i < len; i++) {
        for( j = i; j < len; j++ ) {
            flag = 1;
            for( k = i, m = j; k < m; k++, m-- ) {
                if(s[k] != s[m]) {
                    flag = 0;
                    break;
                }
            }
            if(flag != 0)
                if( j - i + 1 > max ) {
                    max = j - i + 1;
                    start = i;
                    end = j;
                }
        }
    }
    s[end+1] = '\0';
    return &s[start];
}

int
main(int argc, char **argv)
{
    char str[]="aaaaabajbaaaaa";
    char *val = longestPalindrome(str);
    printf("val=%s\n", val);
    return 0;
}

