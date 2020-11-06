// 题目：https://leetcode-cn.com/problems/combinations/

#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    set<int> s;
    vector<int> v;
    vector<vector<int> > res;
    // 全排列：1 到 k 个位置，每个位置从 1 - n 中选择一个数来填充
    // 用一个 set 保证选择不重复
    void dfs_perm(int cur, int n, int k) {
        if (cur > k) {
            res.push_back(v);
            return;
        }

        for (int i = 1; i <= n; i++) {
            if (!s.count(i)) {
                s.insert(i);
                v.push_back(i);
                dfs_perm(cur+1, n, k);
                v.pop_back();
                s.erase(i);
            }
        }
    }
    // 组合：1 - n 个数，每个数有选择和不选择两种情况
    void dfs_comb(int cur, int n, int k) {
        // 剪枝：剩余的数全部用完也达不到 k 了
        if (v.size() + (n - cur + 1) < k) {
            return;
        }

        if (v.size() == k) {
            res.push_back(v);
            return;
        }

        // 选择当前元素
        v.push_back(cur);
        dfs_comb(cur+1, n, k);
        // 回溯
        v.pop_back();
        // 不选择当前元素
        dfs_comb(cur+1, n, k);
    }
    vector<vector<int> > combine(int n, int k) {
        dfs_comb(1, n, k);
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int> > res = s.combine(3, 2);
    for (int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}