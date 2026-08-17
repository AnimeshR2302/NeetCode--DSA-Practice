class KthLargest {
private:
    int myk;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    KthLargest(int k, vector<int>& nums) {
        myk = k;
        for(auto &x: nums) add(x);
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > myk) pq.pop();

        return pq.top();
    }
};
