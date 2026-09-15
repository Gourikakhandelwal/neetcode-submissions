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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr=head;
        ListNode* firstPrev=NULL;
        bool first=true;
        while(curr!=NULL){
             

            // Check whether k nodes are available
            ListNode* check = curr;
            int count = 0;

            while(check != NULL && count < k) {
                check = check->next;
                count++;
            }

            // Less than k nodes -> leave them as they are
            if(count < k) {
                if(first)
                    head = curr;
                else
                    firstPrev->next = curr;

                break;
            }
             count=0;
            ListNode* f=curr;
            ListNode* prev=NULL;
            while(curr!=NULL && count<k){
                ListNode* temp=curr->next;
                curr->next=prev;
                prev=curr;
                curr=temp;
                count++;
            }
            
            if(first){head=prev,first=false;
            }
            else{
                firstPrev->next=prev;
                
            }
            firstPrev=f;
        }
        return head;
    }
};
