#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; 
const int N = 2*1e5 + 10; 

vector<int>adj[N];

struct ST{
    int u;
    int par; 
    long long dist;
    bool processed; 
};
void solve(int n){
    int m = n-1; 
    long long dp[N] = {};
    int num_edges[N] = {};
    // solve for dp[0]
    stack<ST>st; 
    st.push({0,-1,0, false});
    
    while (!st.empty()){
        auto [u,par,dist,processed] = st.top();
        st.pop(); 
        if (!processed){
            st.push({u,par,dist,true});
            for (auto v: adj[u]){
                if (v == par) continue; 
                st.push({v,u,dist+1,false});
            }
        } else {
            dp[0] += dist; 
            for (auto v: adj[u]){
                if (v == par) continue; 
                num_edges[u] += (1 + num_edges[v]);
            }
        }
    }
    st.push({0,-1,0,false});
    while (!st.empty()){
        auto [u,par,_u1,_u2] = st.top();
        st.pop(); 
        if (u != 0)
            dp[u] = (dp[par] - num_edges[u]) + (m - num_edges[u] -1);
        for (int v: adj[u]){
            if (v == par) continue; 
            st.push({v,u,0,0});
        }
    }
    for (int i = 0; i < n; ++i) cout << dp[i] << " "; 

}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; 
    cin >> n; 
    for (int i = 0; i < n-1; ++i){
        int u,v; 
        cin >> u; 
        cin >> v; 
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    solve(n);
}