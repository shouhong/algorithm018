#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        for (int i = 0; i < nums.size(); i++) {
            if (!dq.empty() && i - dq.front() >= k) {
                dq.pop_front();
            } 
            while (!dq.empty() && nums.at(i) >= nums.at(dq.back())) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k-1) {
                res.push_back(nums.at(dq.front()));
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums {1,3,-1,-3,5,3,6,7};
    vector<int> res = s.maxSlidingWindow(nums, 3);
    cout << "expected result: [3,3,5,5,6,7]" << endl;
    cout << "result:          [";
    for (vector<int>::iterator iter = res.begin(); iter != res.end(); iter++) {
        if (iter != res.begin()) cout << ",";
        cout << (*iter);
    }
    cout << "]" << endl; 
    return 0;
}