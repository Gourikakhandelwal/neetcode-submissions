class LRUCache {
public:

class Node{
    public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int key,int val){
        this->key=key;
        this->val=val;
    }
};
Node* head=new Node(-1,-1);
Node* tail=new Node(-1,-1);
unordered_map<int,Node*> mp;
void addnode(Node* node){
    Node* temp=head->next;
    node->next=temp;
    head->next=node;
    temp->prev=node;
    node->prev=head;
}
void deletenode(Node* node){
    Node* back=node->prev;
    Node* front=node->next;
    back->next=front;
    front->prev=back;

}
int cap;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;

    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())return -1;
        deletenode(mp[key]);
        addnode(mp[key]);
        return mp[key]->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            mp[key]->val=value;
            deletenode(mp[key]);
            addnode(mp[key]);
            return ;

        }
        if(mp.size()==cap){
            Node* last=tail->prev;
            deletenode(last);
            mp.erase(last->key);
            delete last;
        }
        Node* node=new Node(key,value);
            addnode(node);
            mp[key]=node;
            
    }
};
