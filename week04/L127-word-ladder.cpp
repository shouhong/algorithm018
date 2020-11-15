// 题目：https://leetcode-cn.com/problems/word-ladder/
// 思路：
// 1. 把每个单词当作图中一个节点，这道题就变成求图中两点间最短路径的问题
// 2. 关键是如何判断两个单词之间是否有边（从一个单词能一步变换到另一个单词）？
// 3. 这里通过引入虚拟节点来解决，如 hit 的虚拟节点有：*it, h*t, hi*
// 4. 每个单词和它的虚拟节点是直接相连的，能够一步变换到的两个单词会连接到相同的虚拟节点，
// 这样就间接将能够一步变换到的两个单词连接了起来，只不过路径长度翻倍了。
// 5. 用 BFS 从起始单词开始遍历图，求出终止单词的距离即可。实际距离是“求出的距离/2+1”，
// 加 1 是为了将起始单词算上。
// 6. 优化：BFS 随着遍历深度的增加，宽度呈指数级增长（扇形展开），可以从起始和终止两个方向
// 同时做 BFS，有效减少搜索宽度。
// 7. 其它优化：这里操作的元素是字符串，可以用一个 map 为每个字符串分配一个 id，
// 后面队列、距离等都可以用 id 来存储。BFS 时，可以将元素到起始点的距离初始化为 INT_MAX,
// 判断某个元素是否被访问过，可以通过距离是否为 INT_MAX 来判断，不用新开一个 visited 数组来记录。

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    map<string, vector<string>> edges;
    queue<string> queBegin;
    queue<string> queEnd;
    map<string, int> disBegin;
    map<string, int> disEnd;
    map<string, bool> visBegin;
    map<string, bool> visEnd;

    void addWord(string word) {
        visBegin[word] = false;
        visEnd[word] = false;
        string str = word;
        for (char& a : str) {
            char tmp = a;
            a = '*';
            edges[word].push_back(str);
            edges[str].push_back(word);
            a = tmp;
            visBegin[str] = false;
            visEnd[str] = false;
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        addWord(beginWord);
        for (int i = 0; i < wordList.size(); i++) {
            addWord(wordList[i]);
        }
        if (!edges.count(endWord)) return 0;

        queBegin.push(beginWord);
        disBegin[beginWord] = 0;
        visBegin[beginWord] = true;
        queEnd.push(endWord);
        disEnd[endWord] = 0;
        visEnd[endWord] = true;
        while (!queBegin.empty() && !queEnd.empty()) {
            int size = queBegin.size();
            for (int k = 0; k < size; k++) {
                string word1 = queBegin.front();
                queBegin.pop();
                if (visEnd[word1]) {
                    return (disBegin[word1] + disEnd[word1])/2 + 1;
                }
                for (int i = 0; i < edges[word1].size(); i++) {
                    string a = edges[word1][i];
                    if (!visBegin[a]) {
                        visBegin[a] = true;
                        disBegin[a] = disBegin[word1] + 1;
                        queBegin.push(a);
                    }
                }
            }

            size = queEnd.size();
            for (int k = 0; k < size; k++) {
                string word1 = queEnd.front();
                queEnd.pop();
                if (visBegin[word1]) {
                    return (disBegin[word1] + disEnd[word1])/2 + 1;
                }
                for (int i = 0; i < edges[word1].size(); i++) {
                    string a = edges[word1][i];
                    if (!visEnd[a]) {
                        visEnd[a] = true;
                        disEnd[a] = disEnd[word1] + 1;
                        queEnd.push(a);
                    }
                }
            }
        }
        return 0;
    }
};

class Solution_SingleDirSearch {
public:
    map<string, vector<string>> edges;
    queue<string> que;
    map<string, int> dis;
    map<string, bool> vis;

    void addWord(string word) {
        vis[word] = false;
        string str = word;
        for (char& a : str) {
            char tmp = a;
            a = '*';
            edges[word].push_back(str);
            edges[str].push_back(word);
            a = tmp;
            vis[str] = false;
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        addWord(beginWord);
        for (int i = 0; i < wordList.size(); i++) {
            addWord(wordList[i]);
        }
        if (!edges.count(endWord)) return 0;

        que.push(beginWord);
        dis[beginWord] = 0;
        vis[beginWord] = true;
        while (!que.empty()) {
            string word = que.front();
            que.pop();
            if (word == endWord) {
                return (dis[word]/2 + 1);
            }
            for (int i = 0; i < edges[word].size(); i++) {
                string a = edges[word][i];
                if (!vis[a]) {
                    vis[a] = true;
                    dis[a] = dis[word] + 1;
                    que.push(a);
                }
            }
        }
        return 0;
    }
};

int main() {
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    Solution s;
    cout << s.ladderLength("hit", "cog", wordList) << endl;

    return 0;
}