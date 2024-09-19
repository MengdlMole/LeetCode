/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
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
// #include <vector>
// #include <queue>
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        auto cmp = [](ListNode* l1, ListNode* l2) {
            return l1->val > l2->val;
        };
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> pq(cmp);
        for(auto l : lists){
            if(l != nullptr) pq.push(l);
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            cur->next = node;
            cur = cur->next;
            if(node->next != nullptr){
                pq.push(node->next);
                node->next = nullptr;
            }
        }
        return dummy->next;
    }
};
// @lc code=end

