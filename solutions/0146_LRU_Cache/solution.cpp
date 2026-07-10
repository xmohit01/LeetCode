class LRUCache {
public:

    class Node{
        public:
            int key, val;
            Node* prev;
            Node* next;

            Node(int k, int v){
                key = k;
                val = v;
                prev = next = NULL;
            }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    unordered_map<int, Node*> m;
    int limit;

    void addNode(Node* newNode){
        Node* oldNext = head->next;
        head->next = newNode;
        newNode->next = oldNext;
        oldNext->prev = newNode;
        newNode->prev = head;
    }

    void deleteNode(Node* oldNode){
        oldNode->prev->next = oldNode->next;
        oldNode->next->prev = oldNode->prev;
    }

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) return -1;
        Node* tempNode = m[key];
        int ans = tempNode->val;
        m.erase(key);
        deleteNode(tempNode);
        addNode(tempNode);
        m[key] = tempNode;
        return ans;
    }
    
    void put(int key, int value) {

        if(m.find(key) != m.end()){
            Node* oldNode = m[key];
            deleteNode(oldNode);
            m.erase(key);
        }
        if(m.size() == limit){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */