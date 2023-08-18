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
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> a(m);
    for(int i=0; i<m; ++i) {
        cin >> a[i];
    }
    a.insert(a.begin(), 1 - d);
    a.push_back(n + 1);
    int sum = 0;
    for(int i = 1; i<=m + 1; ++i) {
        sum += (a[i] - a[i-1] - 1) / d;
    }
    sum += a.size() - 2;
    vector<int> ans;
    int res = inf;
    for(int i=1, D = 0; i<=m; ++i) {
        int A = a[i] - a[i-1] - 1;
        int B = a[i + 1] - a[i] - 1;
        int C = a[i + 1]- a[i - 1] - 1;
        D = C / d - (A / d + B / d); 
        if(D < res) {
            res = D;
            ans.clear();
        } else if(D == res) {
            ans.push_back(D);
        }
    }
    cout << res + sum - 1 << ' ' << ans.size() + 1 << '\n';
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