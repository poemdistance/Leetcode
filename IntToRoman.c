#include <stdio.h>
#include <string.h>

/*建立从数字到字符的映射关系CharTable & NumTable*/

/*1, 2,3 ,4 ,5, 6, 7, 8 ,9, 10, 40, 50, 90, 100, 400, 500, 900, 1000*/
char CharTable[][5] = { "I", "II", "III", "IV", "V", "VI", 
                    "VII", "VIII", "IX", "X", "XL" ,"L", 
                    "XC", "C", "CD", "D", "CM", "M" };

int NumTable[18]= {1, 2,3 ,4 ,5, 6, 7, 8 ,9, 10, 
                   40, 50, 90, 100, 400, 500, 900, 1000};

char* intToRoman(int num) {
    int i, j;
    int times;
    static char str[10];

    memset(str, '\0', sizeof(str));

    for( i = 17; num > 0;  ) {
        if(num < NumTable[i]) {
            i--;
            continue;
        }
        /*找到第一个小于num的table值*/
        else if (num > NumTable[i]) { 
            j = times = num / NumTable[i];

            while(times--)
                strcat(str, CharTable[i]);

            num -= j * NumTable[i--];
        }
        else  
            return strcat(str, CharTable[i]);
    }

    return str;
}

int
main(int argc, char **argv)
{
    printf("%s\n", intToRoman(58));
    return 0;
}
