#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; 
const int N = 2*1e5 + 10; 

vector<int>adj[N];
struct ST{
    int u; 
    int par; 
};

void find_dist(int s, vector<int>&dist){
    stack<ST>st; 
    st.push({s,-1}); 
    dist[s] = 0; 
    while (!st.empty()){
        auto [u,par] = st.top(); 
        st.pop(); 
        for (int v: adj[u]){
            if (v == par) continue; 
            dist[v] = dist[u] + 1; 
            st.push({v,u});
        }
    }
}

void solve(int N){
    // find both ends of the diameter = [a,b]
    vector<int>dist_a(N,0);
    vector<int>dist_b(N,0);
    int s = 0; 
    find_dist(s,dist_a);
    auto it1 = max_element(dist_a.begin(), dist_a.end()); 
    int a = it1-dist_a.begin();
    fill(dist_a.begin(), dist_a.end(), 0);
    find_dist(a, dist_a); 
    auto it = max_element(dist_a.begin(), dist_a.end()); 
    int b = it-dist_a.begin(); 
    find_dist(b, dist_b); 

    for (int v = 0; v < N; ++v){
        int v_a = dist_a[v]; 
        int v_b = dist_b[v]; 
        cout << max(v_a, v_b) << " "; 
    }
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
    solve(n);
}