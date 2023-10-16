/*
Approach 1: traverse and add
Runtime: 18ms
Memory: 71.71MB
Time Complexity: O(n)
*/
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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = NULL;
        ListNode* head = NULL;
        int carry = 0;
        while(l1 != NULL || l2 != NULL)
        {
            if (l3 == NULL)
            {
                l3 = new ListNode;
            }
            else
            {
                l3->next = new ListNode;
                l3 = l3->next;
            }
            
            if (head == NULL)
            {
                head = l3;
            }
 
            int value = 0;
            if (l1 == NULL)
            {
                value = l2->val + carry;
                l2 = l2->next;
            }
            else if (l2 == NULL)
            {
                value = l1->val + carry;;
                l1 = l1->next;
            }
            else
            {
                value = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            }
            carry = value / 10;
            l3->val = value % 10;
        }

        if (carry != 0)
        {
            l3->next = new ListNode;
            l3 = l3->next;
            l3->val = carry;
        }
        return head;
    }
};