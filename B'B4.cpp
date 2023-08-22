#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend();
#define srt(a) sort(a.begin(), a.end());
#define srtr(a) sort(a.rbegin(), a.rend());
 
constexpr int mXN = 2e5 + 5, inf = INT_MAX - 100, mod = 1e9 + 7, llmod = 1e18+7;
constexpr double eps = 1e-8; 
 
int d[100000+5][3][21];

void test_case() {
    for(int i = 0; i<=3; ++i) {
        for(int t=0; t<=20; ++t) {
            d[0][i][t] = -inf;
        }
    }
    int n, kk;
    cin >> n >> kk;
    vector<int> c(n);
    for(int i=0; i<n; ++i) {
        char x; cin >> x;
        if(x == 'M') {
            c[i] = 1;
        } else if(x == 'P') {
            c[i] = 2;
        } else {
            c[i] = 3;
        }
    }
    for(int i=1; i<=3; ++i) {
        d[0][i][kk] = (c[0] == i? 1 : 0);
    }
    for(int i=1; i<n; ++i) {
        for(int type=1; type<=3; ++type) {
            for(int k=kk; k>=0; --k) {
                d[i][type][k] = d[i-1][type][k] + (c[i] == type? 1 : 0);
                if(k < kk) {
                    for(int diff_type = 1; diff_type <= 3; diff_type++) {
                        d[i][type][k] = max(d[i-1][diff_type][k+1] + (c[i] == type? 1 : 0), d[i][type][k]);
                    }
                }
            }
        }
    }
    int global_max = -inf;
    for(int type = 1; type <= 3; ++type) {
        for(int k=0; k <= kk; ++k) {
            global_max = max(global_max, d[n-1][type][k]);
        }
    }
    cout << global_max << '\n';
}
 
signed main() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test_cases = 1;
//    cin >> test_cases;
    while(test_cases--) {
        test_case();    
    }
}