class Solution {
private:

    static inline constexpr array<int, 4> dir = {-1,0,1,0};

    bool trav(int i, int j, int pos, vector<vector<char>>& board, string &word) {
        if(i<0 || j<0|| i>=board.size() || j>=board[0].size() || board[i][j] != word[pos])
            return false;
        else if(pos == word.length() - 1) return true;
        else {
            char temp = board[i][j];
            board[i][j] = '#';

            for(int d=0;d<4;d++)
                if(trav(i+dir[d],j+dir[3-d],pos+1,board,word)) return true;
            
            board[i][j] = temp;
        }

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++) for(int j=0;j<board[0].size();j++)
            if(trav(i,j,0,board,word)) return true;

        return false;
    }
};
