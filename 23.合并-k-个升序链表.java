/*
 * @lc app=leetcode.cn id=23 lang=java
 *
 * [23] 合并 K 个升序链表
 */

// @lc code=start
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
import java.util.*;

class Solution {
    public static class ListNode{
        int val;
        ListNode next;
        ListNode(){}
        ListNode(int x){
            this.val = x;
        }
        ListNode(int x, ListNode next){
            this.val = x;
            this.next = next;
        }
    }

    public static class Node{
        int val;
        List<Node> children;
        Node(){
            // this.children = new ArrayList<>();
        }
        Node(int x){
            this.val = x;
            this.children = new ArrayList<>();
        }
        public void addNode(Node child){
            this.children.add(child);
        }
    }

    public ListNode mergeKLists(ListNode[] lists) {
        Comparator<ListNode> cmp = new Comparator<ListNode>() {
            @Override
            public int compare(ListNode p1, ListNode p2){
                return p1.val - p2.val;
            }
        };
        PriorityQueue<ListNode> myQueue = new PriorityQueue<>(cmp);
        int listCount = lists.length;
        for(int i = 0; i < listCount; i++){
            if(lists[i] != null){
                myQueue.add(lists[i]);
            }
        }
        ListNode dummyHead = new ListNode(-1);
        ListNode cur = dummyHead;
        while(!myQueue.isEmpty()){
            ListNode temp = myQueue.poll();
            cur.next = temp;
            cur = cur.next;
            if(temp.next != null){
                myQueue.add(temp.next);
            }
            temp.next = null;
        }
        return dummyHead.next;
    }
}
// @lc code=end

