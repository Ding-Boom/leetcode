// 题目: 搜索插入位置
// 题号: 35
// 语言: c
// 提交时间: 2025-12-18 11:14:24

int searchInsert(int* nums, int numsSize, int target) {
    int left =0;
    int right =numsSize-1;
    int middle;
    while(left<=right){
        middle=(left+right)/2;
        if(target>nums[middle]){
            left=middle+1;
        }
        else if(target<nums[middle]){
            right=middle-1;
        }
        else{
            return middle;
        }
    }
    return left;
}
