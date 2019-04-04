/*此程序时间复杂读不符合要求,为O(m+n)*/

#include <stdio.h>
#include <stdlib.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    
    int mid = nums2Size / 2;
    
    if( nums1Size == 0) {
        if( nums2Size % 2 == 1) {
            return nums2[ mid ];
        } else {
            return (nums2[ mid ] + nums2[ mid - 1]) *1.0 / 2;
        }             
    }   
    
    mid = nums1Size / 2;
    if( nums2Size == 0) {
        if( nums1Size % 2 == 1) {
            return nums1[ mid ];
        } else {
             return (nums1[ mid ] + nums1[ mid - 1]) * 1.0 / 2;
        }             
    } 
    
    int i = 0, j = 0, k = 0;
    int len = ( nums1Size + nums2Size );
    int *p = malloc( sizeof( int ) * len );
    while( i < nums1Size && j < nums2Size ) {

        if( nums1[i] > nums2[j]) {
            p[k++] = nums2[j];
            j++;
        }
        else {
            p[k++] = nums1[i];
            i++;
        }
    }
    
    if(i == nums1Size) {
        for( ; j < nums2Size; j++) {
            p[k++] = nums2[j];
        }
    } else if (j == nums2Size) {
        for( ; i < nums1Size; i++) {
            p[k++] = nums1[i];
        }
    }
    
    double oddMid = p[len / 2];
    double evenMid = 1.0 * (p[ len / 2] + p[ len / 2 -1]) / 2;
    free(p);
    if( len % 2 == 1 ) {
        return oddMid;
    } else 
        return evenMid;
    

}int
main(int argc, char **argv)
{
    int nums1[4] = { 2, 3, 4, 5 };
    int nums2[4] = { 1, 2, 3, 4 };

    double val = findMedianSortedArrays(nums1, 4, nums2, 4);
    printf("val=%f\n", val);
    return 0;
}

