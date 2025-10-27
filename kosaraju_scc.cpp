#include <bits/stdc++.h>
using namespace std;

class Kosaraju {
public:
    void dfs1(int node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st) {
        vis[node] = 1;
        for (auto neigh : adj[node])
            if (!vis[neigh])
                dfs1(neigh, adj, vis, st);
        st.push(node);
    }

    void dfs2(int node, vector<vector<int>>& rev, vector<int>& vis, vector<int>& component) {
        vis[node] = 1;
        component.push_back(node);
        for (auto neigh : rev[node])
            if (!vis[neigh])
                dfs2(neigh, rev, vis, component);
    }

    vector<vector<int>> findSCC(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V + 1);
        for (auto& e : edges)
            adj[e[0]].push_back(e[1]);

        stack<int> st;
        vector<int> vis(V + 1, 0);
        for (int i = 1; i <= V; i++)
            if (!vis[i])
                dfs1(i, adj, vis, st);

        vector<vector<int>> rev(V + 1);
        for (int i = 1; i <= V; i++)
            for (auto neigh : adj[i])
                rev[neigh].push_back(i);

        fill(vis.begin(), vis.end(), 0);
        vector<vector<int>> sccList;

        while (!st.empty()) {
            int node = st.top(); st.pop();
            if (!vis[node]) {
                vector<int> component;
                dfs2(node, rev, vis, component);
                sccList.push_back(component);
            }
        }
        return sccList;
    }
};

int main() {
    Kosaraju obj;

    int V = 8;
    vector<vector<int>> edges = {
        {1, 2},
        {2, 4},
        {4, 1},
        {4, 3},
        {1, 3},
        {3, 5},
        {5, 3},
        {4, 6},
        {6, 5},
        {6, 7},
        {7, 6},
        {7, 8},
        {8, 7},
        {8, 5}
    };

    vector<vector<int>> ans = obj.findSCC(V, edges);

    cout << "Strongly Connected Components are:\n";
    for (auto& comp : ans) {
        for (auto node : comp)
            cout << node << " ";
        cout << "\n";
    }
}