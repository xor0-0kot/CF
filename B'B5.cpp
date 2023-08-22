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
 
void test_case() {
    string s;
    cin >> s;
    bool allA = true;
    int n = (int)s.size();
    int mn = inf;
    for(int i = 1; i<n; ++i) {
        int cur_mx = -inf;
        if(s[i-1] != s[i]) {
            allA = false;
            cur_mx = max(i - 1, n - i - 1);
            mn = min(cur_mx, mn);
        }
    }
    if(allA) cout << n << '\n';
    else if(mn == inf) cout << 1 << '\n';
    else cout << mn + 1 << '\n';
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