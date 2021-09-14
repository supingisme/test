//31. 下一个排列
//实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
//
//如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
//
//必须原地修改，只允许使用额外常数空间。
//
//以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
//1,2,3 → 1,3,2
//3,2,1 → 1,2,3
//1,1,5 → 1,5,1

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void nextPermutation(int* nums, int numsSize){
    if(numsSize == 0)
        return;
    int i, j;
    /*从后往前找第一个后面比前面大的数*/
    for(i = numsSize - 2; i >= 0 && nums[i+1] <= nums[i]; i--);
    if(i >= 0){
        /*从后往前找第一个比nums[i]大的数*/
        for(j = numsSize - 1; j >= 0 && nums[j] <= nums[i]; j--);
        /*交换*/
        swap(&nums[i], &nums[j]);
    }
    /*翻转nums[i]以后的部分,即[i+1, numsSize-1]*/
    for(j = 0; j <= (numsSize - 2 - i) / 2; j++){
        swap(&nums[i+1+j], &nums[numsSize-1-j]);
    }
}


