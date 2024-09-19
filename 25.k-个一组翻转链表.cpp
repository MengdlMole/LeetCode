/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* seccutor = nullptr; 
    ListNode* reverseN(ListNode* head, int n){
        if(n == 1){
            seccutor = head->next;
            return head;
        }
        ListNode* last = reverseN(head->next, n-1);
        head->next->next = head;
        head->next = seccutor;
        return last;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) return head;
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* dummyHead = new ListNode(-1, head);
        ListNode* preTail = dummyHead;
        ListNode* curHead = dummyHead->next;
        ListNode* curTail = dummyHead->next;
        ListNode* nextHead = dummyHead->next;

        while(true){
            for(int i = 0; i < k - 1; i++){
                if(curTail == nullptr) return dummyHead->next;
                curTail = curTail->next;
            }
            if(curTail == nullptr) return dummyHead->next;

            nextHead = curTail->next;
            preTail->next = reverseN(curHead, k);
            preTail = curHead;
            curHead = nextHead;
            curTail = nextHead;
        }
        return dummyHead->next;
    }
};
// @lc code=end

