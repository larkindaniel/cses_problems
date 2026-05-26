#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100010;
constexpr long long INF = 1LL << 32;  
vector<pair<int,int>>adj[N];


void solve(int n){
    vector<vector<long long >>dp(n+1, vector<long long>(2, INF));
    priority_queue<
        tuple<long long, int, int>,
        vector<tuple<long long, int, int>>,
        greater<tuple<long long, int, int>>
    > pq;
    
    pq.push({0,1,0}); 
    dp[1][0] = 0; 
    dp[1][1] = 0; 
    while (!pq.empty()){
        auto [d,u,s] = pq.top(); 
        pq.pop(); 
        if (dp[u][s] < d) continue; 

        for (auto [v, w]: adj[u]){
            if (dp[v][s] > d + w){
                dp[v][s] = d + w; 
                pq.push({dp[v][s], v, s});
            }
            if (s == 0 && dp[v][1] > d + w/2){
                dp[v][1] = d + w/2; 
                pq.push({dp[v][1], v, 1});
            }
            
        }
    }
    cout << dp[n][1] << '\n';
}   


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m; 
    for (int i = 0; i < m; ++i){
        int u,v,w; 
        cin >> u >> v >> w; 
        adj[u].push_back({v,w});
    }
    
    solve(n);
}