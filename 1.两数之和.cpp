/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> valToIndex;
        for(int i = 0; i < nums.size(); i++){
            if(valToIndex.find(target - nums[i]) != valToIndex.end()){
                return std::vector<int> {valToIndex[target - nums[i]], i};
            }
            valToIndex[nums[i]] = i;
        }
        return std::vector<int> {};
    }
};
// @lc code=end

