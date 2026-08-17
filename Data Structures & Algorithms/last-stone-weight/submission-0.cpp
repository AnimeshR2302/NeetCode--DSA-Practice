class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int &x: stones) pq.push(x);

        while(!pq.empty()) {
            int first = pq.top();
            pq.pop();
      
            if(pq.empty()) return first;

            int second = pq.top();
            pq.pop();

            int diff = abs(first - second);
            if(diff != 0) pq.push(diff);
        }

        return 0;
    }
};