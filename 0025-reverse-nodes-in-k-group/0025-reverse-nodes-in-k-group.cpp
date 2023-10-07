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
    ListNode* reverse(ListNode* head , int k , int a)
    {
        int hehe=k;
        if(head==NULL || head->next==NULL ||a==0)return head;
        ListNode*curr=head, *prev=NULL ,*temp=NULL;
        int cnt=1;
        while(cnt<=k&& curr!=NULL)
        {
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            cnt++;
        }
      head->next=reverse(curr,hehe,a-1);
      return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
         if(head==NULL || head->next==NULL)return head;
        int cnt=0;
        ListNode*curr=head;
       while(curr!=NULL)
       {
           cnt++;
           curr=curr->next;
       }
       int a=cnt/k;
       return reverse(head,k,a);
       
    }
};