class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size() == 1) return;

        auto hori = [](vector<vector<int>>& matrix) {
            int top = 0, bot = matrix.size()-1;
            while(top<bot) swap(matrix[top++], matrix[bot--]);
        };

        auto diag = [](vector<vector<int>>& matrix) {
            for(int i=1;i<matrix.size();i++) for(int j=0;j<i;j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        };
        hori(matrix);
        diag(matrix);
    }
};
