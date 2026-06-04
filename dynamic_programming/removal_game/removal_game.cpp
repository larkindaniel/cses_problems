#include <bits/stdc++.h>
using namespace std;

long long INF = 1LL << 60; 

long long dp [5001][5001];
long long prefix[5001]; 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);  
    int n;
    cin >> n;
    fill(&dp[0][0], &dp[0][0] + 5001LL * 5001, -INF); 
    for (int i = 0; i < n; ++i){
        cin >> dp[i][i]; 
        prefix[i+1] = prefix[i] + dp[i][i];
    }
    auto sum = [&](int l, int r){
        return prefix[r+1]-prefix[l];
    };
    
    for (int len = 2; len <= n; ++len){
        for (int l = 0; l <= n-len; ++l){
            int r = l + len-1;
            long long tot_sum = sum(l,r);
            dp[l][r] = max(
                tot_sum - dp[l][r-1],
                tot_sum - dp[l+1][r]
            );
        }
    }
    cout << dp[0][n-1] << '\n';

}