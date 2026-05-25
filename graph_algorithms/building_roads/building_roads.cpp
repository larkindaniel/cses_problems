#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100010; 

vector<int>adj[N];
bool visited[N] = {}; 

void dfs(int s){
    stack<int>stk; 
    stk.push(s);
    while(!stk.empty()){
        int u = stk.top();
        stk.pop(); 
        if (visited[u]) continue; 
        visited[u] = true; 
        for (int v: adj[u]){
            stk.push(v);
        }    
    }
}

void solve(int n){
    int k = 0; 
    int prev = 0; 
    vector<pair<int,int>>edges; 
    for (int s = 1; s <= n; ++s){

        if (!visited[s]){
            dfs(s);
            if (k >= 1) {
                edges.push_back({s, prev});
            } 
            prev = s; 
            k++;
        }
    }
    printf("%zu\n", edges.size());
    for (auto [a,b]: edges){
        printf("%d %d\n", a,b);
    }
}


int main(){
    int n,m;
    scanf("%d %d", &n,&m);
    
    for (int i = 0; i < m; ++i){
        int a,b; 
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    } 
    solve(n);
}