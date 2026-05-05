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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        
        ListNode* lastNode = head;
        int n = 1;
        while(lastNode->next != nullptr){
            n++;
            lastNode = lastNode->next;
        }

        k = k % n;
        if (k == 0) return head;

        ListNode* dt = head;
        for(int i=0; i<(n-k-1); i++){
            dt = dt->next;
        }

        ListNode* newHead = dt->next;
        dt->next = nullptr;
        lastNode->next = head;

        return newHead;

    }
};