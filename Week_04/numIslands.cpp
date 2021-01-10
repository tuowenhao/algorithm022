class Solution {
    int m = 0;
    int n = 0;
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        m = grid.size();
        if (m == 0) return cnt;
        n = grid[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    cnt++;
                    dfsMarking(i, j, grid);
                }
            }
        }
        return cnt;
    }

    void dfsMarking(int i, int j, vector<vector<char>>& grid) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != '1') return;
        grid[i][j] = '0';

        dfsMarking(i + 1, j, grid);
        dfsMarking(i - 1, j, grid);
        dfsMarking(i, j + 1, grid);
        dfsMarking(i, j - 1, grid);
    }
};
