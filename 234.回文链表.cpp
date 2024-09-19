/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
//     ListNode():val(0),next(nullptr){}
//     ListNode(int x):val(x),next(nullptr){}
//     ListNode(int x, ListNode* next):val(x),next(next){}
// };
class Solution {
private:
    bool res = true;
    ListNode* left;
    ListNode* right;
    void traverse(ListNode* right){
        if(right == nullptr){
            return;
        }
        traverse(right->next);
        if(left->val != right->val){
            res = false;
        }
        left = left->next;
    }
public:
    bool isPalindrome(ListNode* head) {
        left = head;
        right = head;
        traverse(right);
        return res;
    }
};
// @lc code=end

