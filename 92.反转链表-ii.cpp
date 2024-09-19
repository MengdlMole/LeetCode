/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
class Solution {
public:

    ListNode* reverseN(ListNode* head, int n){
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* curNext = head->next;
        while(cur != nullptr && n > 0){
            cur->next = pre;
            pre = cur;
            cur = curNext;
            if(cur != nullptr) curNext = cur->next;
            n--;
        }
        head->next = cur;
        return pre;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        int n = right - left + 1;
        if(left < 2){
            return reverseN(head, n);
        }
        else{
            ListNode* startPre = head;
            for(int i = 0; i < left - 2; i++){
                startPre = startPre->next;
            }
            ListNode* start = reverseN(startPre->next, n);
            startPre->next = start;
            return head;
        }
    }
};
// @lc code=end

