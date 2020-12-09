// 题目：56. 合并区间
// 链接：https://leetcode-cn.com/problems/merge-intervals/
// 思路：先按每个区间左边界由小到大排序，然后逐个比较已合并的最后一个区间
//      的右边界与下一个区间的左边界，以此判断是否有重叠。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            int L = intervals[i][0], R = intervals[i][1];
            if (!res.size() || res.back()[1] < L) {
                res.push_back({L, R});
            } else {
                // 有重叠的情况下，有交叉和完全包含两种情况
                res.back()[1] = max(res.back()[1], R);
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    Solution sl;
    vector<vector<int>> res = sl.merge(intervals);
    for (int i = 0; i < res.size(); i++) {
        cout << "[" << res[i][0] << ", " << res[i][1] << "]" << endl;
    }
    return 1;
}