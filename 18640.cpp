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
    int x, y, n;
    cin >> x >> y >> n;
    if(y <= n * (n-1) / 2) {
        cout << -1 << '\n';
        return;
    }
    vector<int> answer;
    int cur = y - 1;
    int j = 0;
    answer.push_back(y);
    for(int i = 2; i<n-2; ++i) {
        answer.push_back(cur);
        cur+=i;
    }
    for(int& i : answer) {
        cout << i << ' ';
    }
    cout << x << '\n';
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