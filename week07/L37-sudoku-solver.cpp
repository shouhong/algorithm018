// 题目：37. 解数独
// 链接：https://leetcode-cn.com/problems/sudoku-solver/
// 思路：
// 1. 先提取除所有的需要填充的空格
// 3. 用三个数组分别标记每行、每列、每个 Block 中每个数字是否存在
// 2. 对每个空格尝试所有可能的数字，满足每行、每列、每个 Block 该数字还不存在

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool row[9][9];
    bool col[9][9];
    bool block[3][3][9];
    vector<pair<int, int>> spaces;
    bool valid = false;
public:
    void dfs(vector<vector<char>>& board, int pos) {
        // 递归结束条件：全部空格填写完毕
        if (pos == spaces.size()) {
            valid = true;
            return;
        }

        // 获取要填充的位置
        auto [i, j] = spaces[pos];
        // 尝试每一个可能的数字
        for (int k = 0; k < 9 && !valid; k++) {
            if (!row[i][k] && !col[j][k] && !block[i/3][j/3][k]) {
                row[i][k] = col[j][k] = block[i/3][j/3][k] = true;
                board[i][j] = k + '1';
                dfs(board, pos+1);
                // 回溯
                row[i][k] = col[j][k] = block[i/3][j/3][k] = false;
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(block, 0, sizeof(block));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    spaces.emplace_back(i, j);
                } else {
                    // 将 1-9 转为 0-8，方便 block 分区操作
                    int k = board[i][j] - '1';
                    row[i][k] = col[j][k] = block[i/3][j/3][k] = true;
                }
            }
        }
        dfs(board, 0);
    }
};


int main() {
    return 0;
}