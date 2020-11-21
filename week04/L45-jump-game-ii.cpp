// 题目：45. 跳跃游戏 II
// 链接：https://leetcode-cn.com/problems/jump-game-ii/
// 思路：贪心算法
// 1. 从前往后，计算每个元素能够到达的最远位置，如果超过整体最远位置，则更新整体最远位置
// 2. 如果整体最远位置到达或超过数组最后一个元素，则结束。
// 3. 注意：如果当前元素超过了当前的整体最远位置，则这个位置及后面的位置都走不到，直接退出。
// 4. 步数统计：记住每轮能够扫描到的最远位置，当前元素位置到达这个位置的时候，步数加一，进入下一轮。

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        // preMaxPos 用于保存上一轮扫描范围
        int preMaxPos = 0; 
        int maxPos = 0;
        int steps = 0;
        // 注意是 n < nums.size() - 1，不是 n < nums.size() 
        // 对于只有一个元素的情况，不会进入 for 循环，返回 0（不用跳）
        // 如果是  n < nums.size() ，则会进入 for 循环，返回错误值 1
        for (int i = 0; i < nums.size() - 1  && i <= maxPos; i++) {
            maxPos = max(maxPos, i+nums[i]);
            // 可以到达最后一个元素，结束
            if (maxPos >= nums.size()-1) {
                return steps+1;
            }
            // 上一轮扫描范围结束，更新步数
            if (i == preMaxPos) {
                preMaxPos = maxPos;
                steps++;
            }
        }
        return 0;
    }
};

int main() {
    vector<int> nums = {2,3,1,1,4};
    //vector<int> nums = {3,2,1,0,4};
    Solution s;
    cout << s.jump(nums) << endl;
    return 0;
}