// 题目: 将有序数组转换为二叉搜索树
// 题号: 108
// 语言: c
// 提交时间: 2025-11-21 07:16:24

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    // 基准情况：空数组
    if (numsSize == 0) {
        return NULL;
    }
    
    // 创建根节点，值为中间元素
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int mid = numsSize / 2;
    root->val = nums[mid];
    
    // 递归构建左子树（左半部分数组）
    root->left = sortedArrayToBST(nums, mid);
    
    // 递归构建右子树（右半部分数组）
    root->right = sortedArrayToBST(nums + mid + 1, numsSize - mid - 1);
    
    return root;
}