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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *pre=NULL;
        ListNode *cur=head;
        ListNode* ansHead=head->next;
        while(cur && cur->next){
            if(pre){
                pre->next=cur->next;
            }
            ListNode* nxtBlock=cur->next->next;
            cur->next->next=cur;
            cur->next=nxtBlock;
            pre=cur;
            cur=nxtBlock;
            cur=nxtBlock;
        }
        return ansHead;
    }
};