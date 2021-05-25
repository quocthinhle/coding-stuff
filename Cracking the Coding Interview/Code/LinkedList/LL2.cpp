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
        ListNode* res = new ListNode();
        ListNode* travel = res;
        int carry = 0;

        while (l1 && l2) {
            cout << l1->val << endl;
            travel->val  = carry + l1->val + l2->val;
            
            if (carry == 1) --carry;
            
            if (travel->val >= 10) {
                travel->val -= 10;
                carry += 1;
            }
            
            l1 = l1->next;
            l2 = l2->next;
            
            if (!l1 && !l2) {
                if (carry) {
                    travel->next = new ListNode();
                    travel = travel->next;
                    travel->val = 1;
                }
                return res;
            }
            
            travel->next = new ListNode();
            travel = travel->next;
        }
        
        while (l1) {
            travel->val = l1->val + carry;
            if (carry) --carry;
            if (travel->val >= 10) {
                ++carry;
                travel->val -= 10;
            }
            l1 = l1->next;
            if (!l1) {
                travel->next = new ListNode();
                travel = travel->next;
            }
        }
        
        while (l2) {
            travel->val = l2->val + carry;
            if (carry) --carry;
            if (travel->val >= 10) {
                travel->val -= 10;
                ++carry;
            }
            l2 = l2->next;
            if (!l2) {
                travel->next = new ListNode();
                travel = travel->next;
            }
        }
        
        if (carry) {
            travel->next = new ListNode();
            travel = travel->next;
            travel->val = carry;
        }
        
        return res;
    }
};