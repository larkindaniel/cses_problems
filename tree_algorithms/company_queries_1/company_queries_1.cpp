#include <bits/stdc++.h>
using namespace std;


int query(int v, int k, vector<vector<int>>&up){
    int p = bit_width((unsigned int)k);
    for (int i = p-1; i >= 0; --i){
        if ((k & (1 <<i)) == 0) continue;
        if (v == -1)
            return -1;
        v = up[v][i]; 
    }
    return v; 
}

void solve(int n, vector<int>&parent, vector<pair<int,int>>&queries){
    int m = bit_width((unsigned int)n);
    vector<vector<int>>up(n, vector<int>(m,-1));

    for (int v = 0; v < n; ++v) 
        up[v][0] = parent[v];

    for (int j = 1; j < m; ++j){
        for (int v = 0; v < n; ++v){
            if (up[v][j-1] != -1) 
                up[v][j] = up[up[v][j-1]][j-1];
        }
    }

    for (auto [x,k]: queries) {
        int res = query(x, k, up);
        if (res == -1) cout << res; 
        else cout << ++res; 
        cout << "\n";
    }
       
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin >> n >> q;
    vector<int>parent(n, -1); 
    vector<pair<int,int>>queries(q);
    for (int i = 1; i < n; ++i){
        int par;
        cin >> par; 
        parent[i] = --par;
    }
    for (int i = 0; i < q; ++i){
        int x,k;
        cin >> x >> k; 
        queries[i] = {--x,k};
    }
    solve(n, parent,queries);
}