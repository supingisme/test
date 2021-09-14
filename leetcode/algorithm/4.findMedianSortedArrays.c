/*
4. 寻找两个正序数组的中位数
给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。

请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

 

示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/**
 *		1 2 3 4 | 7 8 9
 *		 +------+
 *		5| 6 
 */
#if 0 //TODO
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){

    typedef enum {ITEM_NONE, ITEM_NUMS1, ITEM_NUMS2} item_t;

    //总数的中间值位置
	const int num_mid = (nums1Size + nums2Size - 1) / 2;

    //如果总数是奇数
	const int is_odd = (nums1Size + nums2Size)%2; 
	printf("num_mid = %d, is_odd = %d\n", num_mid, is_odd);

    //两个数组的二分查找中间值
	int i1 = (nums1Size-1)/2;
	int i2 = (nums2Size-1)/2;
	printf("i1 = %d, i2 = %d\n", i1, i2);

//    do {

        int idx1_left = i1<nums1Size?i1:nums1Size;
        int idx1_right = (i1+1)<nums1Size?(i1+1):nums1Size;

        int idx2_left = i2<nums2Size?i2:nums2Size;
        int idx2_right = (i2+1)<nums2Size?(i2+1):nums2Size;

        
        item_t who_is_left_max = nums1[idx1_left]>nums2[idx2_left]?ITEM_NUMS1:ITEM_NUMS2;
        item_t who_is_right_max = nums1[idx1_right]>nums2[idx2_right]?ITEM_NUMS1:ITEM_NUMS2;

        int max_left = who_is_left_max==ITEM_NUMS1?nums1[idx1_left]:nums2[idx2_left];
        int max_right = who_is_right_max==ITEM_NUMS1?nums1[idx1_right]:nums2[idx2_right];

        if(max_left <= max_right && idx1_left+idx2_left == num_mid) {
            
        } else {

        }

//    }while(1);
	
}
#else

#define DEBUG

#ifdef DEBUG



void debug(int* nums1, int nums1Size, int* nums2, int nums2Size, 
            int lo, int hi, int c1, int c2, int LMax1, int RMin1, int LMax2, int RMin2)
{
    
    system("clear");
    
    printf("lo = %d, hi = %d, c1 = %d, c2 = %d, L1 = %d, R1 = %d, L2 = %d, R2 = %d\n",
            lo, hi, c1, c2, LMax1, RMin1, LMax2, RMin2);

    int i1, i2;

    for(i1 = 0; i1 < nums1Size*2; i1++) {
        if(i1 %2 == 0)
            printf("%-2d ", nums1[i1/2]);
        else
            printf("#  ");
    }printf("  \n");
        
    for(i1 = 0; i1 <= nums1Size*2; i1++) {
        if(i1 == lo) printf("\033[1;31m^  \033[m");
        else if(i1 == hi) printf("\033[1;32m^  \033[m");
        else if(i1 == c1) printf("\033[1;33m^  \033[m");
        else printf("   ");
    }printf(" \n");
    
    for(i1 = 0; i1 < nums1Size; i1++) {
        printf("%-2d ", nums1[i1]);
    }printf("   \n");
    
    for(i1 = 0; i1 < nums1Size; i1++) {
        if(i1 == ((c1 - 1) / 2)) printf("\033[1;31m^  \033[m");
        else if(i1 == (c1 / 2)) printf("\033[1;32m^  \033[m");
        else printf("   ");
    }printf("   \n");
        
    for(i2 = 0; i2 < nums2Size; i2++) {
        printf("%-2d ", nums2[i2]);
    }printf("   \n");
    for(i2 = 0; i2 < nums2Size; i2++) {
        if(i2 == ((c2 - 1) / 2)) printf("\033[1;31m^  \033[m");
        else if(i2 == (c2 / 2)) printf("\033[1;32m^  \033[m");
        else printf("   ");
    }printf("   \n");

    sleep(2);

}

#endif


#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){

    //保证数组1一定最短
	if (nums1Size > nums2Size)  
	{
		return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
	}
    
	// Ci 为第i个数组的割,比如C1为2时表示第1个数组只有2个元素。
	// LMaxi为第i个数组割后的左元素。RMini为第i个数组割后的右元素。
	// 是虚拟加了'#'所以数组1是2*n长度
	int LMax1, LMax2, RMin1, RMin2, c1, c2, lo = 0, hi = 2 * nums1Size;  

	while (lo <= hi)   //二分
	{
		c1 = (lo + hi) / 2;  //c1是二分的结果
		c2 = nums2Size + nums1Size - c1;

		LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
		RMin1 = (c1 == 2 * nums1Size) ? INT_MAX : nums1[c1 / 2];
		LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
		RMin2 = (c2 == 2 * nums2Size) ? INT_MAX : nums2[c2 / 2];

        
#ifdef DEBUG
        debug(nums1, nums1Size, nums2, nums2Size, lo, hi, c1, c2, LMax1, RMin1, LMax2, RMin2);
#endif

		if (LMax1 > RMin2)
			hi = c1 - 1;
		else if (LMax2 > RMin1)
			lo = c1 + 1;
		else
			break;

        
	}
	return (MAX(LMax1, LMax2) + MIN(RMin1, RMin2)) / 2.0;
}
//lo = 0, hi = 10, c1 = 5, c2 = 6, L1 = 12, R1 = 12, L2 = 6, R2 = 7
//10 #  11 #  12 #  13 #  14 #    
//^              ^              ^   
//10 11 12 13 14    
//      ^           
//4  5  6  7  8  9     
//      ^  ^           
//lo = 0, hi = 4, c1 = 2, c2 = 9, L1 = 10, R1 = 11, L2 = 8, R2 = 8
//10 #  11 #  12 #  13 #  14 #    
//^     ^     ^                     
//10 11 12 13 14    
//^  ^              
//4  5  6  7  8  9     
//            ^        
//lo = 0, hi = 1, c1 = 0, c2 = 11, L1 = -2147483648, R1 = 10, L2 = 9, R2 = 9
//10 #  11 #  12 #  13 #  14 #    
//^  ^                              
//10 11 12 13 14    
//^                 
//4  5  6  7  8  9     
//               ^     
//9.000000

#endif

int main(int argc, char *argv[])
{
	int nums1Size = 0, nums2Size = 0;
	int nums1[32] = {0}, nums2[32] = {0};
	int iargc, is_nums1 = 1;

	for(iargc=1; iargc<argc;iargc++) {

		if(strcmp(argv[iargc], "-") == 0) {
			is_nums1 = 0;
			continue;
		}

		if(is_nums1) {
			nums1[nums1Size++] = atoi(argv[iargc]);
		} else {
			nums2[nums2Size++] = atoi(argv[iargc]);
		}
	}
	
	printf("%lf\n", findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size));
}
