// 题目: 二叉树的中序遍历
// 题号: 94
// 语言: c
// 提交时间: 2025-11-21 06:39:29

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    // 如果树为空，直接返回空数组
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    
    // 分配存储结果的数组（最大100个节点）
    int* result = (int*)malloc(100 * sizeof(int));
    int index = 0;
    
    // 递归函数进行中序遍历
    void traverse(struct TreeNode* node) {
        if (node == NULL) return;
        
        // 中序遍历：左 -> 根 -> 右
        traverse(node->left);      // 递归遍历左子树
        result[index++] = node->val; // 访问根节点
        traverse(node->right);     // 递归遍历右子树
    }
    
    traverse(root);
    *returnSize = index;
    return result;
}