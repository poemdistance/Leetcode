#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *convert(char *s, int numRows)
{
    if( numRows <= 1 )
        return s;

    int len = strlen(s);
    if( numRows >= len )
        return s;

    /*+1 Reason:注意字符串末尾还有'\0'*/
    char *str = malloc(sizeof(char) * (len+1));

    int i, j, k, index;
    for( k = 0, i = 0; i < numRows; i++ ) {

        /*忽略最后一行,此工作在下一个for里会完成*/
        if(i != numRows - 1)
            str[k++] = s[i];

        /*获取第i行元素在原字符串s中的下标值*/
        for( j = 1; (index = 2 * j * numRows - 2*j - i) < len; j++) {

            /*复制斜线上的元素到str*/
            str[k++] = s[index];

            /*获取斜线元素下一个的下标值*/
            if( i > 0 && i < numRows - 1 ) {
                index += 2 * i;
                if( index < len ) 
                    str[k++] = s[index];
            }
        }
    }

    i = j = 0;
    /*千万注意添加结尾字符,否则下一语句将访问内存越界*/
    str[len] = '\0';

    /*将得到的新序列复制回s,以释放str指向的内存空间*/
    while( (s[i++] = str[j++]) != '\0' );

    free(str);

    return s;
}

int main()
{
    //char str[] = "ABfsdfasdgafasdfa";
    char str[] = "";
    printf("%s\n", str);
    char *ptr = convert(str, 9);
    printf("%s\n", ptr);;
    return 0;
}

/*将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

L   C   I   R
E T O E S I I G
E   D   H   N
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
示例 1:

输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"
示例 2:

输入: s = "LEETCODEISHIRING", numRows = 4
输出: "LDREOEIIECIHNTSG"
解释:

L     D     R
E   O E   I I
E C   I H   N
 * */

