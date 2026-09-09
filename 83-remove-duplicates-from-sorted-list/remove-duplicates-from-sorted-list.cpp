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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;

        ListNode* temp = head;
        while(temp->next) {
            if(temp->next== nullptr) return head;
            ListNode* n1 = temp;
            ListNode* n2 = temp->next;
            if(n1->val == n2->val) {
                n1->next = n2->next;

            } else {
                temp = temp->next;

            }

        }

        return head;
    }
};