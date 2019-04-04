#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);
    int i, j, max, index, num;
    
    /*根据可视字符串十进制表示范围32~126定义对应数量的数组*/
    int hashList[126-32+1] = { 0 };
    
    j = -1; max = 0; num = 0;
    for( i = 0; i < len; i++) {
        
        /*映射字符到数组下标*/
        index = s[i] - ' ';
        
        /*值不等于1表示前面已经出现过该字符*/
        if( ++hashList[ index ] == 1 ) {
            if(++num > max)
                max = num;
            
        } else {

            /*if里检测到重复字符串时没有++num自增,这里补上*/
            num++;
            
            /*找到重复字符,并将前面的映射值全部减1
             *即从重复字符后一位处向后继续检测字符串*/
            while( hashList[index] != 1) {
              hashList[ s[++j] - ' ' ]--;
                
            /*起始字符往后1位,则字符串长度递减1*/
              num--;
            }            
        }          
    }
    return max;
}

int main(void)
{
    /*测试字符串*/
    char str[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABC...";

    int len = lengthOfLongestSubstring(str);
    printf("Max len of substring = %d\n", len);

    char str2[] = "abcdea";
    len = lengthOfLongestSubstring(str2);
    printf("Max len of substring = %d\n", len);

    return 0;
}
