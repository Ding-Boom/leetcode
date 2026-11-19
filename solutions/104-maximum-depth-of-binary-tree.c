// 题目: 二叉树的最大深度
// 题号: 104
// 语言: c
// 提交时间: 2025-11-21 07:10:11

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    // 如果节点为空，深度为0
    if (root == NULL) {
        return 0;
    }
    
    // 递归计算左右子树深度，取较大值加1
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}