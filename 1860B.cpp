#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), r.end();
#define srt(a) sort(a.begin(), a.end());
#define srtr(a) sort(a.rbegin(), a.rend());
 
constexpr int mXN = 2e5 + 5, inf = INT_MAX - 100, mod = 1e9 + 7;
constexpr double eps = 1e-8; 
 
void test_case() {
    int m, k, a1, ak;
    cin >> m >> k >> a1 >> ak;
    int l = 0, r = 1e9;
    int ans = inf;
    for(int i=0; i*k<=m; ++i) {
        int coins_u = max(i - ak, 0LL);
        int coins = m - i * k;
        coins = max(0LL, coins - a1);
        ans = min(ans, coins + coins_u);
    }
    cout << ans << '\n';
}
 
signed main() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test_cases = 1;
    cin >> test_cases;
    while(test_cases--) {
        test_case();    
    }
}