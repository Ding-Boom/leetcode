// 题目: 岛屿数量
// 题号: 200
// 语言: c
// 提交时间: 2025-12-12 00:50:56

int numIslands(char** grid, int gridSize, int* gridColSize) {
    if (gridSize == 0 || gridColSize[0] == 0) return 0;
    
    int row = gridSize;
    int col = gridColSize[0];
    int count = 0;
    
    // 方向数组：下、上、右、左
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    // 遍历整个网格
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            // 发现新岛屿
            if (grid[i][j] == '1') {
                count++;
                
                // 创建队列用于BFS
                int* queueRow = (int*)malloc(sizeof(int) * row * col);
                int* queueCol = (int*)malloc(sizeof(int) * row * col);
                int front = 0, rear = 0;
                
                // 将当前陆地加入队列并标记为已访问
                queueRow[rear] = i;
                queueCol[rear] = j;
                rear++;
                grid[i][j] = '0';
                
                // BFS遍历整个岛屿
                while (front < rear) {
                    int currRow = queueRow[front];
                    int currCol = queueCol[front];
                    front++;
                    
                    // 检查四个方向
                    for (int d = 0; d < 4; d++) {
                        int newRow = currRow + directions[d][0];
                        int newCol = currCol + directions[d][1];
                        
                        // 检查边界条件和是否为陆地
                        if (newRow >= 0 && newRow < row && 
                            newCol >= 0 && newCol < col && 
                            grid[newRow][newCol] == '1') {
                            // 将新发现的陆地加入队列并标记为已访问
                            queueRow[rear] = newRow;
                            queueCol[rear] = newCol;
                            rear++;
                            grid[newRow][newCol] = '0';
                        }
                    }
                }
                
                // 释放队列内存
                free(queueRow);
                free(queueCol);
            }
        }
    }
    
    return count;
}