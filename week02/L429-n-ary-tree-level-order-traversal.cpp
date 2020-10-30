// 题目链接：https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/
// 思路：用队列对树做层次遍历，关键是如何确定不同层之间的边界
// 每次将一层里所有的元素都加入队列，在下一轮循环里队列的大小即层的边界。
// 初始化是将 root 加入队列，注意对 root 是否为空做判断
// 算法复杂度：每个元素遍历一遍，复杂度为 O(N)

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int> > levelOrder(Node* root) {
        queue<Node*> que;
        vector<vector<int> > res;
        if(root != NULL) que.push(root);
        while (!que.empty()) {
            // 需要将每一层的大小先保存下来
            // 因为 que 的大小会不断变化
            int size = que.size();
            vector<int> row;
            for (int i = 0; i < size; i++) {
                Node* node = que.front();
                que.pop();
                row.push_back(node->val);
                for (int j = 0; j < node->children.size(); j++) {
                    que.push(node->children[j]);
                }
            }
            res.push_back(row);
        }
        return res;
    }
};

int main() {
    Node node5(5), node6(6), node4(4), node2(2);
    vector<Node*> children3;
    children3.push_back(&node5);
    children3.push_back(&node6);
    Node node3(3, children3);
    vector<Node*> children1;
    children1.push_back(&node3);
    children1.push_back(&node2);
    children1.push_back(&node4);
    Node node1(1, children1);

    cout << "expected result:" << endl;
    cout << "[1]," << endl;
    cout << "[3,2,4]," << endl;
    cout << "[5,6]" << endl;

    cout << endl << "actual result:" << endl;
    Solution s;
    vector<vector<int> > res = s.levelOrder(&node1);
    for (int i = 0; i < res.size(); i++) {
        cout << "[";
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j];
            if (j < res[i].size()-1) cout << ",";
        }
        cout << "]";
        if (i < res.size()-1) cout << ",";
        cout << endl;
    }

    return 0;
}