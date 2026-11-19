// 题目: 三角形最小路径和
// 题号: 1000286
// 语言: c
// 提交时间: 2025-11-21 07:01:30



int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
// 从倒数第二行开始向上计算
       for (int i = triangleSize - 2; i >= 0; i--) {
        for (int j = 0; j < triangleColSize[i]; j++) {
            // 当前值加上下一行相邻两个位置中较小的路径和
            triangle[i][j] += (triangle[i+1][j] < triangle[i+1][j+1]) ? 
                             triangle[i+1][j] : triangle[i+1][j+1];
        }
    }
    return triangle[0][0];
}