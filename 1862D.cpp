#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

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
    int n;
    cin >> n;
    int low = 0, high = 4e9;
    while(high - low > 1) {
        int mid = (low + high) / 2;
        if(mid * (mid-1) / 2 <= n) {
            low = mid;
        } else high = mid;
    }
    cout << low + (n - (low-1)*low/2) << '\n';
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