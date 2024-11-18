/*
 * @lc app=leetcode.cn id=300 lang=java
 *
 * [300] 最长递增子序列
 */

// @lc code=start

import java.util.ArrayList;
import java.util.List;

class Solution {
    // public int lengthOfLIS(int[] nums) {
    //     int[] dp = new int[nums.length];
    //     Arrays.fill(dp, 1);
    //     for(int i = 0; i < nums.length; i++){
    //         for(int j = 0; j < i; j++){
    //             if(nums[i] > nums[j]){
    //                 dp[i] = Math.max(dp[i], dp[j] + 1);
    //             }
    //         }
    //     }
    //     int res = 0;
    //     for (int i = 0; i < dp.length; i++) {
    //         res = Math.max(res, dp[i]);
    //     }
    //     return res;
    // }
    public int lengthOfLIS(int[] nums) {
        if(0 == nums.length) return 0;
        List<Integer> top = new ArrayList<>();
        top.add(nums[0]);
        for(int i = 1; i < nums.length; i++){
            int left = 0, cur = top.size();
            while(left < cur){
                int mid = (left + cur) >> 1;
                if(top.get(mid) < nums[i]){
                    left = mid + 1;
                }
                else{
                    cur = mid;
                }
            }
            if(cur == top.size()){
                top.add(nums[i]);
            }
            else{
                top.set(cur, nums[i]);
            }
        }
        return top.size();
    }
}
// @lc code=end

