class MyStack {
    vector<int> v;
    int size = 0;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        v.push_back(x);
        size++;
    }
    
    int pop() {
        int temp = v[size - 1];
        v.pop_back();
        size--;
        return temp;
    }
    
    int top() {
        return v[size - 1];
    }
    
    bool empty() {
        return v.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */