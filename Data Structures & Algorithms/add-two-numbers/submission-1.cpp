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
        if(!l1 && !l2) return nullptr;
        ListNode* final = new ListNode(0);
        ListNode* curr = final;
        int carry = 0;
        while(l1 && l2) {
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            if(sum >= 10) {
                ListNode* new_2 = new ListNode(sum % 10);
                curr->next = new_2;
                curr = curr->next;
            }
            else {
                ListNode* new_2 = new ListNode(sum);
                curr->next = new_2;
                curr = curr->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1) {
            int sum = l1->val + carry;
            carry = sum / 10;
            ListNode* new_1 = new ListNode(sum % 10);
            curr->next = new_1;
            curr = curr->next;
            l1 = l1->next;
        }
        while(l2) {
            int sum = l2->val + carry;
            carry = sum / 10;
            ListNode* new_2 = new ListNode(sum % 10);
            curr->next = new_2;
            curr = curr->next;
            l2 = l2->next;
        }
        if(carry) {
            curr->next = new ListNode(carry);
        }
        return final->next;
    }
};