// 题目：2. 最长有效括号
// 链接：https://leetcode-cn.com/problems/longest-valid-parentheses/
// 思路1：括号匹配问题，一般用栈来解决，需要注意的是栈中存的不是字符，而是下标
//       通过匹配的下标相减来计算有效长度
// 思路2：动态规划

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int res = 0;
        // 初始：0 号元素的前一个元素编号为 -1
        st.push(-1);
        for (int i = 0; i < s.size(); i++) {
            // 左括号，下标直接入栈，等待右括号来匹配
            if (s[i] == '(') st.push(i);
            else {
                // 先弹出与当前右括号匹配的元素
                st.pop();
                if (st.empty()) {
                    // 如果弹出后栈为空，说明没有匹配的，
                    // 以当前右括号下标作为新的初始值
                    st.push(i);
                } else {
                    // 如果弹出后栈非空，说明有匹配的，
                    // 计算匹配的两个括号间的长度
                    res = max(res, i - st.top());
                }
            }
        }
        return res;
    }
};

class Solution_1 {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        int n = s.size();
        // 状态 dp[i] 以第 i 个字符结束的子串的最长有效括号数
        // 注意：一定要包含第 i 个字符
        // 比如 s[i] == '('，则 dp[i] = 0, 虽然 dp[i-1] 可能大于 0。
        // 初始化所有状态为 0， 后面只考虑不为 0 的情况 
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++) {
            if (s[i] == ')' ) {
                // 第一种不为 0 的情况：最后两个字符是 “()”
                // 则 dp[i] = dp[i-2] + 2;
                if (s[i-1] == '(') {
                    dp[i] = (i-2 >= 0 ? dp[i-2] : 0) + 2;
                // 第二种情况：最后两个字符是 “))”
                // 查看将s[i-1]匹配到的部分去掉后，是否能和最后“)”匹配上
                // 即 s[i - dp[i-1] - 1] 是否是 "("
                // 如果能匹配上，则 dp[i] 有三部分组成：
                // dp[i-1], dp[i - dp[i-1] - 2] 和新增加的 2
                } else {
                    if (i - dp[i-1] - 1 >= 0 && s[i - dp[i-1] - 1] == '(') {
                        dp[i] = dp[i-1] + (i - dp[i-1] - 2 >= 0 ? dp[i - dp[i-1] - 2] : 0) + 2;
                    }
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main() {
    Solution_1 sl;
    string s = ")()())";
    cout << sl.longestValidParentheses(s) << endl;
}