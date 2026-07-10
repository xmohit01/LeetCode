class MyLinkedList {
private:
    struct Node{
        int val;
        Node* next;

        Node(int x){
            val = x;
            next = NULL;
        }
    };
    Node* head;
    int size;

public:

    MyLinkedList() {
        head = nullptr;
        size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >= size) return -1;

        Node* curr = head;
        for(int i = 0; i < index; i++) curr = curr->next;

        return curr->val;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        if (head == NULL) {
            addAtHead(val);
            return;
        }

        Node* tail = head;
        while(tail->next != NULL) tail = tail->next;
        tail->next = new Node(val);
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) return;
        if(index == 0){
            addAtHead(val);
            return;
        }
        
        Node* curr = head;
        for(int i = 0; i < index - 1; i++) curr = curr->next;

        Node* newNode = new Node(val);
        newNode->next = curr->next;
        curr->next = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size) return;

        if(index == 0){
            Node* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
            size--;
            return;
        }

        Node* curr = head;
        for(int i = 0; i < index - 1; i++) curr = curr->next;
        Node* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */