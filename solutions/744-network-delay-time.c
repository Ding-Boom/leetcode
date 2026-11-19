// 题目: 网络延迟时间
// 题号: 744
// 语言: c
// 提交时间: 2025-12-12 01:27:44

int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k){
    // 初始化邻接矩阵
    int** graph = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            graph[i][j] = (i == j) ? 0 : INT_MAX;
        }
    }
    
    // 构建邻接矩阵
    for (int i = 0; i < timesSize; i++) {
        int u = times[i][0] - 1;  // 转换为0-based索引
        int v = times[i][1] - 1;
        int w = times[i][2];
        graph[u][v] = w;
    }
    
    // Dijkstra算法
    int* dist = (int*)malloc(sizeof(int) * n);
    int* visited = (int*)malloc(sizeof(int) * n);
    
    // 初始化距离数组和访问标记
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[k-1] = 0;  // 起点距离为0
    
    // 遍历所有节点
    for (int count = 0; count < n; count++) {
        // 找到未访问节点中距离最小的节点
        int minDist = INT_MAX;
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }
        
        // 如果没有找到可达的未访问节点，说明有节点不可达
        if (u == -1) {
            break;
        }
        
        visited[u] = 1;  // 标记为已访问
        
        // 更新邻居节点的距离
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != INT_MAX && 
                dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    
    // 找到最大距离
    int maxDist = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) {
            // 有节点不可达
            maxDist = -1;
            break;
        }
        if (dist[i] > maxDist) {
            maxDist = dist[i];
        }
    }
    
    // 释放内存
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
    free(dist);
    free(visited);
    
    return maxDist;
}