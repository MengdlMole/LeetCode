/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
// struct ListNode{
//     int val;
//     ListNode* next;
//     ListNode():val(0), next(nullptr){}
//     ListNode(int x):val(x), next(nullptr){}
//     ListNode(int x, ListNode* next):val(x), next(next){}
// };
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr){
            if(slow->val != fast->val){
                ListNode* temp = slow->next;
                // TODO: delete useless nodes temp=>...->fast
                // delete(temp, fast);
                slow->next = fast;
                slow = slow->next;
            }
            fast = fast->next;
        }
        slow->next = nullptr;
        return head;
    }

    // void delete(ListNode* start, ListNode* end){
    //     while(start != end && start != nullptr){
    //         ListNode* temp = start;
    //         start = start->next;
    //         delete temp;
    //     }
    // }
};
// @lc code=end

