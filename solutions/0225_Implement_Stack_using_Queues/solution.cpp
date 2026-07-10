class MyStack {
    // vector<int> v;
    // int size = 0;

    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        // v.push_back(x);
        // size++;

        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(x);

        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        // int temp = v[size - 1];
        // v.pop_back();
        // size--;
        // return temp;

        int ans = q1.front();
        q1.pop();
        return ans;
    }
    
    int top() {
        // return v[size - 1];

        return q1.front();
    }
    
    bool empty() {
        // return v.empty();

        return q1.empty();
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