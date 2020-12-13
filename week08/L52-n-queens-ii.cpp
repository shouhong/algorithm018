// 题目：52. N皇后 II
// 链接：https://leetcode-cn.com/problems/n-queens-ii/
// 思路:
// 1. 使用常规深度优先一层层搜索
// 2. 使用三个整形分别标记每一层哪些格子可以放置皇后，这三个整形分别代表
//    列、左斜下、右斜下（col, ld, rd），二进制位为 1 代表不能放置，0 代表可以放置
// 3. 核心两个位运算：
//   (1) x & -x 代表除最后一位 1 保留，其它位全部为 0
//   (2) x & (x - 1) 代表将最后一位 1 变成 0
// 4. 数的存储用补码：正数的补码为自身，负数的补码为其反码+1

#include <iostream>
using namespace std;

class Solution {
private:
    int res = 0;
    void dfs(int n, int row, int col, int ld, int rd) {
        if (row >= n) {
            res++;
            return;
        }

        int bits = ~(col | ld | rd) & ((1 << n) - 1);
        while (bits > 0) {
            int pick = bits & -bits;
            dfs(n, row+1, col | pick, (ld | pick) << 1, (rd | pick) >> 1);
            bits &= (bits - 1);
        }
    }
public:
    int totalNQueens(int n) {
        dfs(n, 0, 0, 0, 0);
        return res;
    }
};

int main() {
    Solution sl;
    cout << sl.totalNQueens(4) << endl;
    return 1;
}