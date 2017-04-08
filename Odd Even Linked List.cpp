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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *temp=head;
        int len=1;
        
        if(head==NULL)
            return head;
        while(temp->next!=NULL)
        {
         temp=temp->next;
         len+=1;
        }
        cout<<"len: "<<len<<"\n";
        int ct=1;
        
        ListNode *previous=head,*tobe=head;
        while(ct<=len && len!=2)
        {
            cout<<ct<<"\n";
            if(ct%2 ==0)
            {
                previous->next=head->next;
                temp->next=head;
                head->next=NULL;
                temp=temp->next;
                head=previous->next;
            }
            else
            {
                previous=head;
                head=head->next;
            }
            ct+=1;
            
        }
        return tobe;
    }
};