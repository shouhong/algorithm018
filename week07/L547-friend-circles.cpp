// 题目：547. 朋友圈
// 链接：https://leetcode-cn.com/problems/friend-circles/
// 思路：并查集模版题

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> parent;
public:
    int find(int x) {
        if (parent[x] == x) return x;
        parent[x] = find(parent[x]); // 路径压缩
        return parent[x];
    }
    int findCircleNum(vector<vector<int>>& M) {
        int res = M.size();
        // 初始化：每个人一个朋友圈
        for (int i = 0; i < M.size(); i++) {
            parent.push_back(i);
        }
        for (int i = 0; i < M.size(); i++) {
            for (int j = 0; j < M.size(); j++) {
                // 合并有朋友关系的人到同一个朋友圈
                if (M[i][j] == 1) {
                    int fx = find(i), fy = find(j);
                    // 已经在一个圈里的就不用再合并了
                    // 每合并一下，朋友圈数量减一
                    if (fx != fy) {
                        parent[fx] = fy;
                        res--;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
   vector<vector<int>> M = {{1,1,0},{1,1,0},{0,0,1}};
   Solution sl;
   cout << sl.findCircleNum(M) << endl;
   return 0;
}