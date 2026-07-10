class MyCircularQueue {
public:
    int* arr;
    int currSize, capacity;
    int front, rear;

    MyCircularQueue(int k) {
        capacity = k;
        arr = new int[capacity];
        currSize = 0;
        front = 0;
        rear = -1;
    }
    
    bool enQueue(int value) {
        if(currSize == capacity) return false;

        rear++;
        if(rear == capacity) rear = 0;

        arr[rear] = value;
        currSize++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;

        front++;
        if(front == capacity) front = 0;

        currSize--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;

        return arr[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;

        return arr[rear];
    }
    
    bool isEmpty() {
        return currSize == 0;
    }
    
    bool isFull() {
        return currSize == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */