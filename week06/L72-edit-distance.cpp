// 题目：72. 编辑距离
// 链接：https://leetcode-cn.com/problems/edit-distance/
// 思路：动态规划
// 状态：dp[i][j]: 从第一个单词前 i 个字符组成的子串变换到第二个单词前 j 个
//      字符组成的子串需要的变换次数

// dp[i][j] 可以从 dp[i-1][j-1], dp[i][j-1], dp[i-1][j]三种状态之一变换而来
//（1）假设已知 dp[i][j-1], 即目标还少一个字符，增加一步插入操作即可，所以：dp[i][j] = dp[i][j-1] + 1
//（2）假设已知 dp[i-1][j], 要求 dp[i][j], 可以先执行一步删除操作，将问题转换为 dp[i-1][j]，
//     所以： dp[i][j] = dp[i-1][j] + 1
//（3）假设已知 dp[i-1][j-1], 
//    如果 word1[i] == word2[j], 则最后一个字符不需要变换，所以：dp[i][j] = dp[i-1][j-1]；
//    如果 word1[i] != word2[j], 可以先对 word1 最后一个字符执行一次替换操作，使 word1[i] == word2[j]
//         从而转换为第一个种情况，所以：dp[i][j] = dp[i-1][j-1] + 1；
// 最终结果是上面三种情况里取最优。

// 初始条件：
// dp[0][0] = 0; // 不用变换
// dp[i][0] = i; // 删除 i 个字符
// dp[0][j] = j; // 插入 j 个字符

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int dp[n+1][m+1];
        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= m; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int left = dp[i][j-1] + 1;
                int up = dp[i-1][j] + 1;
                int left_up = dp[i-1][j-1];
                if (word1[i-1] != word2[j-1]) left_up++;
                dp[i][j] = min(left_up, min(left, up));
            }
        }
        return dp[n][m];
    }
};

int main() {
    Solution s;
    string word1 = "horse", word2 = "ros";
    cout << s.minDistance(word1, word2) << endl;
}