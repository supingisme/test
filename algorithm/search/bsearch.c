/**
 *  二分查找
 *
 *  作者：荣涛
 *  时间：2021年8月18日
 */
#include <stdio.h>


int binary_search(int *arr, int nr, int find_val)
{
    int start = 0;
    int end = nr - 1;

    while(start <= end) {
        
        if(arr[start] == find_val) return start;
        if(arr[end] == find_val) return end;
        
        if(start == end) {
            if(arr[start] != find_val) {
                return -1;
            } else {
                return start;
            }
        }
        
        int mid = (start + end)/2;
//        printf("mid = %d(%d,%d)\n", mid, start, end);
        
        if(arr[mid] > find_val) {
            end = mid;
        } else if(arr[mid] < find_val) {
            start = mid;
        } else {
            return mid;
        }
    }
    return -1;
}

int main()
{
    int i;
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12};


    for(i=0; i<sizeof(arr)/sizeof(arr[0]); i++) {
        printf("%d\n", binary_search(arr, sizeof(arr)/sizeof(arr[1]), i+1));
    }

}



