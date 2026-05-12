#include <bits/stdc++.h>
using namespace std;



void solve(int N, vector<vector<int>>&adj){
    vector<int>res(N+1,0);
    
    stack<pair<int,int>>s; 
    s.push({1,0});
    while (!s.empty()){
        auto [v,state] = s.top(); 
        s.pop();
        if (state == 0){
            s.push({v,1});
            for (auto n: adj[v]) s.push({n,0});
        } else {
            for (auto n: adj[v]) res[v] +=  (1 + res[n]);
        }
    }
    for (int i = 1; i <= N; ++i) cout << res[i] << " ";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N; 
    vector<vector<int>>adj(N+1);
    for (int n = 2; n <= N; ++n){
        int parent;
        cin >> parent;
        adj[parent].push_back(n);
    }
    solve(N, adj);
}