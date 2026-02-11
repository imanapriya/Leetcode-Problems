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
    typedef ListNode* ln;
    
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return 0;

        ln s = head->next;
        ln f = head->next->next;

        while (s && f && s != f) {
            s = s->next;
            f = f->next;
            f = f ? f->next : f;
        }

        return s == f;
    }
};
