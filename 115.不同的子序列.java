/*
 * @lc app=leetcode.cn id=115 lang=java
 *
 * [115] 不同的子序列
 */

// @lc code=start

// import java.util.Arrays;

class Solution {
    public int numDistinct(String s, String t) {
        int m = s.length(), n = t.length();
        if(m < n){
            return 0;
        }
        int[][] dp = new int[m+1][n+1];
        for(int i = 0; i < m+1; i++){
            dp[i][n] = 1;
        }
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(s.charAt(i) != t.charAt(j)){
                    dp[i][j] = dp[i+1][j];
                }
                else{
                    dp[i][j] = dp[i+1][j] + dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];
        // memory = new int[s.length()][t.length()];
        // for(int i = 0; i < s.length(); i++){
        //     Arrays.fill(memory[i], -1);
        // }
        // int res = dp(s,0,t,0);
        // return res;
    }

    // private int[][] memory;

    // private int dp(String s, int sStart, String t, int tStart){
    //     if(s.length()-sStart < t.length()-tStart){
    //         return 0;
    //     }
    //     if(tStart == t.length()){
    //         return 1;
    //     }
    //     if(memory[sStart][tStart] != -1){
    //         return memory[sStart][tStart];
    //     }
    //     // int output = 0;
    //     // for(int k = sStart; k < s.length(); k++){
    //     //     if(s.charAt(k) == t.charAt(tStart)){
    //     //         output += dp(s, k+1, t, tStart+1);
    //     //     }
    //     // }
    //     if(s.charAt(sStart) == t.charAt(tStart)){
    //         return dp(s,sStart+1,t,tStart+1) + dp(s,sStart+1,t,tStart);
    //     }
    //     else{
    //         return dp(s,sStart+1,t,tStart);
    //     }
    //     // return output;
    // }
}
// @lc code=end

