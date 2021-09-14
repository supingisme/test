/*
18. 四数之和
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例：

给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/
int comp(const void *a,const void *b)
{
    return *(int *)a - *(int *)b;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (numsSize == 0) {
        return 0;
    }
    int **ret = (int **)malloc(sizeof(int *) * (numsSize + 1) * 3);
    *returnSize = 0;
    short left = 0;
    short right = numsSize - 1;
    short begin = 0;
    short end = numsSize - 1;
    int loopTarget = 0;
    int subTarget = 0;
    
    *returnColumnSizes = malloc(sizeof(int) * (numsSize + 1) * 3);
    qsort(nums, numsSize, sizeof(int), comp);
    ret[*returnSize] = malloc(sizeof(int) * 4);
    
    while (begin + 2 < end) {
        left = begin + 1;
        right = end;
        loopTarget = target - nums[begin];
        while (left + 1 < right) {
            int i = left + 1;
            int j = right;
            subTarget = loopTarget - nums[left];
            while (i < j) {
                if (nums[i] + nums[j] < subTarget) {
                    i++;
                } else if (nums[i] + nums[j] > subTarget) {
                    j--;
                } else {
                    ret[*returnSize][0] = nums[begin];
                    ret[*returnSize][1] = nums[left];
                    ret[*returnSize][2] = nums[i];
                    ret[*returnSize][3] = nums[j];
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;
                    ret[*returnSize] = malloc(sizeof(int) * 4);

                    while(nums[i] == nums[++i] && i < j) {}
                    while(nums[j] == nums[--j] && i < j) {}
                }
            }
            while(nums[left] == nums[++left] && left + 1 < right) {}
        }
        while(nums[begin] == nums[++begin] && begin + 2 < end) {}
    }
    
    return ret;
}

