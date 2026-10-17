class LFUCache {
public:
    class Node{
        public:
            int key, val, freq;
            Node* prev;
            Node* next;

            Node(int k, int v, int f){
                key = k;
                val = v;
                freq = f;
                prev = next = NULL;
            }
    };

    Node* head = new Node(-1, -1, -1);
    Node* tail = new Node(-1, -1, -1);

    unordered_map<int, Node*> m;
    int limit;

    void addNode(Node* newNode){
        int freq = newNode->freq;

        Node* temp = head;
        while(temp->next != NULL && temp->next->freq > freq) temp = temp->next;

        Node* oldNext = temp->next;
        temp->next = newNode;
        newNode->next = oldNext;
        oldNext->prev = newNode;
        newNode->prev = temp;
    }

    void deleteNode(Node* oldNode){
        oldNode->prev->next = oldNode->next;
        oldNode->next->prev = oldNode->prev;
    }

    LFUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!m.count(key)) return -1;

        Node* tempNode = m[key];
        int ans = tempNode->val;

        m.erase(key);
        deleteNode(tempNode);

        tempNode->freq++;

        addNode(tempNode);
        m[key] = tempNode;

        return ans;
    }
    
    void put(int key, int value) {
        int freq = 1;
        
        if(m.count(key)) {
            Node* oldNode = m[key];

            freq += oldNode->freq;

            m.erase(key);
            deleteNode(oldNode);
        }

        if(m.size() == limit) {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        Node* newNode = new Node(key, value, freq);

        addNode(newNode);
        m[key] = newNode;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */