//33. 搜索旋转排序数组
//假设按照升序排序的数组在预先未知的某个点上进行了旋转。
//
//( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
//
//搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
//
//你可以假设数组中不存在重复的元素。
//
//你的算法时间复杂度必须是 O(log n) 级别。
//
//示例 1:
//
//输入: nums = [4,5,6,7,0,1,2], target = 0
//输出: 4
//示例 2:
//
//输入: nums = [4,5,6,7,0,1,2], target = 3
//输出: -1

//减治搜索范围
//根据上面对 mid 范围分析，我们有 100% 可能搜索区间一定在某个范围内，那么先确定这个能保证的范围，
//然后其他的都是反例。
//一定有序的区间就是图中【黄括号】内的区间，这里我们只处理能保证的 target1。
//
//确定有序区间，即确定 mid 分布在旋转点左侧还是右侧，这里是左侧，必定存在 nums[left] <= nums[mid]。
//为什么可以相等？即这个区间变成一个点，难道此时不应该为假吗？
//mid = left + (right - left) / 2; mid 选取是向下取整的，
//比如 [3,1],3,nums[mid] = 3直接返回 mid = 0，但是 [3, 1],1,nums[mid] != 1，
//而需要向右移动。（关于这点选取，在代码中条件判断等于情况内层判断也需要变动）
//nums[left] <= target < nums[mid]:这个时候查找的 target 就是图中 target1，
//因此下轮搜索区间就是 [left, mid-1]，否则其对立面就是 [mid + 1, right]
//没有必要 target <= nums[mid]，如果这样，那么这种一定找到了。虽然加上也没事。
//nums[left] <= target：有可能 target 就是等于 nums[left]呢？此时收缩右边界是没错的。
//
//作者：boille
//链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/jian-zhi-si-xiang-er-fen-zhi-ren-100que-ding-qu-ji/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

int search(int* nums, int numsSize, int target){
    int left = 0, right = numsSize - 1, mid;
    while (left <= right) {
        mid = left + (right - left) / 2;  // 防止溢出
        if (nums[mid] == target) return mid;
        if (nums[left] <= nums[mid]) {  // 等于处理单个不存在情况
            if (target < nums[mid] && target >= nums[left]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            if (target > nums[mid] && nums[right] >= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return -1;
}

