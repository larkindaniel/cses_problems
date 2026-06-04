#include <bits/stdc++.h>
using namespace std;

long long INF = 1LL << 60; 

int arr[5001];
long long dp [5001][5001];


void dfs(int i, int j, long long tot_sum){
    if (dp[i][j] != -INF) return;
    if (i == j){
        dp[i][j] = arr[i];
        return;
    }
    if (i == j-1) {
        dp[i][j] = max(arr[i], arr[j]);
        return; 
    }

    dfs(i+1,j,tot_sum-arr[i]);
    dfs(i,j-1,tot_sum-arr[j]);
    dp[i][j] = max(
        tot_sum-dp[i+1][j],
        tot_sum-dp[i][j-1]
    );
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);  
    int n;
    cin >> n;
    fill(&dp[0][0], &dp[0][0] + 5001LL * 5001, -INF); 
    long long tot_sum = 0; 
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        tot_sum += arr[i];
    }
    dfs(0,n-1,tot_sum);
    cout << dp[0][n-1] << '\n';
}