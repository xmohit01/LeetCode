class MyHashSet {
public:
    class Node{
    public:
        int val;
        Node* next;

        Node(int k){
            val = k;
            next = NULL;
        }
    };

    Node* table[1000];
    MyHashSet() {
        for(auto& node : table) node = NULL;
    }
    
    void add(int key) {
        int idx = key % 1000;
        
        if(table[idx] == NULL) table[idx] = new Node(key);
        else{
            Node* temp = table[idx];
            while(temp->next != NULL){
                if(temp->val == key) return;
                temp = temp->next;
            }
            if(temp->val == key) return;
            temp->next = new Node(key);
        }
    }
    
    void remove(int key) {
        int idx = key % 1000;
        if(table[idx] == NULL) return;

        if(table[idx]->val == key){
            table[idx] = table[idx]->next;
            return;
        }

        Node* temp = table[idx];
        while(temp->next != NULL && temp->next->val != key) temp = temp->next;

        if(temp->next == NULL) return;
        temp->next = temp->next->next;
    }
    
    bool contains(int key) {
        int idx = key % 1000;
        Node* node = table[idx];

        while(node != NULL){
            if(node->val == key) return true;
            node = node->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */