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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return eachBitNumber(l1, l2, 0);
    }
    
    ListNode* eachBitNumber(ListNode* l1, ListNode* l2, int carry)
    {
        if (l1 == NULL && l2 == NULL)
            return carry == 0 ? NULL : new ListNode(carry);
        if (l1 == NULL && l2 != NULL)
            l1 = new ListNode(0);
        if (l1 != NULL && l2 == NULL)
            l2 = new ListNode(0);
        
        int sum = l1->val + l2->val + carry;
        ListNode* curr = new ListNode(sum % 10);
        curr->next = eachBitNumber(l1->next, l2->next, sum / 10);
        return curr;
    }
};