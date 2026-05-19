#include <bits/stdc++.h>
using namespace std;


int jump(int v, int k, vector<vector<int>>&up){
    if (k == 0) return v; 
    int m = up[0].size(); 
    for (int j = m-1; j >= 0; --j){
        if ((k&(1<<j)) == 0) continue;
        if (up[v][j] == -1) return -1; 
        v = up[v][j];
    }
    return v; 
}


void solve(int n, vector<int>&parent, vector<pair<int,int>>&queries){
    int m = bit_width((unsigned)n);
    vector<vector<int>>up(n+1, vector<int>(m,-1));
    vector<int>lvl(n+1,0);
    vector<vector<int>>adj(n+1);

    for (int v = 1; v < n+1; ++v){
        up[v][0] = parent[v];
    }

    for (int j = 1; j < m; ++j){
        for (int v = 1; v < n+1; ++v){
            if (up[v][j-1] != -1)
                up[v][j] = up[up[v][j-1]][j-1]; 
        }
    }

    for (int i = 2; i < n+1; ++i){
        adj[parent[i]].push_back(i);
    }
    stack<pair<int,int>>st; 
    st.push({1,0});

    while (!st.empty()){
        auto [u,d] = st.top();
        st.pop();
        lvl[u] = d; 
        for (int v: adj[u]) st.push({v,d+1});
    }

    
    for (auto [a,b]: queries){
        if (a == b){
            cout << a << '\n';
            continue; 
        }
        if (lvl[a] < lvl[b]){
            swap(a,b);
        }
        
        int diff = lvl[a]-lvl[b];
        
        int c = jump(a, diff, up);
        if (c == b){
            cout << b << '\n';
            continue; 
        }

        for (int j = m-1; j >= 0; --j){
            if (up[c][j] != up[b][j]){
                c = up[c][j]; 
                b = up[b][j];
            }
        }
        
        cout << parent[c] << '\n';
    }   

}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin >> n >> q;
    vector<int>parent(n+1, -1);
    vector<pair<int,int>>queries(q);
    for (int i = 2; i < n+1; ++i){
        cin >> parent[i];
    }
    for (int i = 0; i < q; ++i){
        int a,b;
        cin >> a >> b; 
        queries[i] = {a,b};
    }
    solve(n,parent,queries);
}