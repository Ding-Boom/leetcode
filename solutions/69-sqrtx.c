// 题目: x 的平方根 
// 题号: 69
// 语言: c
// 提交时间: 2025-12-18 11:17:24

#define SQRT_INT_MAX ((int) sqrt(INT_MAX))
#define MIN(a, b) ((b) < (a) ? (b) : (a))

int mySqrt(int x) {
    // 开区间 (left, right)
    int left = 0, right = MIN(x, SQRT_INT_MAX) + 1;
    while (left + 1 < right) { // 开区间不为空
        // 循环不变量：left^2 <= x
        // 循环不变量：right^2 > x
        int m = (left + right) / 2;
        if (m * m <= x) {
            left = m;
        } else {
            right = m;
        }
    }
    // 循环结束时 left+1 == right
    // 此时 left^2 <= x 且 right^2 > x
    // 所以 left 最大的满足 m^2 <= x 的数
    return left;
}