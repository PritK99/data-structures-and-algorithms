/*
Approach 1: DFS & Backtracking with pruning strategies
Runtime: 3ms
Memory: 7.97MB
Time Complexity: O(n), where n is length of linkedlist
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL)
        {
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        do
        {
            if (fast->next != NULL && fast->next->next != NULL)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            else
            {
                return NULL;
            }
        }
        while (slow != fast);

        fast = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;

    }
};