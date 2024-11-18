/*
 * @lc app=leetcode.cn id=93 lang=java
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

class Solution {
    public List<String> res = new ArrayList<>();
    public List<String> track = new LinkedList<>();
    public int cur = 0;
    public int path = 0;
    public int[] nextLengths = new int[]{3,2,1};

    public List<String> restoreIpAddresses(String s) {
        backtrack(s);
        return res;
    }

    private void backtrack(String s){
            if(path == 4){
                if(cur == s.length()){
                    StringBuilder temp = new StringBuilder();
                    for(int i = 0; i < 3; i++){
                        temp.append(track.get(i));
                        temp.append(".");
                    }
                    temp.append(track.get(3));
                    res.add(temp.toString());
                }
                else if(cur < s.length()){
                    return ;
                }
            }
            
            for(int nextLength : nextLengths){
                if(cur + nextLength <= s.length()){
                    String temp = s.substring(cur, cur + nextLength);
                    if(temp.equals("0") || Integer.parseInt(temp)<256){
                        path += 1;
                        track.add(temp);
                        cur += nextLength;
                        backtrack(s);
                        cur -= nextLength;
                        track.remove(path-1);
                        path -= 1;
                    }
                }
                else{
                    continue;
                }
            }
    }

    public static void main(String[] args){
        String mString = "25525511135";
        Solution mSolution = new Solution();
        mSolution.restoreIpAddresses(mString);
    }
}
// @lc code=end

