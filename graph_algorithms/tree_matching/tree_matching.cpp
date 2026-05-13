#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; 
const int N = 2*1e5 + 10; 

int dp[N][2];
vector<int>adj[N];

void dfs(int u, int par){
    dp[u][0] = 0; 
    dp[u][1] = -INF; 
    for (auto n: adj[u]){
        if (n == par) continue; 
        dfs(n,u);
        dp[u][0] += max(dp[n][0], dp[n][1]);
        dp[u][1] = max(dp[u][1], min(dp[n][0]-dp[n][1], 0)); 
    }
    dp[u][1]+=dp[u][0];
    dp[u][1]++;
}

void solve(){
    dfs(0,-1); 
    cout << max(dp[0][0], dp[0][1]);
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; 
    cin >> N; 
    for (int i = 0; i < N-1; ++i){
        int u,v; 
        cin >> u; 
        cin >> v; 
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    solve();
}