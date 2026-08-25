class Solution {
public:
    vector<vector<int>> visit;

    bool func(int index, int i, int j,
              vector<vector<char>>& board, string& word) {

        // Successfully found all characters
        if (index == word.size()) {
            return true;
        }

        // Boundary check
        if (i < 0 || i >= board.size() ||
            j < 0 || j >= board[0].size()) {
            return false;
        }

        // Invalid cell
        if (visit[i][j] == 1 || board[i][j] != word[index]) {
            return false;
        }

        visit[i][j] = 1;

        bool found =
            func(index + 1, i + 1, j, board, word) ||
            func(index + 1, i - 1, j, board, word) ||
            func(index + 1, i, j + 1, board, word) ||
            func(index + 1, i, j - 1, board, word);

       
        visit[i][j] = 0;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        visit.resize(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (func(0, i, j, board, word)) {
                    return true;
                }
            }
        }

        return false;
    }
};