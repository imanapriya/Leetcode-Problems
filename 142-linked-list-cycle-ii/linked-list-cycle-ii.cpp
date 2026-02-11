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

    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) {
            return NULL;
        }

        ln s = head;
        ln f = head;

        while (f && f->next) {
            s = s->next;
            f = f->next->next;

            if (s == f) {
                s = head;         
                while (s != f) {
                    s = s->next;
                    f = f->next;
                }
                return s;         
            }
        }

        return NULL;
    }
};