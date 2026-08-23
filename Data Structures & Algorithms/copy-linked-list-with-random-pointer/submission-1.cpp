/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)return NULL;
        Node* curr=head;
        while(curr!=NULL){
            Node* temp=new Node(curr->val);
            Node* next=curr->next;
            curr->next=temp;
            temp->next=next;
            curr=curr->next->next;

        }
        Node* h1=head;
        while(h1!=NULL){
            if(h1->random){
                h1->next->random=h1->random->next;
            }
            h1=h1->next->next;
        }
        Node* cur=head;
       Node* copy=cur->next;
        while(cur!=NULL){
            Node* temp=cur->next;
            cur->next=temp->next;
            if(temp->next!=NULL){
                temp->next=temp->next->next;
            }
            cur=cur->next;
          
        }
        return copy;
    }
};
