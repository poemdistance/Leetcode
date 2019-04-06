#include <stdio.h>

/*暴力法*/
int maxArea(int* height, int heightSize) {
    
    int i, j;
    int max, min;
    int current;
    
    for( max = 0, i = 0; i < heightSize - 1; i++) {
        for( j = i + 1; j < heightSize; j++) {
            min = height[i]<height[j]?height[i]:height[j];
            if( ( current = (j-i) * min ) > max)
                max  = current;
        }
    }
    
    return max;
    
}

/*时间复杂度O(N)*/
int maxArea2(int* height, int heightSize) {
    
    int i, j;
    int max = 0;
    int min;
    int current;

    for(i=0, j=heightSize-1; i < j; ) {
        min = height[i]<height[j]?height[i]:height[j];
        current = min * ( j - i );
        if( current > max )
            max = current;
        if( height[i] > height[j])
            j--;
        else
            i++;
    } 
    return max;
    
}

int main()
{
    int num[] = { 1,8,6,2,5,4,8,3,7 };
    int val = maxArea(num, 9);
    printf("%d\n", val);
    
    return 0;
}

/*
 * 给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。



图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。



示例:

输入: [1,8,6,2,5,4,8,3,7]
输出: 49*/
