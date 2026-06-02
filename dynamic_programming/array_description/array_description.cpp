#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);   
    const long long MOD = 1'000'000'007;

    int n,m; 
    cin >> n >> m; 
    vector<vector<long long>>dp(n, vector<long long>(m+1,0)); 
    vector<int>arr(n,0);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    if (arr[0] == 0){
        for (int j = 1; j <= m; ++j)
            dp[0][j] = 1; 
    } 
    dp[0][arr[0]] = 1; 

    for (int i = 1; i < n; ++i){
    
        for (int j = 1; j <= m; ++j){
            if (arr[i] != 0) j = arr[i];
            int s = max(j-1,1), e = min(j+1,m);

            for (int k = s; k <= e; ++k){
                dp[i][j] += dp[i-1][k];
                dp[i][j] %= MOD;
            }
            if (arr[i] != 0) break; 
            
        }
    }
    long long res = 0;
    for (int j = 1; j <= m; ++j) res += dp[n-1][j];
    cout << res%MOD << '\n';
}