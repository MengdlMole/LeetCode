/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* pseudoHead = new ListNode(0, head);
        // x->2->1->3
        ListNode* left = pseudoHead;
        ListNode* right = pseudoHead;
        // left->4->5(right)->2->1->3
        while(right->next != nullptr){
            if(right->next->val < x){
                if(left == right){
                    left = left->next;
                    right = right->next;
                }else{
                    ListNode* tmp = left->next;
                    left->next = right->next;
                    right->next = right->next->next;
                    left->next->next = tmp;
                    left = left->next;
                }
            }else{
                right = right->next;
            }
        }
        return pseudoHead->next;
    }
};
// @lc code=end

