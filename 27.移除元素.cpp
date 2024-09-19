/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
#include <vector>
#include <iostream>
class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            if(val == nums[left]){
                while(nums[right] == val && right > left){
                    right--;
                }
                if(left == right){
                    return left;
                }
                nums[left] = nums[right];
                nums[right] = val;
            }
            left++;
        }
        return left;
    }
};
// @lc code=end

