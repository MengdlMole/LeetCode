/*
 * @lc app=leetcode.cn id=354 lang=java
 *
 * [354] 俄罗斯套娃信封问题
 */

// @lc code=start

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

class Solution {
    public int maxEnvelopes(int[][] envelopes) {
        Comparator<int[]> cmp = new Comparator<int[]>() {
            @Override
            public int compare(int[] a, int[] b){
                if(a[0] != b[0]){
                    // return Integer.compare(a[0], b[0]);
                    return a[0] - b[0];
                }
                if(a[1] != b[1]){
                    // return Integer.compare(b[1], a[1]);
                    return b[1] - a[1];
                }
                return 0;
            }
        };

        Arrays.sort(envelopes, cmp);

        List<Integer> dp = new ArrayList<>();
        dp.add(envelopes[0][1]);
        for(int i = 1; i < envelopes.length; i++){
            int left = 0, right = dp.size();
            if(envelopes[i][1] > dp.get(right - 1)) {
                dp.add(envelopes[i][1]);
            }
            else{
                while(left < right){
                    int mid = (left + right) >> 1;
                    if(dp.get(mid) < envelopes[i][1]){
                        left = mid + 1;
                    }
                    // else if(envelopes[mid][1] > envelopes[i][1]){
                    //     right = mid;
                    // }
                    else{
                        right = mid;
                    }
                }
                dp.set(right, envelopes[i][1]);
            }
        }
        return dp.size();
    }

    // public static void main(String[] args){
    //     int[][] test = new int[][]{{2,100},{3,200},{4,300},{5,500},{5,400},{5,250},{6,370},{6,360},{7,380}};
    //     Solution mSolution = new Solution();
    //     mSolution.maxEnvelopes(test);
    // }
}
// @lc code=end

