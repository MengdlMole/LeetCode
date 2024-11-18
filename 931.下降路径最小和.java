/*
 * @lc app=leetcode.cn id=931 lang=java
 *
 * [931] 下降路径最小和
 */

// @lc code=start

class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int row = matrix.length, col = matrix[0].length;
        int[][] dp = new int[row][col];
        for(int j = 0; j < col; j++){
            dp[0][j] = matrix[0][j];
        }
        
        for(int i = 1; i < row; i++){
            for(int j = 0; j < col; j++){
                int front = dp[i-1][j];
                if(j - 1 >= 0){
                   front = Math.min(front, dp[i-1][j-1]);
                }
                if(j + 1 < col){
                    front = Math.min(front, dp[i-1][j+1]);
                }
                dp[i][j] = front + matrix[i][j];
            }
        }
        int res = Integer.MAX_VALUE;
        for(int j = 0; j < col; j++){
            res = Math.min(dp[row-1][j], res);
        }
        return res;
    }
}
// @lc code=end

