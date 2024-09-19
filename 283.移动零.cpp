/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
#include <vector>
class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int slow = 0, fast = 0;
        while(fast < nums.size()){
            if(nums[fast] != 0){
                int temp = nums[slow];
                nums[slow] = nums[fast];
                nums[fast] = temp;
                slow++;
            }
            fast++;
        }
    }
};
// @lc code=end

