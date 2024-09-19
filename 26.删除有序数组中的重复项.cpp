/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
#include <vector>
class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        int left = 0, right = 1;
        while(right < nums.size()){
            if(nums[right] == nums[left]){
                right++;
            }
            else{
                nums[++left] = nums[right++];
            }
        }
        return left+1;
    }
};
// @lc code=end

