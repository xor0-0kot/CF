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
    int n, mm;
    cin >> n >> mm;
    vector<vector<char>> a(n, vector<char>(mm));
    map<int,vector<char>> m;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<mm; ++j) {
            cin >> a[i][j];
            m[j].push_back(a[i][j]);
        }
    }
    string s = "vika";
    int cur = 0;
    for(int i=0; i<mm; ++i) {
        vector<char> curr = m[i];
        for(char& j : curr) {
            if(j == s[cur]) {
                cur++;
                if(cur == 4) {
                    cout << "YES\n";
                    return;
                }
                break;
            }
        }
    }
    cout << "NO\n";
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