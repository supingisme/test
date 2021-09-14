/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:24 CST. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binary_search(int arr[], int N, int find) 
{
    int left = 0;
    int right = N-1;
    int n = (right + left + 1)/2;

    /**
     *  处理两头最坏的情况
     */
    if(arr[left] == find) {
        return left;
    }
    if(arr[right] == find) {
        return right;
    }

    /**
     *  二分查找
     */
    while(arr[n] != find) {
        if(arr[n] > find) {
            right = n;
        } else if(arr[n] < find) {
            left = n;
        } else {
            break;
        }
        
        n = (right + left + 1)/2;

//        printf("[%d - %d] n = %d\n", left, right, n);
//        sleep(1);
        if(left == right) {
            return -1;
        }
    }
    return n;
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22};

    int find = binary_search(arr, sizeof(arr)/sizeof(arr[0]), 3);

    printf("find = %d\n", find);
    
	return 0;
}
