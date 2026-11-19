// 题目: 克隆图
// 题号: 133
// 语言: c
// 提交时间: 2025-12-12 00:43:38

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */

struct Node* dfsClone(struct Node* s, struct Node** visited) {
    if (s == NULL) return NULL;
    
    // 如果节点已经访问过，直接返回克隆节点
    if (visited[s->val] != NULL) {
        return visited[s->val];
    }
    
    // 创建新节点
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = s->val;
    newNode->numNeighbors = s->numNeighbors;
    visited[s->val] = newNode;
    
    // 分配邻居数组空间
    if (newNode->numNeighbors > 0) {
        newNode->neighbors = (struct Node**)malloc(sizeof(struct Node*) * newNode->numNeighbors);
        
        // 递归克隆邻居节点
        for (int i = 0; i < s->numNeighbors; i++) {
            newNode->neighbors[i] = dfsClone(s->neighbors[i], visited);
        }
    } else {
        newNode->neighbors = NULL;
    }
    
    return newNode;
}

struct Node *cloneGraph(struct Node *s) {
    // 创建访问数组，题目说明节点值在1-100之间，且唯一
    struct Node** visited = (struct Node**)calloc(101, sizeof(struct Node*));
    
    struct Node* result = dfsClone(s, visited);
    
    free(visited);
    return result;
}