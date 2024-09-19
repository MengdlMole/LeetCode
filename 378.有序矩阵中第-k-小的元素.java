/*
 * @lc app=leetcode.cn id=378 lang=java
 *
 * [378] 有序矩阵中第 K 小的元素
 */

// @lc code=start

import java.util.PriorityQueue;

class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        for(int i = 0; i < matrix.length; i++){
            pq.add(new int[]{matrix[i][0], i, 0});
        }

        int res = -1;
        while(!pq.isEmpty() && k > 0){
            int[] cur = pq.poll();
            res = cur[0];
            k--;
            int i = cur[1];
            int j = cur[2];
            if(j + 1 < matrix[0].length){
                pq.add(new int[]{matrix[i][j + 1], i, j + 1});
            }
        }
        return res;
    }
}
// @lc code=end

