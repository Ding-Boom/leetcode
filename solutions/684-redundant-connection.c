// 题目: 冗余连接
// 题号: 684
// 语言: c
// 提交时间: 2025-12-12 01:12:33

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    // 初始化返回数组
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    
    // 创建并查集，节点编号从1到n
    int parent[edgesSize + 1];
    for (int i = 1; i <= edgesSize; i++) {
        parent[i] = i;
    }
    
    // 查找函数（带路径压缩）
    int find(int x) {
        while (parent[x] != x) {
            // 路径压缩
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    
    // 合并函数
    int unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) {
            return 0; // 已经在同一个集合中，说明这条边形成了环
        }
        
        parent[rootX] = rootY;
        return 1; // 合并成功
    }
    
    // 遍历所有边
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        // 如果合并失败，说明这条边形成了环
        if (!unionSet(u, v)) {
            result[0] = u;
            result[1] = v;
            return result;
        }
    }
    
    // 理论上不会执行到这里，因为题目保证一定存在冗余边
    return result;
}