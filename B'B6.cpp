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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int sum = 0;
    for(int i=0; i<n; ++i) {
        int x, y;
        cin >> x >> y;
        a[i] = x - y;
        sum += abs(x - y);
    }
    srtr(a);    
    int suffix = sum, preffix = 0;
    int result = suffix;
    for(int i=0; i<n; ++i) {
        preffix += abs(a[i]);
        suffix -= abs(a[i]);
        if((i + 1) + ((n - i - 1) * 2) <= m) {
            result = max(result, preffix + suffix);
        }
    }
    cout << result << '\n';
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