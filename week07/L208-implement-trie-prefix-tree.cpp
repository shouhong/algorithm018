// 题目：208. 实现 Trie (前缀树)
// 链接：https://leetcode-cn.com/problems/implement-trie-prefix-tree/
// 思路: 
// 1. Trie 树就是一棵 26 叉树（26 是字母个数），每个节点代表一个字母
// 2. 每个节点存储了所有可能的下一个字母节点的指针（Trie* next[26];）
// 3. 每个节存储了是否是一个单词最后一个字母的标记（ bool isEnd; ）
// 4. 搜索一个单词是否在 Trie 树中存在的过程就是按单词的字母顺序从 Trie 树的
//    根节点开始对单词的每个字母一路查找下去
// 5. 如果找到且最后一个节点是单词的结尾，则搜索成功
// 6. 如果找到但最后一个节点不是单词的结尾，说明找到的是一个前缀。

#include <iostream>
#include <string>
using namespace std;

class Trie {
private:
    bool isEnd;
    Trie* next[26];
public:
    /** Initialize your data structure here. */
    Trie() {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            if (node->next[c - 'a'] == NULL) {
                node->next[c - 'a'] = new Trie();
            }
            node = node->next[c - 'a'];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for (char c : word) {
            if (node->next[c - 'a'] == NULL) {
                return false;
            }
            node = node->next[c - 'a'];
        }
        return node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char c : prefix) {
            if (node->next[c - 'a'] == NULL) {
                return false;
            }
            node = node->next[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
    Trie* obj = new Trie();
    string word = "hello";
    string prefix1 = "hel";
    string prefix2 = "hey";
    obj->insert(word);
    cout << obj->search(word) << endl;
    cout << obj->search(prefix1) << endl;
    cout << obj->startsWith(prefix1) << endl;
    cout << obj->startsWith(prefix2) << endl;
    return 0;
}