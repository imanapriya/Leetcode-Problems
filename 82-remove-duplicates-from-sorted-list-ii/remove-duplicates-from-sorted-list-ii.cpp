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
        if (!head || !head->next) return head;

        ListNode* ans = nullptr;
        ListNode* pre = nullptr;
        
        while (head) {
            bool hasDup = false;
            
            while (head->next && head->val == head->next->val) {
                hasDup = true;
                head = head->next;
            }
            
            if (!hasDup) {
                if (!ans) {
                    ans = head;
                    pre = head;
                } else {
                    pre->next = head;
                    pre = head;
                }
            }
            
            head = head->next;
        }
        
        if (pre) pre->next = nullptr;
        
        return ans;
    }
};
