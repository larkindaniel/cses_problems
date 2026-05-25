#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; 
const int N = 2*1e5 + 10; 

vector<int>adj[N];

struct ST{
    int v; 
    int parent;
    int dist;
};

void get_dist(int v, vector<int>&dist){
    stack<ST>stk; 
    stk.push({v,-1,0}); 
    while (!stk.empty()){
        auto [v,par, d] = stk.top(); 
        stk.pop(); 
        dist[v] = d; 
        for (int u: adj[v]){
            if (u == par) continue; 
            stk.push({u,v,d+1});
        }
    }
}

void solve(){
    int a = 0;
    vector<int>dist(N, 0);
    get_dist(a, dist);
    int b = 0; 
    int farthest = 0; 
    for (int cand = 0; cand < N; ++cand){
        if (dist[cand] > farthest){
            farthest = dist[cand]; 
            b = cand; 
        }
    }
    fill(dist.begin(), dist.end(), 0);
    get_dist(b, dist); 
    auto max_it = max_element(dist.begin(), dist.end());
    cout << *max_it << endl; 
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
        u--;
        v--; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    solve();
}