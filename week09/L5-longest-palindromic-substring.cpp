// 题目：5. 最长回文子串
// 链接：https://leetcode-cn.com/problems/longest-palindromic-substring/
// 思路：动态规划
// 状态：dp(i,j) 以 i 为起点，j 为终点的字符串是否是回文字符串
// 状态转移方程：dp(i, j) = s[i] == s[j] && dp(i+1, j-1)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0 || n == 1) return s;
        vector<vector<bool>> dp(n, vector<bool>(n));
        int start = 0;
        int maxLen = 1;
        // 初始化，设置长度为 1 和 2 的子串的状态
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            if (i < n - 1 && s[i] == s[i+1]) {
                dp[i][i+1] = true;
                start = i;
                maxLen = 2;
            }
        }
        // 遍历长度从 3 到 n 的子串，判断是否是回文
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;
                // 状态转移
                if (s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    start = i;
                    maxLen = len;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};

int main() {
    Solution sl;
    cout << sl.longestPalindrome("cbbd") << endl;
    return 0;
}