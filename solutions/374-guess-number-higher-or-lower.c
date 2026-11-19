// 题目: 猜数字大小
// 题号: 374
// 语言: c
// 提交时间: 2025-12-18 11:19:35

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int guess(int num);
int guessNumber(int n) {
    int left = 1, right = n;
    while (left < right) {  // 循环直至区间左右端点相同
        int mid = left + (right - left) / 2;  // 防止计算时溢出
        if (guess(mid) <= 0) {
            right = mid;  // 答案在区间 [left, mid] 中
        } else {
            left = mid + 1;  // 答案在区间 [mid+1, right] 中
        }
    }
    // 此时有 left == right，区间缩为一个点，即为答案
    return left;
}