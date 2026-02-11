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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if(!a) return b;
        if(!b) return a;
        ListNode* dummy= new ListNode(-1);
        ListNode* finalhead=(a->val<=b->val)? a:b;

        while(a&& b){
            if(a->val <= b->val){
                dummy->next=a;
                dummy=a;
                a=a->next;
            }
            else{
                dummy->next=b;
                dummy=b;
                b=b->next;
            }
        }
        if(a) dummy->next=a;
        if(b) dummy->next=b;

        return finalhead;
    }
};