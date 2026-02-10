class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> st;

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {

                if(board[i][j] == '.') continue;

                string num(1, board[i][j]);

                string r = num + "_ROW_" + to_string(i);
                string c = num + "_COL_" + to_string(j);
                string b = num + "_BOX_" + to_string(i/3) + "_" + to_string(j/3);

                if(st.find(r) != st.end() ||
                   st.find(c) != st.end() ||
                   st.find(b) != st.end())
                    return false;

                st.insert(r);
                st.insert(c);
                st.insert(b);
            }
        }

        return true;
    }
};
