// 题目: 平衡二叉树
// 题号: 110
// 语言: c
// 提交时间: 2025-11-21 11:10:41

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// 辅助函数，检查子树是否平衡并返回高度
int checkHeight(struct TreeNode* root) {
    if (root == NULL) return 0;
    
    // 检查左子树
    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1) return -1;
    
    // 检查右子树
    int rightHeight = checkHeight(root->right);
    if (rightHeight == -1) return -1;
    
    // 检查当前节点是否平衡
    if (abs(leftHeight - rightHeight) > 1) return -1;
    
    // 返回当前节点高度
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

bool isBalanced(struct TreeNode* root) {
     return checkHeight(root) != -1;
}