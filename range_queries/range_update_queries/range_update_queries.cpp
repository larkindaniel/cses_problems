#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<long long> tree;

    BIT(int n) : n(n), tree(n + 1, 0) {}

    void add(int i, long long v) {
        while (i <= n) {
            tree[i] += v;
            i += i & -i;
        }
    }

    long long sum(int i) {
        long long s = 0;
        while (i > 0) {
            s += tree[i];
            i -= i & -i;
        }
        return s;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    BIT bit(n + 1);

    long long prev = 0;
    for (int i = 1; i <= n; ++i) {
        long long x; 
        cin >> x; 
        bit.add(i, x-prev); 
        prev = x; 
    }
    while (q--){
        int type;
        cin >> type; 
        if (type == 1){
            int a,b,u; 
            cin >> a >> b >> u;
            bit.add(a, u); 
            bit.add(b+1, -u); 

        } else {
            int k; 
            cin >> k; 
            cout << bit.sum(k) << '\n';
        }
    }


}