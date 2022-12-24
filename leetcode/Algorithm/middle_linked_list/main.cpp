#include <iostream>

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


/*
Given the head of a singly linked list, return the middle node of the 
linked list.

If there are two middle nodes, return the second middle node.

*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // Initialize slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;

        // Iterate through the linked list using the slow and fast pointers
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Return the slow pointer, which will be at the middle of the list
        return slow;
    }
};