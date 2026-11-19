// 题目: 二叉树的最小深度
// 题号: 111
// 语言: c
// 提交时间: 2025-11-21 11:16:00

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    
    // 如果左子树为空，只计算右子树深度
    if (root->left == NULL) {
        return minDepth(root->right) + 1;
    }
    
    // 如果右子树为空，只计算左子树深度
    if (root->right == NULL) {
        return minDepth(root->left) + 1;
    }
    
    // 如果左右子树都存在，取较小深度
    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);
    
    return (leftDepth < rightDepth ? leftDepth : rightDepth) + 1;
}