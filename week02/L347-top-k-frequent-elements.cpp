// 题目链接：https://leetcode-cn.com/problems/top-k-frequent-elements/
// 思路：
//（1）先用一个哈希表统计每个元素出现的次数
//（2）再将（元素值，出现次数）作为一个结构体存入一个小顶堆
//（3）将该堆的最大容量限制为 K，同时只有比堆顶元素大的才允许进入
// 从而实现堆中元素就是最大的 K 个元素
//（4）这里哈希表用 c++ STL 中的 map；堆用 c++ STL 中的 priority_queue
//（5）priority_queue 需要自定义比较函数，用出现次数来排序，小顶堆需要降序排列

// 复杂度分析：
//（1）时间复杂度：哈希表统计 O(N)。堆操作，每次 logK，共 N 次，复杂度为 O(NlogK)。
// 综合复杂度 O(NlogK)。
//（2）空间复杂度：哈希表 O(N)，堆空间 O(K)，综合复杂度：O(N)。

#include <iostream>
#include <map>
#include <queue>
using namespace std;

class Solution {
public:
    struct cmp {
        bool operator()(pair<int, int> a, pair<int ,int> b) {
            return a.second > b.second;
        }
    };
    /*static bool cmp(pair<int, int> a, pair<int ,int> b) {
        return a.second < b.second;
    }*/
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> ocr;
        //priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(&cmp)> heap(cmp);
        priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> heap;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            ocr[nums[i]]++;
        }
        
        map<int, int>::iterator it = ocr.begin();
        while (it != ocr.end()) {
            if (heap.size() < k) heap.push(make_pair(it->first, it->second));
            else {
                if (heap.top().second < it->second) {
                    heap.pop();
                    heap.push(make_pair(it->first, it->second));
                }
            }
            it++;
        }

        while (!heap.empty()) {
            res.push_back(heap.top().first);
            heap.pop();
        }

        return res;
    }
};

int main() {
    Solution s;
    //int a[6] = {1,1,1,2,2,3};
    int a[7] = {4,1,-1,2,-1,2,3};
    vector<int> nums;
    for (int i = 0; i < 6; i++) {
        nums.push_back(a[i]);
    }
    int k = 2;
    vector<int> topK = s.topKFrequent(nums, k);

    cout << "expected result:" << endl;
    //cout << "[1,2]" << endl << endl;
    cout << "[-1,2]" << endl << endl;

    cout << "actual result:" << endl;
    cout << "[";
    for (int i = 0; i < topK.size(); i++) {
        cout << topK[i];
        if (i < topK.size()-1) cout << ",";
    }
    cout << "]" << endl;
    
    return 0;
}