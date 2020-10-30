// 1. 题目：剑指 Offer 49. 丑数
// 2. 链接：https://leetcode-cn.com/problems/chou-shu-lcof/
// 思路：
// 1. 每个丑数都是由排在它前面的某个丑数 X2, X3 或 X5 产生的
// 2. 递推公式为：dp[i] = min(dp[a]*2, dp[b]*3, dp[c]*5)
// 3. 现在考虑有 n-1 个丑数组成的序列，求第 n 个丑数
// 假设有 a，b, c 三个指针，分别从头开始遍历已有的丑数，
// a 指针指向的数 X2，b 指针指向的数 X3，c 指针指向的数 X5
// 算出的大于第 n-1 个丑数的结果中，最小的那个就是答案。
// 4. 初始化 a = b = c = 0, dp[0] = 1, 模拟上面的过程就
// 可以从小到大逐个求出整个丑数序列。
// 5. 后面的计算会利用前面的结果，总共经历了 3 次遍历，时间复杂度为 O(N)。

#include <iostream>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        int a = 0, b = 0, c = 0;
        int dp[n];
        dp[0] = 1;
        int k = 1; 
        while (k < n) {
            dp[k] = min(dp[a]*2, min(dp[b]*3, dp[c]*5));
            // 下一个丑数是哪个指针指向的数算出的，这个指针就可以前进一步，遍历下一个元素了
            // 注意：可能有多个指针同时满足，不能用 if -- else if -- else if
            if (dp[k] == dp[a]*2) a++;
            if (dp[k] == dp[b]*3) b++;
            if (dp[k] == dp[c]*5) c++;
            k++;
        }
        return dp[n-1];
    }
};

int main() {
    int n = 10;
    Solution s;
    int res = s.nthUglyNumber(n);

    cout << "expected result:" << endl;
    cout << "12" << endl << endl;

    cout << "actual result:" << endl;
    cout << res << endl;
    return 0;
}