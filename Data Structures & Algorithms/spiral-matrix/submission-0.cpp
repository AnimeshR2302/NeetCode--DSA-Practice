class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0, left = 0;
        int bottom = matrix.size() - 1;
        int right = matrix[0].size() - 1;

        vector<int> ans;
        ans.reserve(matrix.size() * matrix[0].size());

        while (top <= bottom && left <= right) {
            for (int j = left; j <= right; j++) ans.emplace_back(matrix[top][j]);
            top++;

            for (int i = top; i <= bottom; i++) ans.emplace_back(matrix[i][right]);
            right--;

            if (top <= bottom) {
                for (int j = right; j >= left; j--) ans.emplace_back(matrix[bottom][j]);
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) ans.emplace_back(matrix[i][left]);
                left++;
            }
        }

        return ans;
    }
};