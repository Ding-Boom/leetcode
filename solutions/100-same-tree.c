// 题目: 相同的树
// 题号: 100
// 语言: c
// 提交时间: 2025-11-21 06:49:30

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    // 如果两个节点都为空，则相同
    if (p == NULL && q == NULL) {
        return true;
    }
    
    // 如果只有一个节点为空，则不同
    if (p == NULL || q == NULL) {
        return false;
    }
    
    // 如果节点值不同，则不同
    if (p->val != q->val) {
        return false;
    }
    
    // 递归检查左子树和右子树是否都相同
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}