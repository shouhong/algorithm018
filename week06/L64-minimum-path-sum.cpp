// 题目：64. 最小路径和
// 链接：https://leetcode-cn.com/problems/minimum-path-sum/
// 思路：动态规划
// 状态转移方程：dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
// 结果：

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dp[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[0][0] = grid[0][0];
                    continue;
                }
                int tmp = INT_MAX;
                if (i > 0) tmp = min(tmp, dp[i-1][j]);
                if (j > 0) tmp = min(tmp, dp[i][j-1]);
                dp[i][j] = tmp + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    cout << s.minPathSum(grid) << endl;
    return 0;
}