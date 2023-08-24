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
 
constexpr int mXN = 2e5 + 5, inf = INT_MAX - 100, mod = 1e9 + 7, llmod = INT64_MAX;
constexpr double eps = 1e-8; 
 
int power_of_two[1000];

void test_case() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i<n; ++i) {
        cin >> a[i];
    }
    for(int i=0; i<n; ++i) {
        cin >> b[i];
    }
    vector<vector<bool>> answer(1001, vector<bool>(n));  
    vector<int> done(n, -1); vector<bool> blocked(n);
    bool zeroes = true;
    int cnt = n;
    for(int i=0; i<n; ++i) {
        if(a[i] != b[i]) zeroes = false;
        if(a[i] == b[i]) {blocked[i] = true; cnt--;}
    }
    if(zeroes) {
        cout << 0 << '\n';
        return;
    }

    for(int i=0; i<n; ++i) {
        for(int j=1; j <= 1000; ++j) {
            if(a[i] % j == b[i]) {
                answer[j][i] = true;
            }
        }
    }
    int res = 0;
    for(int i=1; i<=1000; ++i) {
        bool fnd = false;
        for (int j = 0; j < n; ++j) {
            if (answer[i][j] && done[j] == -1 && !blocked[j]) {
                cnt--;
                fnd = true;
                done[j] = i;
            } else if(answer[i][j] && done[j] && fnd) {
                res -= power_of_two[done[j]];
                done[j] = i;
            }
        }
        if (fnd) {
            res += power_of_two[i];
        }
        if(cnt == 0) {
            break;
        }
    }
    if(cnt != 0) cout << -1 << '\n';
    else cout << res << '\n';
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
    power_of_two[0] = 1;
    for(int i=1; i<100; ++i) {
        power_of_two[i] = (power_of_two[i-1] * 2);
    }
    while(test_cases--) {
        test_case();    
    }
}