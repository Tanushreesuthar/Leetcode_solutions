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
        if(l1==NULL && l2==NULL)return NULL;
        if(l1==NULL)return NULL;
        if(l2==NULL)return NULL;
        ListNode* p1=l1,*p2=l2;
        int carry=0;
        ListNode*prev1=NULL;
        while(p1!=NULL && p2!=NULL)
        {
            int sum=p1->val+p2->val+carry;
            carry=sum/10;
            p1->val=sum%10;
            p2->val=sum%10;
            prev1=p1;
            p1=p1->next;
            p2=p2->next;
        } 
        if(p1==NULL && p2==NULL && carry==0)
        {
           return l1;
        }  
        else if(p1!=NULL)
        {
            while(p1!=NULL)
            {
                int sum=p1->val+carry;
                carry=sum/10;
                p1->val=sum%10;
                prev1=p1;
                p1=p1->next;
            }
            if(carry>0)
            {
                ListNode*dummy=new ListNode(carry);
                dummy->val=carry;
                prev1->next=dummy; 
            }
            return l1;
             
        }
        else if(p2!=NULL)
        {
             while(p2!=NULL)
            {
                int sum=p2->val+carry;
                carry=sum/10;
                p2->val=sum%10;
                prev1=p2;
                p2=p2->next;
                
            }
            if(carry>0)
            {
                ListNode*dummy=new ListNode(carry);
                dummy->val=carry;
                prev1->next=dummy; 
            }
           return l2;
        }
        else if(carry!=0)
        {
            ListNode*dummy=new ListNode(carry);
                dummy->val=carry;
                prev1->next=dummy; 
                return l1;
        }
        return l1;
    }
};