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
    vector<int> a(n);
    map<int,int> h;
    for(int i=0; i<n; ++i) {
        cin >> a[i];
    }
    h[a[n-1]] = n;
    int cnt = 0;
    for(int i=n-2; i>=0; --i) {
        if(a[i] > a[i+1]) {
            cnt++;
        }
        h[a[i]] = n - cnt;
    }
    int cur = n-1;
    for(auto& i : h) {
        if(i.second != a[cur]) {
            cout << "NO\n";
            return;
        } else cur--;
    }
    cout << "YES\n";
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