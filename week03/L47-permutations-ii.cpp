// 题目：https://leetcode-cn.com/problems/permutations-ii/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<vector<int> > res;
    vector<int> perm;
    vector<bool> vis;
    // 全排列：对元素有重复的情况，与普通全排列的区别：
    // 1. 先对数组排序，让相同的元素排在一起
    // 2. 排列过程中如果某个元素与前一个元素相同，且前一个元素没有在其它位置被使用
    // 说明前一个元素在当前位置已经被尝试过了，当前元素与其相同，再尝试就重复了，需要跳过。
    void dfs_permUni(int cur, vector<int>& nums) {
        if (cur == nums.size()) {
            res.push_back(perm);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (vis[i] || ((i > 0) && (nums[i] ==  nums[i-1]) && (!vis[i-1]))) {
                continue;
            }
            perm.push_back(nums[i]);
            vis[i] = true;
            dfs_permUni(cur+1, nums);
            perm.pop_back();
            vis[i] = false;
        }
    }
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vis.resize(nums.size());
        sort(nums.begin(), nums.end());
        dfs_permUni(0, nums);
        return res;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    Solution s;
    vector<vector<int> > res = s.permuteUnique(nums);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

