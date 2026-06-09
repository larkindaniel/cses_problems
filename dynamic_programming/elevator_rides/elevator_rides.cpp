#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1 << 30; 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);  
    int n,x; 
    cin >> n >> x;
    vector<int>weights(n); 
    for (int i = 0; i < n; ++i){
        cin >> weights[i];
    }
    int limit = 1 << n; 
    vector<pair<int,int>>dp(limit, {INF,INF});

    dp[0] = {1,0}; // 1 elevator, 0 space taken 
    
    for (int mask = 0; mask < limit; ++mask){
        for (int i = 0; i < n; ++i){
            if (mask & (1 << i)) continue;
            int new_mask = mask | (1 << i);
            auto candidate = dp[mask];

            if (dp[mask].second + weights[i] <= x){
                candidate.second += weights[i];
            } else {
                candidate.first +=1;
                candidate.second = weights[i]; 
            }
            dp[new_mask] = min(candidate, dp[new_mask]);
        }
    }
    cout << dp[limit-1].first << '\n';
}