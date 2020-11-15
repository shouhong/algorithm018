// 题目：33. 搜索旋转排序数组
// 链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
// 思路：
// 1. 数组二分以后，肯定有一半是有序的
// 2. 判读是否有序：首元素是否小于尾元素
// 3. 在有序的一半里容易判断 target 是否在里面，如果不在，就肯定在另一半里
// 4. 找到 target 所在的部分，接着往下二分就行了

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        if (n == 1) {
            return target == nums[0] ? 0 : -1;
        }
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r)/2;
            if (nums[mid] == target) return mid;
            // 注意：l 可能和 mid 相等，所以下面的判断条件是 <=, 而不是 <
            if (nums[l] <= nums[mid]) {
                if (target >= nums[l] && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    //vector<int> nums = {4,5,6,7,0,1,2};
    //int target = 0;
    vector<int> nums = {3,1};
    int target = 1;
    Solution s;
    cout << s.search(nums, target) << endl;
    return 0;
}