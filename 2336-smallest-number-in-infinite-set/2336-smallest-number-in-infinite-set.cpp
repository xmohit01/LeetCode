class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_set<int> s;
    int nextToPop = 1;

    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if(!pq.empty()){
            int ans = pq.top();
            pq.pop();
            s.erase(ans);
            return ans;
        }

        return nextToPop++;
    }
    
    void addBack(int num) {
        if(num >= nextToPop) return;

        if(s.count(num)) return;

        s.insert(num);
        pq.push(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */