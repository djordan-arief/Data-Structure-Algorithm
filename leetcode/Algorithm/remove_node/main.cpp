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
Given the head of a linked list, remove the nth node 
from the end of the list and return its head.

*/



class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Initialize slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;

        // Move the fast pointer n steps ahead of the slow pointer
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Special case: if the fast pointer reaches the end of the list,
        // then we need to remove the head of the list
        if (!fast) {
            return head->next;
        }

        // Iterate through the linked list until the fast pointer reaches the end
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        // Remove the n-th node from the end of the list by updating the next pointer
        // of the (n-1)-th node from the end
        slow->next = slow->next->next;

        // Return the head of the modified list
        return head;
    }
};