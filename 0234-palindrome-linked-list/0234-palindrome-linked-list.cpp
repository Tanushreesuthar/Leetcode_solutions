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

   ListNode* reverse(ListNode* head) {
        ListNode*prev=NULL,*curr=head,*temp=NULL;
        while(curr!=NULL)
        {
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head==NULL ||head->next==NULL )return true;
        // if(head->next->val==head->val && head->next->next==NULL)return true;
        // else if(head->next->val!=head->val && head->next->next==NULL)return false;
        ListNode* fast=head,*slow=head , *check=head;
        int cnt=0;
        while(fast!=NULL && slow!=NULL)
        {

            fast=fast->next;
            cnt++;
            if(fast!=NULL)
            {
                fast=fast->next;
                cnt++;
            }
            slow=slow->next;
        }
        // cout<<" slow ->>"<<slow->val<<endl;
        ListNode*temp=reverse(slow);

        // if(cnt%2==1)
        // {
            while(check!=NULL && temp!=NULL)
            {
                if(check->val!=temp->val)return false;
                check=check->next;
                temp=temp->next;
            }
            return true;
        // }
        // else {

        // }
    }

};