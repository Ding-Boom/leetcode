// 题目: 二分查找
// 题号: 792
// 语言: c
// 提交时间: 2025-12-18 11:10:43

int search(int* nums, int numsSize, int target){
    int left = 0, right = numsSize - 1;
    while (left <= right) {
        int middle = left + ((right - left) / 2);
        if (nums[middle] > target) {
            right = middle - 1;
        } else if (nums[middle] < target) {
            left = middle + 1;
        } else {
            return middle;
        }
    }
    return -1;
}
