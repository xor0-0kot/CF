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
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) {
        cin >> a[i];
    }
    int cur_mn = inf, mn = inf;
    int bad = 0;
    for(int i=0; i<n; ++i) {
        if(a[i] < cur_mn) {
            cur_mn = a[i];
            bad++;
            continue;
        }
        if(a[i] > mn) {
            bad++;
        } else {
            mn = a[i];
        }
    }
    cout << n - bad << '\n';
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