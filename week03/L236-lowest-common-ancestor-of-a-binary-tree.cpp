// 题目：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
// 思路：节点 root 是 p, q 最近公共祖先有两种情况：
//（1）root = p 或 q 并且另一个节点在 root 的左子树或右子树里
//（2）p 和 q 分别在 root 的左右子树里
// 需要用一个递归函数来判断 p 或 q 是否在这棵树里即可

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *ans;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return false;

        bool inCurNode = (root->val == p->val) || (root->val == q->val);
        bool inLeftTree = dfs(root->left, p, q);
        bool inRightTree = dfs(root->right, p, q);
        if ((inCurNode && (inLeftTree || inRightTree)) || (inLeftTree && inRightTree)) {
            ans = root;
        }
        return inCurNode || inLeftTree || inRightTree;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};

int main() {
    TreeNode* s[9];
    for (int i = 0; i <=8; i++) {
        s[i] = new TreeNode(i);
    }
    s[2]->left = s[7];
    s[2]->right = s[4];
    s[1]->left = s[0];
    s[1]->right = s[8];
    s[5]->left = s[6];
    s[5]->right = s[2];
    s[3]->left = s[5];
    s[3]->right = s[1];

    Solution sl;
    TreeNode* lca = sl.lowestCommonAncestor(s[3], s[6], s[4]);

    cout << "expected result: 5" << endl;
    cout << "actual result: " << lca->val << endl;
    
    return 0; 
}