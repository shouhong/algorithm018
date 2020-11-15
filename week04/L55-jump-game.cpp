// 题目：55. 跳跃游戏
// 链接：https://leetcode-cn.com/problems/jump-game/
// 思路：贪心算法
// 1. 从前往后，计算每个元素能够到达的最远位置，如果超过整体最远位置，则更新整体最远位置
// 2. 如果整体最远位置到达或超过数组最后一个元素，则能够跳到。
// 3. 注意：如果当前元素超过了当前的整体最远位置，则这个位置及后面的位置都走不到，直接退出。

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxPos = 0;
        for (int i = 0; i < nums.size() && i <= maxPos; i++) {
            maxPos = max(maxPos, i+nums[i]);
            if (maxPos >= nums.size()-1) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    vector<int> nums = {2,3,1,1,4};
    //vector<int> nums = {3,2,1,0,4};
    Solution s;
    cout << s.canJump(nums) << endl;
    return 0;
}