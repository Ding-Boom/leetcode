// 题目: 路径总和
// 题号: 112
// 语言: c
// 提交时间: 2025-11-21 11:20:31

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int targetSum) {
      // 空树情况
    if (root == NULL) {
        return false;
    }
    
    // 到达叶子节点时检查路径和是否等于目标值
    if (root->left == NULL && root->right == NULL) {
        return targetSum == root->val;
    }
    
    // 递归检查左右子树，更新剩余目标值
    int remaining = targetSum - root->val;
    return hasPathSum(root->left, remaining) || hasPathSum(root->right, remaining);
}