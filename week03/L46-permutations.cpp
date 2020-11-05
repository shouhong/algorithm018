// 题目：https://leetcode-cn.com/problems/permutations/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
private:
    vector<vector<int> > res;
    set<int> used;
    vector<int> tmp;
    // 全排列基本思路：从头到尾，对每个位置尝试不同的元素
    // 方法1: 每次遍历一遍，尝试每个还没有被使用过的元素
    // 用一个 set 来记录元素是否被使用过
    void dfs_perm1(int cur, vector<int>& nums) {
        if (cur == nums.size()) {
            res.push_back(tmp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!used.count(nums[i])) {
                used.insert(nums[i]);
                tmp.push_back(nums[i]);
                dfs_perm1(cur+1, nums);
                tmp.pop_back();
                used.erase(nums[i]);
            }
        }
    }
    // 方法2: 将要尝试的元素交换到指定位置
    // 这种方法效率更高
    void dfs_perm2(int cur, vector<int>& nums) {
        if (cur == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = cur; i < nums.size(); i++) {
            // 当前位置尝试用第 i 个元素
            swap(nums[cur], nums[i]);
            dfs_perm2(cur+1, nums);
            // 回溯，将尝试的元素换回去
            swap(nums[cur], nums[i]);
        }
    }
public:
    vector<vector<int> > permute(vector<int>& nums) {
        dfs_perm2(0, nums);
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums;
    for (int i = 1; i <= 3; i++) {
        nums.push_back(i);
    }
    vector<vector<int> > res = s.permute(nums);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}