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
        if(head==NULL||head->next==NULL)return NULL;
        ListNode*temp=head;
        int count=0;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        temp=head;
        ListNode*prev=NULL;
        int pos=(count-n);
        if(n==count)
        {
            head=head->next;
            delete temp;
            return head;
        }
        temp=head;
        while(pos>0)
        {
            prev=temp;
            temp=temp->next;
            
            pos--;
            
        }
        ListNode*toremove=temp;
        prev->next=temp->next;
        temp->next=NULL;
        delete toremove;
        return head;




    }
};