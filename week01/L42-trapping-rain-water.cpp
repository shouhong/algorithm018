#include <iostream>
#include <vector>
using namespace std;

// 解题思路：每根柱子的盛水量 = 等于其左右两边（包括它自己）
// 最大高度的较小值 - 其自身高度
// 遍历两遍数组，求出每个元素左边的最大高度和右边的最大高度
// 带入上面的公式进行计算 
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;
        int left[height.size()], right[height.size()];
        left[0] = height[0];
        for (int i = 1; i < height.size(); i++) {
            left[i] = height[i] > left[i-1] ? height[i] : left[i-1];
        }
        right[height.size()-1] = height[height.size()-1];
        for (int i = height.size()-2; i >= 0; i--) {
            right[i] = height[i] > right[i+1] ? height[i] : right[i+1];
        }
        int sum = 0;
        for (int i = 1; i < height.size()-1; i++) {
            int bar = left[i] > right[i] ? right[i] : left[i];
            sum += (bar - height[i]);
        }
        return sum;
    }
};

int main() {
    vector<int> height {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;
    cout << "expected result = 6, result = " << s.trap(height) << endl;
    height = {4,2,0,3,2,5};
    cout << "expected result = 9, result = " << s.trap(height) << endl;
    return 0;
}