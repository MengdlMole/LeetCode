/*
 * @lc app=leetcode.cn id=139 lang=java
 *
 * [139] 单词拆分
 */

import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
// @lc code=start
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        words = new HashSet<>(wordDict);
        memory = new int[s.length()];
        Arrays.fill(memory, -1);
        return dp(s,0);
    }

    private int[] memory;
    private HashSet<String> words;

    private boolean dp(String s, int start){
        if(start == s.length()){
            return true;
        }
        if(memory[start] != -1){
            return memory[start] == 0 ? false : true;
        }
        boolean res = false;
        for(int end = s.length(); end >= start; end--){
            if(words.contains(s.substring(start, end))){
                res = dp(s, end);
                if(res == true){
                    memory[start] = 1;
                    return res;
                }
            }
        }
        memory[start] = 0;
        return res;
        // for(String word : wordDict){
        //     if(start+word.length() > s.length()){
        //         continue;
        //     }
        //     if(s.charAt(start) == word.charAt(0)){
        //         if(s.substring(start, start+word.length()).equals(word)){
        //             res = dp(s, start + word.length(), wordDict);
        //             if(res == true){
        //                 memory[start] = 1;
        //                 return res;
        //             }
        //         }
        //     }
        // }
        // return res;
    }
}
// @lc code=end

