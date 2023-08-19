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
    int m, k, a, ak;
    cin >> m >> k >> a >> ak;
    if(m <= a) { // if m is zero
        cout << 0 << '\n';
    } else {
        int need = m - a;
        int now = need / k;
        if(m - k * (now) > a && m - k * (now + 1) >= 0) {
            now++;
        }
        cout << max(now - ak, 0LL) + max(m - k * now - a, 0LL) << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test_cases = 1;
    cin >> test_cases;
    while(test_cases--) {
        test_case();    
    }
}