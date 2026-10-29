class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vis(n,false);
        priority_queue<int> q;
        
        q.push(0);
        while(!q.empty()) {
            int pos = q.top();
            q.pop();
            
            if(pos == n - 1) return true;
            vis[pos] = true;

            for(int i=1;i<=nums[pos];i++)
                if(pos+i < n && !vis[pos + i]) q.push(pos + i);
        }

        return false;
    }
};
