class UnionFind {
public:
    UnionFind(int n) {
        parent = new int[n];
        count = n;
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int findRoot(int p) {
        while (p != parent[p]) {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }

    void unite(int x, int y) {
        int rootX = findRoot(x);
        int rootY = findRoot(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
            count--;
        }
    }

    int getCount() {
        return count;
    }

    bool isConnected(int x, int y) {
        int rootX = findRoot(x);
        int rootY = findRoot(y);
        return rootX == rootY;
    }
private:
    int* parent;
    int count;
};
class Solution {
public:
    int rows;
    int cols;
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0) return;
        rows = board.size(), cols = board[0].size();
        int virtualNode = rows * cols;
        UnionFind* un = new UnionFind(rows * cols + 1);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == 'O') {
                    if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                        un->unite(mapNode(i, j), virtualNode);
                    } else {
                        if (i > 0 && board[i - 1][j] == 'O') {
                            un->unite(mapNode(i, j), mapNode(i - 1, j));
                        }
                        if (i < rows - 1 && board[i + 1][j] == 'O') {
                            un->unite(mapNode(i, j), mapNode(i + 1,j));
                        }
                        if (j > 0 && board[i][j - 1] == 'O') {
                            un->unite(mapNode(i, j), mapNode(i, j - 1));
                        }
                        if (j < cols - 1 && board[i][j + 1] == 'O') {
                            un->unite(mapNode(i, j), mapNode(i, j + 1));
                        }
                    }
                }
            }
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (un->isConnected(mapNode(i, j), virtualNode)) {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
    }

    int mapNode(int i, int j) {
        return i * cols + j;
    }
};
