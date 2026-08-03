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


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c=0;
        ListNode *dummy=new ListNode(0,NULL);
        ListNode *head=dummy;
        while(l1 && l2)
        {
            int sum=l1->val+l2->val+c;
            if(sum<=9)
            {
                ListNode *t=new ListNode(sum,NULL);
                head->next=t;
                head=head->next;
                c=0;
            }
            else
            {
                c=1;
                ListNode *t=new ListNode(sum-10,NULL);
                head->next=t;
                head=head->next;
            }
            l1=l1->next;
            l2=l2->next;
        }

        while(l1!=NULL)
        {
            int sum=l1->val+c;
            if(sum<=9)
            {
                ListNode *t=new ListNode(sum,NULL);
                head->next=t;
                head=head->next;
                c=0;
            }
            else
            {
                c=1;
                ListNode *t=new ListNode(sum-10,NULL);
                head->next=t;
                head=head->next;
            }
            l1=l1->next;   
        }

        while(l2!=NULL)
        {
            int sum=l2->val+c;
            if(sum<=9)
            {
                ListNode *t=new ListNode(sum,NULL);
                head->next=t;
                head=head->next;
                c=0;
            }
            else
            {
                c=1;
                ListNode *t=new ListNode(sum-10,NULL);
                head->next=t;
                head=head->next;
            }
            l2=l2->next;
        }

        if(c!=0)
        {
            ListNode *t=new ListNode(1,NULL);
            head->next=t;
        }

        return dummy->next;
    }
};