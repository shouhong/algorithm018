// 题目：10. 正则表达式匹配
// 链接：https://leetcode-cn.com/problems/regular-expression-matching/
// 思路：动态规划
// 状态：dp(i, j): s 中前 i 个字符的字串是否与 p 中 前 j 个字符的字串匹配
// (1) p[j] != "*": dp(i, j) = matches(i, j) && dp(i-1, j-1)
// (2) p[j] == "*": 
//     （A）匹配 0 次：  dp(i, j) = dp(i, j-2) 
//     （B）匹配 1-N 次：dp(i, j) = maches(i, j-1) && dp(i-1, j)
// 初始状态：
//（1）f(0,0) = true; // 都为空能够匹配上
//（2）f(1-m,0) = false // s 有值，p 为空，肯定匹配不上，j 为 0 的情况用缺省值，不用循环计算了。
//（3）f(0,1-n) // s 为空，p 有值，true 和 false 都有可能（需要循环计算），如 p 值为 “a*”，a 出现 0 次。
// 所以循环时，i 从 0 开始，j 从 1 开始。

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    bool maches(int i, int j, string s, string p) {
        if (i == 0) return false;
        if (p[j-1] == '.') return true;
        return s[i-1] == p[j-1];
    }
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1));
        
        dp[0][0] = true;
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j-1] != '*') {
                    // 如果最后一个字符能够匹配，则看前面的匹配结果
                    if (maches(i, j, s, p)) 
                        dp[i][j] = dp[i-1][j-1];
                } else {
                    // 模拟星号组合匹配零次的情况，直接消掉这个组合，当作不存在
                    dp[i][j] = dp[i][j-2];
                    if (maches(i, j-1, s, p)) 
                        // 模拟星号组合匹配 1 次的情况，直接消掉被匹配的字符，星号组合保留，可以继续往后匹配
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution sl;
    // cout << sl.isMatch("aa", "a*") << endl;
    cout << sl.isMatch("aasdfasdfasdfasdfas", "aasdf.*asdf.*asdf.*asdf.*s") << endl;
    return 0;
}