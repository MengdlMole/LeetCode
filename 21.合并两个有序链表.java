/*
 * @lc app=leetcode.cn id=21 lang=java
 *
 * [21] 合并两个有序链表
 */

// @lc code=start

import java.util.Scanner;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {

    // public static class ListNode{
    //     int val;
    //     ListNode next;
    //     ListNode(){};
    //     ListNode(int x){this.val = x;}
    //     ListNode(int x, ListNode next){this.val = x; this.next = next;}
    // }

    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode dummyHead = new ListNode(-1);
        ListNode l1, l2, p;
        l1 = list1;
        l2 = list2;
        p = dummyHead;
        while(l1 != null && l2 != null){
            if(l1.val < l2.val){
                p.next = l1;
                p = p.next;
                l1 = l1.next;
            }
            else{
                p.next = l2;
                p = p.next;
                l2 = l2.next;
            }
        }
        if(l1 != null){
            p.next = l1;
        }
        if(l2 != null){
            p.next = l2;
        }
        return dummyHead.next;
    }

    // public static void main(String[] args){
    //     Scanner myScanner = new Scanner(System.in);
    //     int n, m;
    //     n = myScanner.nextInt();
    //     m = myScanner.nextInt();
    //     ListNode list1, list2;
    //     list1 = new ListNode();
    //     list2 = new ListNode();
    //     for(int i = 0; i < n; i++){
    //         int temp_int = myScanner.nextInt();
    //         ListNode temp = new ListNode(temp_int);
    //         list1.next = temp;
    //     }
    //     for(int i = 0; i < m; i++){
    //         int temp_int = myScanner.nextInt();
    //         ListNode temp = new ListNode(temp_int);
    //         list2.next = temp;
    //     }
    //     Solution solution = new Solution();
    //     ListNode res = solution.mergeTwoLists(list1.next, list2.next);
    //     ListNode p = res;
    //     System.out.print("[");
    //     while(p != null && p.next != null){
    //         System.out.print(p.val);
    //         System.out.print(",");
    //         p = p.next;
    //     }
    //     System.out.print(p.val);
    //     System.out.print("]");
    //     myScanner.close();
    // }
}
// @lc code=end

