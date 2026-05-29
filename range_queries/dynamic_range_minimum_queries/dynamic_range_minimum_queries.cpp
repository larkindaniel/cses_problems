#include <bits/stdc++.h>
using namespace std;

long long int INF = 1LL << 60; 

struct SEG{
    int n; 
    vector<long long>tree; 
    SEG(const vector<long long>& arr){
        n = arr.size();
        tree.assign(n*2,0);
        for (int i = 0; i < n; ++i)
            tree[i+n] = arr[i];
        for (int i = n-1; i >= 1; --i)
            tree[i] = min(tree[2*i], tree[2*i+1]);
    }
    void update(int index, long long val){
        tree[n + index] = val;
        int par = (n + index)/2; 
        while (par > 0){
            tree[par] = min(tree[2*par], tree[2*par +1]);
            par/=2; 
        }
    }
    long long query(int l, int r){
        if (l == r) return tree[n+l];
        l += n; 
        r += n; 
        long long res = INF; 

        while (l <= r){
            res = min(res, tree[l]);
            res = min(res, tree[r]);
            if (l%2 == 1) 
                l+=1;
            if (r%2 == 0)
                r-=1;
            l/=2;
            r/=2; 
        }
        return res; 
    }

};



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q; 
    vector<long long>arr(n, 0);
    for (int i = 0; i < n; ++i){
        cin >> arr[i]; 
    }
    SEG sg(arr);
    while (q--){
        int type; 
        cin >> type;
        if (type == 1){
            int k;
            long long u; 
            cin >> k >> u; 
            sg.update(k-1,u);
        }
        else {
            int a, b; 
            cin >> a >> b; 
            cout << sg.query(a-1,b-1) << '\n';
        }
    }

}