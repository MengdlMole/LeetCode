/*
 * @lc app=leetcode.cn id=373 lang=cpp
 *
 * [373] 查找和最小的 K 对数字
 */

// @lc code=start
// #include <vector>
// #include <queue>
class Solution {
public:
    std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        std::vector<std::vector<int> > res;
        auto cmp = [](std::vector<int> a, std::vector<int>b){
            return a[0] + a[1] > b[0] + b[1];
        };
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(cmp)> pq(cmp);

        for(int i = 0; i < nums1.size(); i++){
            pq.push({nums1[i], nums2[0], 0});
        }

        while(!pq.empty() && k > 0){
            auto cur = pq.top();
            pq.pop();
            k--;
            int nextIndex = cur[2] + 1;
            if(nextIndex < nums2.size()){
                pq.push({cur[0], nums2[nextIndex], nextIndex});
            }
            res.push_back({cur[0], cur[1]});
        }
        return res;
    }
};
// @lc code=end

