#include <bits/stdc++.h>
using namespace std;

struct ST{
    int u;
    int parent; 
    bool processed;
};

void solve(int N, vector<vector<int>>&adj){
    int s = 0;   
    vector<vector<int>>dp(N,vector<int>(2,0)); 

    stack<ST>st; 
    st.push({s,-1,false});

    while (!st.empty()){
        auto [u,parent, processed] = st.top(); 
        st.pop(); 
        if (!processed){
            st.push({u,parent,true});
            for (auto v: adj[u]){
                if (v == parent) continue; 
                st.push({v,u,false});
            }
        } else {
            for (auto v: adj[u]){
                if (v == parent) continue;
                dp[u][0] += max(dp[v][0], dp[v][1]);
            }
            for (auto v: adj[u]){
                if (v == parent) continue;
                dp[u][1] = max(dp[u][1], 1 + dp[u][0] + dp[v][0] - max(dp[v][0], dp[v][1]));
            }
        }
    }
    cout << max(dp[s][0], dp[s][1]) << endl;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; 
    cin >> N; 
    vector<vector<int>>adj(N);
    for (int i = 0; i < N-1; ++i){
        int u,v; 
        cin >> u; 
        cin >> v; 
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    solve(N, adj);
}