class Solution {
public:
    int n;
    
    vector<vector<int>> graph;

    vector<int> tin, tout, eulerTour;

    vector<int> segTree;

    vector<int> depth;

    vector<vector<int>> ancestorTable;
    int cols;

    int time;

    void dfs(int node, int dep, int parent, string& s) {
        depth[node] = dep;
        ancestorTable[node][0] = parent;

        tin[node] = time;
        eulerTour[time] = (1 << (s[node] - 'a')); // 'a' = 001, 'b' = 010.... {Entering}
        
        time++;
        for(int& child : graph[node]) {
            if(child == parent) {
                continue;
            }

            dfs(child, dep + 1, node, s);
        }

        tout[node] = time;
        eulerTour[time] = (1 << (s[node] - 'a')); // 'a' = 001, 'b' = 010.... {Leaving}
        
        time++;
    }

    // Segment Tree: Build {for XOR}.
    void buildSegTree(int i, int l, int r, vector<int>& eulerTour) {
        if(l == r) {
            segTree[i] = eulerTour[l];
            return;
        }

        int mid = l + (r - l) / 2;

        buildSegTree(2 * i + 1, l, mid, eulerTour);
        buildSegTree(2 * i + 2, mid + 1, r, eulerTour);

        segTree[i] = segTree[2 * i + 1] ^ segTree[2 * i + 2];
    }

    // Segment Tree: Point update {for XOR}.
    void updateSegTree(int idx, int val, int i, int l, int r) {
        if(l == r) {
            segTree[i] = val;
            return;
        }

        int mid = l + (r - l) / 2;

        if(idx <= mid) updateSegTree(idx, val, 2 * i + 1, l, mid);

        else updateSegTree(idx, val, 2 * i + 2, mid + 1, r);

        segTree[i] = segTree[2 * i + 1] ^ segTree[2 * i + 2];
    }

    // Segment Tree: Search.
    int querySegTree(int st, int end, int i, int l, int r) {
        if(l > end || r < st) return 0;

        if(l >= st && r <= end) return segTree[i];

        int mid = l + (r - l) / 2;
        return querySegTree(st, end, 2 * i + 1, l, mid) ^ querySegTree(st, end, 2 * i + 2, mid + 1, r);
    }


    void buildAncestorTable() {
        for(int i = 1; i < cols; i++) {
            for(int node = 0; node < n; node++) {
                if(ancestorTable[node][i - 1] != -1) {
                    ancestorTable[node][i] = ancestorTable[ancestorTable [node] [i - 1] ] [i - 1];
                }
            }
        }
    }
    // get LCA using Binary Lifting.
    int getLCA(int u, int v) {
        if(depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];

        for(int j = 0; j < cols; j++) {
            if(diff & (1 << j)) {
                u = ancestorTable[u][j];
            }
        }

        if(u == v) return u;

        for(int j = cols - 1; j >= 0; j--) {
            if(ancestorTable[u][j] != ancestorTable[v][j]) {
                u = ancestorTable[u][j];
                v = ancestorTable[v][j];
            }
        }

        return ancestorTable[u][0];
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->n = n;

        graph.assign(n, {});
        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);
        eulerTour.assign(2 * n, 0); // will store in and out time of each node.

        for(auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);

            graph[edge[1]].push_back(edge[0]);
        }

        cols = log2(n) + 1;
        ancestorTable.assign(n, vector<int>(cols, -1));
        
        // let root = 0.
        time = 0;
        dfs(0, 0, -1, s);

        // built segment tree for quler tour array!!
        // of size 4 times of the array itself i.e. 4 * ( 2 * n) = 8 * n; 
        segTree.resize(8 * n, 0);
        buildSegTree(0, 0, 2 * n - 1, eulerTour);

        buildAncestorTable();

        vector<bool> res;
        
        for(string& querie : queries) {
            stringstream ss(querie);
        
            string type;
            ss >> type;

            if(type == "update") { // update ui c.
                int node;
                char c;
                ss >> node >> c;

                int charVal = (1 << (c - 'a'));

                s[node] = c;

                updateSegTree(tin[node], charVal, 0, 0, 2 * n - 1);
                updateSegTree(tout[node], charVal, 0, 0, 2 * n - 1);
            }
            else { // query ui vi.
                int u, v;
                ss >> u >> v;

                int lcaNode = getLCA(u, v);
                char ch = s[lcaNode];
                int charVal = (1 << (ch - 'a'));

                int mask = querySegTree(0, tin[u], 0, 0, 2 * n - 1) ^
                           querySegTree(0, tin[v], 0, 0, 2 * n - 1) ^
                           charVal;

                bool isPalindromePossible = ((mask) & (mask - 1)) == 0;

                res.push_back(isPalindromePossible);
            }
        }

        return res;
    }
};