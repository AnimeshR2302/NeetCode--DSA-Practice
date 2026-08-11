class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto &v: matrix) {
            if(target < v.front()) return false;
            else if(target > v.back()) continue;
            else {
                int low = 0, high = v.size() - 1;
                int i = 0;
                while(low <= high) {
                    int mid = low + (high - low) / 2;

                    if(v[mid] < target) low = mid+1;
                    else if(v[mid] > target) high = mid - 1;
                    else return true;
                }

                return false;
            }
        }

        return false;
    }
};