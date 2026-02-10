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
    ListNode* reverseList(ListNode* head){
      ListNode* prev = NULL;
        while (head != NULL) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
}
    
    bool isPalindrome(ListNode* head) {
        ListNode* s=head;
        ListNode* f=head;
        while(f && f->next){
            s=s->next;
            f=f->next->next;
        }
        ListNode* r=reverseList(s);
        ListNode* temp = head;

        while (r != NULL) {
            if (temp->val != r->val)
                return false;

            temp = temp->next;
            r = r->next;
        }

        return true;

    }
};