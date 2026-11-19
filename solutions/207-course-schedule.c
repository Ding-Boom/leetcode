// 题目: 课程表
// 题号: 207
// 语言: c
// 提交时间: 2025-12-12 00:55:57

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    // 构建邻接表和入度数组
    int** graph = (int**)malloc(numCourses * sizeof(int*));
    int* graphSize = (int*)calloc(numCourses, sizeof(int));
    int* indegree = (int*)calloc(numCourses, sizeof(int));
    
    // 为每个课程分配邻接表空间（临时分配，稍后调整）
    for (int i = 0; i < numCourses; i++) {
        graph[i] = (int*)malloc(prerequisitesSize * sizeof(int));
    }
    
    // 构建图：prerequisites[i] = [a, b] 表示 b -> a（需要先修b才能修a）
    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];  // 目标课程
        int b = prerequisites[i][1];  // 先修课程
        graph[b][graphSize[b]++] = a; // 添加边 b->a
        indegree[a]++;                // a的入度加1
    }
    
    // 初始化队列，存储入度为0的节点
    int* queue = (int*)malloc(numCourses * sizeof(int));
    int front = 0, rear = 0;
    
    // 将所有入度为0的节点加入队列
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }
    
    int visitedCount = 0; // 记录已访问（拓扑排序）的节点数
    
    // 拓扑排序：每次从队列中取出入度为0的节点
    while (front < rear) {
        int current = queue[front++];
        visitedCount++;
        
        // 遍历当前节点的所有邻居（后继节点）
        for (int i = 0; i < graphSize[current]; i++) {
            int neighbor = graph[current][i];
            indegree[neighbor]--; // 邻居节点的入度减1
            
            // 如果邻居节点的入度变为0，加入队列
            if (indegree[neighbor] == 0) {
                queue[rear++] = neighbor;
            }
        }
    }
    
    // 释放内存
    for (int i = 0; i < numCourses; i++) {
        free(graph[i]);
    }
    free(graph);
    free(graphSize);
    free(indegree);
    free(queue);
    
    // 如果访问过的节点数等于总节点数，说明拓扑排序成功，没有环
    return visitedCount == numCourses;
}