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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sza = 0, szb = 0;

        ListNode* a = headA;
        ListNode* b = headB;

        while (a) {
            ++sza;
            a = a->next;
        }
        while (b) {
            ++szb;
            b = b->next;
        }

        // reset pointers
        a = headA;
        b = headB;

        if (sza < szb) {
            swap(sza, szb);
            swap(a, b);
        }

        for (int i = 0; i < sza - szb; ++i) {
            a = a->next;
        }

        while (a && b && a != b) {
            a = a->next;
            b = b->next;
        }

        return (a && b) ? a : nullptr;
    }
};
