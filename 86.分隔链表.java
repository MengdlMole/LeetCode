/*
 * @lc app=leetcode.cn id=86 lang=java
 *
 * [86] 分隔链表
 */

// @lc code=start

// import Solution.ListNode;

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
    //     ListNode(int x){this.val = x}
    //     ListNode(int x, ListNode next){
    //         this.val = x;
    //         this.next = next;
    //     }
    // }

    public ListNode partition(ListNode head, int x) {
        // if(head == null) return head;
        ListNode oldHead = new ListNode(-1, head);
        ListNode newHead = new ListNode(-1);
        ListNode pOld = oldHead;
        ListNode pNew = newHead;
        while(pOld.next != null){
            if(pOld.next.val < x){
                ListNode temp = pOld.next;
                pOld.next = pOld.next.next;
                temp.next = null;
                pNew.next = temp;
                pNew = pNew.next;
            }
            else{
                pOld = pOld.next;
            }
        }
        pNew.next = oldHead.next;
        return newHead.next;
    }
}
// @lc code=end

