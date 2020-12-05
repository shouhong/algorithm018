// 题目：212. 单词搜索 II
// 链接：https://leetcode-cn.com/problems/word-search-ii/
// 思路：
// 1. 先对列表里单词建一个 Trie 树，便于查找
// 2. 再对 board 中从每个位置开始的根据规则可能形成的单词
//    到 Trie 树中查找，看是否能找到

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Trie {
public:
    string word = "";
    vector<Trie*> next;
    Trie() : next(26, 0) {}
};

class Solution {
private:
    vector<string> res;
    int row, col;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        row = board.size();
        col = row == 0 ? 0 : board[0].size();
        if (row == 0 && col == 0) return res;

        // 构造 Trie 树，将 words 里的单词添加进去
        Trie* root = new Trie();
        for (string word : words) {
            Trie* node = root;
            for (char c : word) {
                if (node->next[c - 'a'] == NULL) {
                    node->next[c - 'a'] = new Trie();
                }
                node = node->next[c - 'a'];
            }
            node->word = word;
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // 对 board 中从每个位置开始的根据规则可能形成的单词
                // 到 Trie 树中查找，看是否能找到
                dfs(board, root, i, j);
            }
        }

        return res;
    }

    void dfs(vector<vector<char>>& board, Trie* node, int x, int y) {
        char c = board[x][y];
        // 递归终止条件1：但字母已经被检查过，或在 Trie 树中不存在
        if (c == '.' || node->next[c - 'a'] == NULL) return;
        // 递归终止条件2：找到了匹配的单词
        // Trie 树的根节点是个虚几点，不代表任何字母，所以需要先往下走一步，
        // 再判断当前字母是否是一个单词的最后一个字母
        node = node->next[c - 'a'];
        if (node->word != "") {
            res.push_back(node->word);
            // 重要：标记该单词已经被找到过，避免重复
            node->word = "";
            return;
        }

        // 标记当前位置已经被检查过
        board[x][y] = '.';
        
        // 按规则向下递归
        if (x > 0) dfs(board, node, x-1, y);
        if (x < row-1) dfs(board, node, x+1, y);
        if (y > 0) dfs(board, node, x, y-1);
        if (y < col-1) dfs(board, node, x, y+1);
    
        // 回溯
        board[x][y] = c;
    }
};

int main() {
    vector<vector<char>> board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    vector<string> words = {"oath","pea","eat","rain"};
    Solution sl;
    vector<string> res = sl.findWords(board, words);
    for (string s : res) {
        cout << s << endl;
    }
    return 0;
}

