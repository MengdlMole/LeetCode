/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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

// #include <iostream>

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode* next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyHead = new ListNode();
        ListNode* cur = dummyHead;
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val < list2->val){
                cur->next = list1;
                list1 = list1->next;
            }
            else{
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        if(list1 != nullptr){
            cur->next = list1;
        }
        if(list2 != nullptr){
            cur->next = list2;
        }
        return dummyHead->next;
    }
};
// @lc code=end

// int main(){
//     ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
//     ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
//     ListNode* p1 = list1;
//     while(p1 != nullptr){
//         printf("%d->", p1->val);
//         p1 = p1->next;
//     }
//     printf("\n");
//     ListNode* p2 = list2;
//     while(p2 != nullptr){
//         printf("%d->", p2->val);
//         p2 = p2->next;
//     }
//     printf("\n");
//     Solution mySolution;
//     ListNode* res = mySolution.mergeTwoLists(list1, list2);
//     ListNode* cur = res;
//     while(cur != nullptr){
//         printf("%d->", cur->val);
//         cur = cur->next;
//     }
//     return 0;
// }