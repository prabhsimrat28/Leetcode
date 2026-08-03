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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *s=head;
        ListNode *f=head;
        ListNode *dummy=new ListNode(-1,head);
        ListNode *prev=dummy;
        while(n--)
        {
            f=f->next;
        }
        while(f)
        {
            prev=s;
            s=s->next;
            f=f->next;
        }

        prev->next=s->next;
        return dummy->next;
    }
};