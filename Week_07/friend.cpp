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
private:
    int* parent;
    int count;
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind* un = new UnionFind(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isConnected[i][j] == 1) {
                    un->unite(i, j);
                }
            }
        }
        return un->getCount();
    }
};
