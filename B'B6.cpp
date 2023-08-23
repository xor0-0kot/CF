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
    vector<pair<int,int>> a(n); vector<pair<int,int>> b(n);
    int suffix = 0, preffix = 0;
    int sum = 0;
    for(int i=0; i<n; ++i) {
        int x, y;
        cin >> x >> y;
        b[i] = {x - y, i};
        a[i] = {x, y};
        suffix += x;
        sum += y;
    }
    sort(all(b));
    int result = suffix;
    if (n == 1) {
        cout << sum << '\n';
        return;
    }
    for(int i=0; i<n; ++i) {
        preffix += a[b[i].second].second;      
        suffix -= a[b[i].second].first;
        int two = i + 1;
        int one = n - two;
        if((m + 1) / 2 >= two && (m - two * 2 >= one || one == 0) && one != 1) {
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